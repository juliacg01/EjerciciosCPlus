#include <iostream>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include "empresa.hpp"

int menu(){
    cout << "------------" << endl;
    cout << "    Menu    " << endl;
    cout << "------------" << endl;

    cout << "1: pedido cliente" << endl;
    cout << "2: aprovisionamiento" << endl;
    cout << "3: mostrar todo" << endl;
    cout << "0: Salir" << endl;

    cout << "------------" << endl;
    cout << "Elija opcion: ";

    int opcion;
    cin >> opcion;
    return opcion;
}

int main(){
    srand(time(NULL));
    Almacen al;
    int opcion;
    int id, cant;

    do{
        opcion=menu();
        switch(opcion){
            case 1:
                cout << "Introduzca la identificacion del producto que desea: ";
                cin >> id;
                cout << "Introduzca la cantidad que desea: ";
                cin >> cant;
                al.pedido_cliente(id, cant);
                break;
            case 2:
                cout << "Introduzca la identificacion del producto que trae: ";
                cin >> id;
                cout << "Introduzca la cantidad que trae: ";
                cin >> cant;
                al.aprovisionamiento(id, cant);
                break;
            case 3:
                al.mostrar();
                break;
        }
    }while(opcion!=0);
    return 0;
}