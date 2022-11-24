#include <iostream>
#include <vector>
#include <fstream>
#pragma once
#include"../Modelo/DetalledeVenta.h"
class DetalledeVentaControlador {
private:
    vector<DetalleDeVenta> vectorDetalledeVenta;
    std::string detalle = "DetalledeVentaControlador";

public:
    DetalledeVentaControlador(){
    }
    void registrarDetalledeVenta (DetalleDeVenta objetoDetalledeVenta){
        vectorDetalledeVenta.push_back(objetoDetalledeVenta);
    }
   DetalleDeVenta obtenerPosicion( int posicion ){
        return vectorDetalledeVenta[posicion];
    }

    int longitud(){
        return vectorDetalledeVenta.size();
    }

    int obtenerCorrelativo(){
        if(longitud()==0){
            return 1;
        }else{
            return vectorDetalledeVenta[longitud()-1].getCodigoVenta()+1;
        }
    }

    void mostrarDetalle(){
        cout << "Se muestra el detalle de la venta: "<< detalle << endl;
    }

    void generarDetalleenArchivo(DetalleDeVenta objetoDetalledeVenta){
        cout <<"Se esta guardando el detalle: "<<endl;

        try{
            fstream archivodeDetalle;
            archivodeDetalle.open("listadeDetalledeVenta.csv", ios::app);
            if(archivodeDetalle.is_open()){
                archivodeDetalle <<objetoDetalledeVenta.getCodigoVenta()<<";"<<objetoDetalledeVenta.getcantidadProducto()<<";"<<objetoDetalledeVenta.getcodigoProducto()<<";"<<objetoDetalledeVenta.getprecioDeVenta()<<";"<<endl;
            }
        } catch (exception e){
            cout <<"error al guardar detalles"<<endl;
        }
    }
    void cargarDatosDelArchivoAlVector() {
        cout <<"Cargando detalles de venta  del archivo..."<<endl;
        try {
            int i;
            size_t posicion;
            string linea;
            string arregloTemporal[4];
            fstream archivodeDetalle;
            archivodeDetalle.open("detalledeventa.csv", ios::in);
            if (archivodeDetalle.is_open()){
                while (!archivodeDetalle.eof() && getline(archivodeDetalle, linea)){
                    i = 0;
                    while ((posicion = linea.find(";")) != string::npos){
                        arregloTemporal[i] = linea.substr(0, posicion);
                        linea.erase(0, posicion + 1);
                        ++i;
                    }

                    DetalleDeVenta objProd(stoi(arregloTemporal[0]), arregloTemporal[1], arregloTemporal[2], arregloTemporal[3]);
                    registrarDetalledeVenta(objProd);
                }
            }
        } catch (exception e) {
            cout <<"Ocurrio un error al cargar detalle de venta  del archivo"<<endl;
        }
    }


};