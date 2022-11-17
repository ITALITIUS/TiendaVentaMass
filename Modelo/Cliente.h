#include <iostream>
using namespace std;



class Cliente {
private:
    int codigoCliente = 2;
    string nombredeCliente;
    string telefonoCliente;
    string dniCliente;
    string correoCliente;
    string direccionCliente;


public:
    Cliente(){}
    Cliente(int codigoCliente, string nombreCliente, string telefonoCliente, string correoCliente, string direccionCliente){
        this->codigoCliente = codigoCliente;
        this->nombredeCliente = nombreCliente;
        this->telefonoCliente = telefonoCliente;
        this->correoCliente = correoCliente;
        this->direccionCliente = direccionCliente;

    }

    int getCodigoCliente()  {
        return codigoCliente;
    }

    void setCodigoCliente(int codigoCliente) {
        codigoCliente = codigoCliente;
    }

    string getNombredeCliente()  {
        return nombredeCliente;
    }

    void setNombredeCliente(string nombredeCliente) {
        nombredeCliente = nombredeCliente;
    }

    string getTelefonoCliente()  {
        return telefonoCliente;
    }

    void setTelefonoCliente(string telefonoCliente) {
        telefonoCliente = telefonoCliente;
    }

    string getDniCliente() {
        return dniCliente;
    }

    void setDniCliente(string dniCliente) {
        dniCliente = dniCliente;
    }

    string getCorreoCliente() {
        return correoCliente;
    }

    void setCorreoCliente(string correoCliente) {
        correoCliente = correoCliente;
    }

    string getDireccionCliente() {
        return direccionCliente;
    }

    void setDireccionCliente(string direccionCliente) {
        direccionCliente = direccionCliente;
    }

    void verCodigoCliente(){
        cout <<"el codigo es"<< codigoCliente << endl;
    }

};



