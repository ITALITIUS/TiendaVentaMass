#pragma once
using namespace std;
#include <iostream>

class Producto{
private:
    int codigodeProducto;
    string nombredeProducto;
    string stockdeProducto;
    float preciodeProducto;
    int codigodeCategoria;

public:
    //Producto(){}
    Producto(int codigodeProducto, string nombredeProducto, string stockdeProducto, float preciodeProducto, int CodigodeCategoria){
        this->codigodeProducto = codigodeProducto;
        this->nombredeProducto = nombredeProducto;
        this->stockdeProducto = stockdeProducto;
        this->preciodeProducto = preciodeProducto;
        this->codigodeCategoria = codigodeCategoria;

    }

    int getCodigodeProducto(){
        return codigodeProducto;
    }

    void setCodigodeProducto(int codigodeProducto){
       codigodeProducto = codigodeProducto;
    }

    string getNombredeProducto(){
        return nombredeProducto;
    }

    void setNombredeProducto(string nombredeProducto){
        nombredeProducto = nombredeProducto;
    }

    string getStockdeProducto(){
        return stockdeProducto;
    }

    void setStockdeProducto(string stockdeProducto){
        stockdeProducto = stockdeProducto;
    }

    float getPreciodeProducto(){
        return preciodeProducto;
    }

    void setPreciodeProducto(float preciodeProducto){
        preciodeProducto = preciodeProducto;
    }

    int getCodigodeCategoria(){
        return codigodeCategoria;
    }

    void setCodigodeCategoria(int codigodeCategoria){
        codigodeCategoria = codigodeCategoria;
    }


};
