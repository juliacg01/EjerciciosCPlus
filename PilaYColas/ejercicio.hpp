#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <iostream>
#include <map>
using namespace std;
typedef pair<string, int> persona;

class Almacen{
    private:
        multimap<string, int> usuarios;
    public:
        Almacen (){
            persona p1("Jose",11);
            persona p2("Laura",12);
            persona p3("Javier",13);
            persona p4("Jose",18);
            persona p5("Marta",16);
            persona p6("Laura",15);
            persona p7("Elena",17);
            persona p8("Mario",18);

            usuarios.insert(p1);
            usuarios.insert(p2);
            usuarios.insert(p3);
            usuarios.insert(p4);
            usuarios.insert(p5);
            usuarios.insert(p6);
            usuarios.insert(p7);
            usuarios.insert(p8);
        };
        ~Almacen (){}
        void Mostrar();
        void BuscarNombre(string nomobre);
        void BuscarDNI( int dni);
        void InsertarUsuario();
        void Eliminar();
};

#endif