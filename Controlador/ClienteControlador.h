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

    Cliente obtenerPosicion(int posicion) {
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
    void guardarClienteenArchivo(Cliente objetoCliente) {
        cout << "Se esta guardando el cliente." << endl;
        try {
            fstream archivosCliente;
            archivosCliente.open("ListaClientes.csv",ios::app);
            if(archivosCliente.is_open()){
                archivosCliente << objetoCliente.getCodigoCliente() << objetoCliente.getCorreoCliente() << objetoCliente.getDireccionCliente()  << objetoCliente.getNombredeCliente() << objetoCliente.getTelefonoCliente() << ";" << endl;
            }
        }
        catch (exception e) {

        }
    }
    void buscarCodigoCliente(string buscarDNI) {
        int codigoCliente;
        string nombresCliente;
        string apellidosCliente;
        string dniCliente;
        string edadCliente;
        //bool registroEncontrado = false;

        ifstream Leer;
        system("cls");
        Leer.open("Clientes.txt");
        Leer>>codigoCliente >>nombresCliente >>apellidosCliente >>dniCliente >>edadCliente;
        bool encontrado = false;
        //cout<<"Ingrese su numero de cedula para buscar"<<endl;
        //cin>>buscarDNI;
        while(!Leer.eof()) {
            Leer>>dniCliente;
            if(dniCliente==buscarDNI) {
                encontrado=true;
                cout<<"----------------------------"<<endl;
                cout<<"Codigo:    "<<codigoCliente<<endl;
                cout<<"Nombre:    "<<nombresCliente<<endl;
                cout<<"Apellido:  "<<apellidosCliente<<endl;
                cout<<"dniCliente:      "<<dniCliente<<endl;
                cout<<"edadCliente:  "<<edadCliente<<endl;
                cout<<"----------------------------"<<endl;
                cout<<endl;
            }
            Leer>>codigoCliente >>nombresCliente >>apellidosCliente >>dniCliente >>edadCliente;
        }
        if(encontrado==false) {
            cout<<"DNI no encontrado"<<endl;
        }
        Leer.close();
        //buscarPorDocumento(codigo);
    }
};
