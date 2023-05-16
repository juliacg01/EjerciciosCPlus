#include "ejercicio.hpp"

void Almacen::InsertarUsuario(){
    string nombre;
    int dni;

    cout<<"Nombre del nuevo usuario: "<<endl;
    cin>> nombre;
    cout<<"DNI del usuario: "<<endl;
    cin>> dni;

    persona nueva(nombre, dni);
    usuarios.insert(nueva);
    cout<<endl;
}

void Almacen::Mostrar(){
    map<string, int>::iterator it = usuarios.begin();
    while (it != usuarios.end()) {
        cout << "Nombre: " << it -> first << " - DNI: " << it -> second << endl; 
        ++it;
    }
    cout<<endl;
    cout<<endl;
}

void Almacen::BuscarNombre(string nombre){
    multimap<string, int>::iterator it = usuarios.begin();
    while (it != usuarios.end()) {
        if(it->first == nombre){
            cout << "Nombre: " << it -> first << " - DNI: " << it -> second << endl; 
        }
        it++;
    }
    if(it == usuarios.end()){
        cout<< "No existe ningun usuario con el nombre " << nombre <<endl;
    }
    cout<<endl;
    cout<<endl;
}

void Almacen::BuscarDNI(int dni){
    map<string, int>::iterator it = usuarios.begin();
    while (it != usuarios.end()) {
        if(it->second == dni){
            cout << "Nombre: " << it -> first << " - DNI: " << it -> second << endl; 
        }
        it++;
    } 
    if(it == usuarios.end()){
        cout<< "No existe un usuario el DNI " << dni  <<endl;
    }
    cout<<endl;
    cout<<endl;
}
