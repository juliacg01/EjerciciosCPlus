#include "ejercicio.hpp"

void Menu(){
    cout<<"--------------------------------"<<endl;
    cout<<"--------------MENU--------------"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1. Mostrar todos los usuarios" <<endl;
    cout<<"2. Buscar usuario por el DNI" <<endl;
    cout<< "3. Buscar usuario por el nombre" << endl;
    cout<< "4. Insertar pasajero nuevo "<<endl;
    cout<< "0. Salir" <<endl;
}

int main(){
    Almacen al;

    int dni, opcion;
    string nombre;

    do{
        Menu();
        cout<<"Eliga una opcion: ";
        cin >> opcion;
        cout<<endl;
        cout<<endl;

        switch(opcion){
            case 1:
                al.Mostrar();
                break;
            case 2:
                cout<<"Introduce el DNI que quieres buscar"<<endl;
                cin >> dni;
                al.BuscarDNI(dni);
                break;
            case 3:
                cout << "Introduce el nombre que quieres buscar "<<endl;
                cin >> nombre;
                al.BuscarNombre(nombre);
                break;
            case 4:
                al.InsertarUsuario();
                break;
        }
    }while(opcion!=0);

    return 0;
}