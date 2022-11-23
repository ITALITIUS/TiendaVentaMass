#pragma once
#include <vector>
#include <iostream>
#include "../Modelo/Categoria.h"
#include <fstream>

class CategoriaControlador {
private:
    vector<Categoria> vectorCategoria;
    string nombre = "ProductoCategoria ";
public:
    CategoriaControlador() {}
    void registrarCategoria(Categoria objetoCategoria) {
        vectorCategoria.push_back(objetoCategoria);
    }

    Categoria objetoCategoria(int posicion) {
        return vectorCategoria[posicion];
    }

    int longitud() {
        return vectorCategoria.size();
    }

    int obtenerCorrelativo() {
        if (longitud() == 8) {
            return 1;
        }
        else {
            return vectorCategoria[longitud() - 1].getCodigoCategoria() + 1;
        }
    }
    void generarProductoCategoria(Categoria  objetoCategoria) {
        cout << "Se esta guardando categoria." << endl;
        try {
            fstream archivosCategoria;
            archivosCategoria.open("ListaCategoria .csv",  ios::app);
            if (archivosCategoria.is_open()) {
                archivosCategoria << objetoCategoria.getNombreCategoria() << objetoCategoria.getCodigoCategoria() << ";" << endl;
            }
        }
        catch (exception e) {

        }
    }

    void MostrarNombre() {
        cout << "Nombre: " << nombre << endl;
    }
};