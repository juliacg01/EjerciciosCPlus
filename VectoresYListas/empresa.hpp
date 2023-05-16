#ifndef EMPRESA_H
#define EMPRESA_H
using namespace std;

class Producto{
    private:
        int id_;
        int cantidad_;
    public:
        Producto(int id = 0, int cant = 0){
            id_ = id;
            cantidad_ = cant;
        }
        ~Producto(){}
        int getid(){ return id_ ;}
        int getcantidad(){ return cantidad_; }
        void setid(int i){ id_ = i; }
        void setcantidad(int cant){ cantidad_ = cant;}
        int operator==(const Producto& right) {
            return this -> id_ == right.id_;
        }
};

class Almacen{
    private:
        list<Producto>stock;
        list<Producto>demanda;
    public:
        //Comenzamos con productos aleatorios en el almacen y en la demanda
        Almacen(){
            Producto p1(1, rand() % 1000 + 1);
            Producto p2(2, rand() % 1000 + 1);
            Producto p3(3, rand() % 1000 + 1);
            Producto p4(4, rand() % 1000 + 1);
            stock.push_back(p1);
            stock.push_back(p2);
            stock.push_back(p3);
            stock.push_back(p4);

            Producto p5(5, rand() % 1000 + 1);
            Producto p6(6, rand() % 1000 + 1);
            Producto p7(7, rand() % 1000 + 1);
            Producto p8(8, rand() % 1000 + 1);
            demanda.push_back(p5);
            demanda.push_back(p6);
            demanda.push_back(p7);
            demanda.push_back(p8);
        };
        ~Almacen(){};

        //Entra un pedido de un cliente
        void pedido_cliente(int id, int cant);
        //Llegada de mercancia
        void aprovisionamiento(int id, int cant);
        //Mostrar todo
        void mostrar();
};

#endif