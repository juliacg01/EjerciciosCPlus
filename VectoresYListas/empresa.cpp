#include <iostream>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include "empresa.hpp"

void Almacen::pedido_cliente(int id, int cant){
    Producto p(id, cant);
    //Se crea un interador que recorra la lista y se busca si esta el producto en el almacen 
    list<Producto>::iterator it;
    it = find(stock.begin(), stock.end(), p);

    //Si hay ese producto en el almacen
    if (it != stock.end()){
        //Si esta en el almacen, se comprueba que haya suficiente cantidad
        if(it->getcantidad() >= p.getcantidad()){
            int dif = it->getcantidad() - p.getcantidad();
            //Si hay justo la cantidad se elimina del almacen
            if (dif == 0){
                stock.erase(it);
            }
            //Si sobra producto se actualiza la cantidad que hay
            else{
                it->setcantidad(dif);
            }
        }
        //Si no hay suficiente cantidad se le da la cantidad que tengamos y guardamos en demanda la cantidad que falta por entragar
        else{
            int dif = p.getcantidad() - it->getcantidad();
            p.setcantidad(dif);
            demanda.push_back(p);

            stock.erase(it);
            }
    }
    //Si no hay producto en el almacen
    else{
        demanda.push_back(p);
    }
}

void Almacen::aprovisionamiento(int id, int cant){
    Producto p(id, cant);
    list<Producto>::iterator it;
    it = find(demanda.begin(), demanda.end(), p);

    //Comprobamos si hay algun cliente que dmanda el producto
    if(it != demanda.end()){
        //Si nos llega suficiente cantididad para el cliente, se la damos
        if(it->getcantidad() <= p.getcantidad()){
            int dif = p.getcantidad() - it->getcantidad();
            //LLega suficiente, le damos al cliente lo que queria, y guardamos el sobrante
            if(dif != 0){
                p.setcantidad(dif);
                stock.push_back(p);
            }
            demanda.erase(it);
        }
        //Si no llega suficiente cantidad, le damos todo lo que tenemos y actualizamos cuanto le seguimos debiendo
        else{
            int dif = it->getcantidad()-p.getcantidad();
            it->setcantidad(dif);
        }
    }
    //Si ningun cliente esperaba el producto se guarda en el almacen
    //Antes de almacenarlo se comprueba si ya habia stock del mismo, y si hay se guardan juntos
    else{
        list<Producto>::iterator aux;
        aux = find(stock.begin(), stock.end(), p);
        if(aux != stock.end()){
            aux->setcantidad(aux->getcantidad() + p.getcantidad());
        }
        else{
            stock.push_back(p);
        }
    }

}

void Almacen::mostrar(){   
    list<Producto>::iterator start_d = demanda.begin();
    list<Producto>::iterator stop_d = demanda.end();
    cout << endl;
    cout << endl;      
    cout << "Demanda: "<<endl;
    while (start_d != stop_d){
        cout << "[" << start_d -> getid() << ", " << start_d -> getcantidad() << "]";
        ++start_d;
    }

    cout << endl; 
    cout << "Stock: "<<endl;
    list<Producto>::iterator start_s = stock.begin();
    list<Producto>::iterator stop_s = stock.end();
    while (start_s != stop_s){
        cout << "[" << start_s -> getid() << ", " << start_s -> getcantidad() << "]";
        ++start_s;
    }
    cout << endl;  
    cout << endl;  
    cout << endl;   
};