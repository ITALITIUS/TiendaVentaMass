#include<vector>
#include <iostream>
using namespace std;
#include "../Modelo/Vendedor.h"
#include <fstream>


class VendedorControlador {
private:
    vector <Vendedor> vectorVendedor;
    string nombre = "VendedorControlador";
public:
    VendedorControlador() {

    }
    void regitrarVendedor(Vendedor objetoVendedor) {
        vectorVendedor.push_back(objetoVendedor);
    }
    Vendedor obtenerPosicion( int posicion ){
        return vectorVendedor[posicion];
    }

    int longitud(){
        return vectorVendedor.size();
    }
    int obtenerCorrelativo(){
        if(longitud()==0){
            return 1;
        }else{
            return vectorVendedor[longitud()-1].getCodigoVendedor()+1;
        }
    }

    void mostrarNombre() {
        cout << "Nombre del vendedor: " << nombre << endl;
    }

    void generarProductoVendedor(Vendedor objetoVendedor) {
        cout << "Se esta guardando el vendedor." << endl;
        try {
            fstream archivosVendedor;
            archivosVendedor.open("ListaVendedor.csv",ios::app);
            if (archivosVendedor.is_open()) {
                archivosVendedor << objetoVendedor.getdniVendedor()  << objetoVendedor.getnombresVendedor() << objetoVendedor.getNumCelularVendedor() << objetoVendedor.getApellidosVendedor() << ";" << endl;
            }
        }
        catch (exception e) {

        }
    }
    void cargarDatosDelArchivoAlVector() {
        cout <<"Cargando Productos del archivo..."<<endl;
        try {
            int i;
            size_t posicion;
            string linea;
            string arregloTemporal[4];
            fstream archivoVendedor;
            archivoVendedor.open("Productos.csv", ios::in);
            if (archivoVendedor.is_open()){
                while (!archivoVendedor.eof() && getline(archivoVendedor, linea)){
                    i = 0;
                    while ((posicion = linea.find(";")) != string::npos){
                        arregloTemporal[i] = linea.substr(0, posicion);
                        linea.erase(0, posicion + 1);
                        ++i;
                    }

                    Vendedor objProd(stoi(arregloTemporal[0]), stoi(arregloTemporal[1]),stoi(arregloTemporal[2]),arregloTemporal[3], arregloTemporal[4]);
                    regitrarVendedor(objProd);
                }
            }
        } catch (exception e) {
            cout <<"Ocurrio un error al cargar Productos del archivo"<<endl;
        }
    }

};