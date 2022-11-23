using namespace std;
#include <vector>
#include <iostream>
#include "../Modelo/Producto.h"
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

    void cargarDatosDelArchivoAlVector() {
        cout <<"Cargando Productos del archvio..."<<endl;
        try {
            int i;
            size_t posicion;
            string linea;
            string arregloTemporal[4];
            fstream archivoProducto;
            archivoProducto.open("Productos.csv", ios::in);
            if (archivoProducto.is_open()){
                while (!archivoProducto.eof() && getline(archivoProducto, linea)){
                    i = 0;
                    while ((posicion = linea.find(";")) != string::npos){
                        arregloTemporal[i] = linea.substr(0, posicion);
                        linea.erase(0, posicion + 1);
                        ++i;
                    }

                    Producto objProd(stoi(arregloTemporal[0]), arregloTemporal[1], stoi(arregloTemporal[2]), stoi(arregloTemporal[3]), stoi(arregloTemporal[4]));
                    registrarProducto(objProd);
                }
            }
        } catch (exception e) {
            cout <<"Ocurrio un error al cargar Productos del archivo"<<endl;
        }
    }

    void Mostrarnombre(){
        cout <<"nombre" << nombre<<endl;
    }
};