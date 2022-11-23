#include <iostream>
#include <vector>
#include <fstream>
#pragma once
#include"../Modelo/DetalledeVenta.h"
class DetalledeVentaControlador {
private:
    vector<detalleDeVenta> vectorDetalledeVenta;
    std::string detalle = "DetalledeVentaControlador";

public:
    DetalledeVentaControlador(){
    }
    void registrarDetalledeVenta (detalleDeVenta objetoDetalledeVenta){
        vectorDetalledeVenta.push_back(objetoDetalledeVenta);
    }

    void mostrarDetalle(){
        cout << "Se muestra el detalle de la venta: "<< detalle << endl;
    }

    void generarDetalleenArchivo(detalleDeVenta objetoDetalledeVenta){
        cout <<"Se esta guardando el detalle: "<<endl;

        try{
            fstream archivodeDetalle;
            archivodeDetalle.open("listadeDetalledeVenta.csv", ios::app);
            if(archivodeDetalle.is_open()){
                archivodeDetalle <<objetoDetalledeVenta.getCodigoVenta()<<";"<<objetoDetalledeVenta.getcantidadProducto()";"<<objetoDetalledeVenta.getcodigoProducto()";"<<objetoDetalledeVenta.getprecioDeVenta()";"<<endl;
            }
        } catch (exception e){
            cout <<"error al guardar detalles"<<endl;
        }
    }


};