#include <iostream>
#pragma once
using namespace std;

class detalleDeVenta {
private:
    int codigoVenta;
    string codigoProducto;
    string cantidadProducto;
    string precioDeVenta;

public:
    detalleDeVenta(int codigoVenta, string codigoProducto, string cantidadProducto, string precioDeVenta){
        this->codigoVenta = codigoVenta;
        this->codigoProducto = codigoProducto;
        this->cantidadProducto = cantidadProducto;
        this->precioDeVenta = precioDeVenta;
    }
    int getCodigoVenta(){
        return codigoVenta;
    }
    void setCodigoVenta (int codigoVenta) {
        this -> codigoVenta = codigoVenta;
    }
    string getcodigoProducto() {
        return codigoProducto;
    }
    void setcodigoProducto (string codigoProducto) {
        this -> codigoProducto = codigoProducto;
    }
    string getcantidadProducto() {
        return cantidadProducto;
    }
    void setcantidadProducto (string cantidadProducto) {
        this -> cantidadProducto = cantidadProducto;
    }
    string getprecioDeVenta() {
        return precioDeVenta;
    }
    void setprecioDeVenta (string precioDeVenta) {
        this-> precioDeVenta = precioDeVenta;
    }
};