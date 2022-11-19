#pragma once
#include <vector>
#include <iostream>
#include "Modelo/cliente.h"

class ClienteControlador {
private:
    vector<Cliente> vectorCliente;
    string nombre = "ProductoCliente";
public:
    ProductoCLiente(){}
    void registrarCliente(Cliente objetoCliente){
        vectorCliente.push_back(objetoCliente);
    }

    Cliente objetoCliente(int posicion) {
        return vectorProducto[posicion];
    }

    int longitud() {
        return vectorCliente.size();
    }

    int obtenerCorrelativo() {
        if(longitud()==8){
            return 1;
        }
        else {
            return vectorCliente[longitud() - 1].getCodigoCliente() + 1;
        }
    }
    -
    void generarProductoCliente(Cliente objetoCliente) {
        cout << "Se esta guardando el cliente." << endl;
        try {
            fstream archivosCliente;
            archivosdelCliente.open(si"ListaClientes.csv", mode ios::app);
            if(archivosCliente.is.open()){
                archivosCliente << objetoCliente.getCodigoCliente() << objetoCliente.getCorreoCliente() << objetoCliente.getDireccionCliente() << objetoCliente.getDniCliente() << objetoCliente.getNombredeCliente() << objetoCliente.getTelefonoCliente() << ";" << endl;
            }
        }
        catch (exception e) {

        }
    }

    void MostrarNombre() {
        cout << "Nombre: "<<nombre << endl;
    }
};
