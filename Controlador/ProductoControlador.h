using namespace std;
#include <vector>
#include <iostream>
#include "Modelo/Producto.h"
#include <fstream>

class ProductoControlador{
private:
    vector<Producto> vectorProducto;
    string nombre="ProductoControlador";
public:
    ProductoControlador(){}
    void registrarProducto(Producto objetoProducto ){
        vectorProducto.push_back(objetoProducto);
    }

    Producto obtenerPosicion( int posicion ){
        return vectorProducto[posicion];
    }

    int longitud(){
        return vectorProducto.size();
    }

    int obtenerCorrelativo(){
        if(longitud()==0){
            return 1;
        }else{
            return vectorProducto[longitud()-1].getCodigodeProducto()+1;
        }
    }

    void guardarProductoenArchivo(Producto objetoProducto){
        cout <<"seestaguardandoelProducto" <<endl;

        try{
            fstream archivodelProducto;
            archivodelProducto.open("listadeProducto.csv", ios::app);
            if(archivodelProducto.is_open()){
                archivodelProducto <<objetoProducto.getCodigodeProducto()<<";"<<objetoProducto.getNombredeProducto()<<";"<<objetoProducto.getStockdeProducto()<<";"<<objetoProducto.getPreciodeProducto()<<";"<<objetoProducto.getCodigodeCategoria()<<";"<<endl;
            }

        }catch(exception e){
            cout <<"ocurrio un error al guardar producto" <<endl;
        }
    }

    void Mostrarnombre(){
        cout <<"nombre" << nombre<<endl;
    }
};