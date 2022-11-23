#pragma once
#include <vector>
#include <iostream>
#include "../Modelo/Cliente.h"
#include <fstream>
class ClienteControlador {
private:
    vector<Cliente> vectorCliente;
    string nombre = "ProductoCliente";
public:
    ClienteControlador(){}
    void registrarCliente(Cliente objetoCliente){
        vectorCliente.push_back(objetoCliente);
    }

    Cliente objetoCliente(int posicion) {
        return vectorCliente[posicion];
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
    void generarProductoCliente(Cliente objetoCliente) {
        cout << "Se esta guardando el cliente." << endl;
        try {
            fstream archivosCliente;
            archivosCliente.open("ListaClientes.csv",ios::app);
            if(archivosCliente.is_open()){
                archivosCliente << objetoCliente.getCodigoCliente() << objetoCliente.getCorreoCliente() << objetoCliente.getDireccionCliente() << objetoCliente.getDniCliente() << objetoCliente.getNombredeCliente() << objetoCliente.getTelefonoCliente() << ";" << endl;
            }
        }
        catch (exception e) {

        }
    }
};
