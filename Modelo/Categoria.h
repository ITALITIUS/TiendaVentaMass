#pragma once
#include<iostream>

using namespace std;


class Categoria {
private:
    int codigoCategoria;
    string nombreCategoria;

public:

    Categoria() {


    }
    Categoria(int codigoCategoria, string nombreCategoria){
        this->codigoCategoria = codigoCategoria;
        this->nombreCategoria = nombreCategoria;

    }

    void setCodigoCategoria(int codigoCategoria) {
        this->codigoCategoria = codigoCategoria;
    }
    int getCodigoCategoria() {
        return codigoCategoria;
    }
    void setNombreCategoria(string nombreCategoria) {
        this->nombreCategoria = nombreCategoria;
    }
    string getNombreCategoria() {
        return nombreCategoria;
    }
};