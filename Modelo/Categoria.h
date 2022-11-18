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

    ~Categoria() {

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