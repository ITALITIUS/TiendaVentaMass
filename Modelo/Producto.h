#pragma once
using namespace std;
#include <iostream>

class Producto{
private:
    int codigodeProducto;
    string nombredeProducto;
    int  stockdeProducto;
    long preciodeProducto;
    int codigodeCategoria;

public:
    //Producto(){}
    Producto(int codigodeProducto, string nombredeProducto, int stockdeProducto, long preciodeProducto, int codigodeCategoria){
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

    int getStockdeProducto(){
        return stockdeProducto;
    }

    void setStockdeProducto(int stockdeProducto){
        stockdeProducto = stockdeProducto;
    }

    long getPreciodeProducto(){
        return preciodeProducto;
    }

    void setPreciodeProducto(long preciodeProducto){
        preciodeProducto = preciodeProducto;
    }

    int getCodigodeCategoria(){
        return codigodeCategoria;
    }

    void setCodigodeCategoria(int codigodeCategoria){
        codigodeCategoria = codigodeCategoria;
    }


};
