#pragma once
using namespace std;
#include<string>

class Vendedor {
private:
    int  codigoVendedor;
    int dniVendedor;
    int numCelularVendedor;
    string  apellidosVendedor;
    string  nombresVendedor;


public:

    Vendedor();
    Vendedor(int codigoVendedor, int dniVendedor, int numCelularVendedor, string  apellidosVendedor, string nombresVendedor) {
        this->codigoVendedor = codigoVendedor;
        this->dniVendedor = dniVendedor;
        this-> numCelularVendedor = numCelularVendedor;
        this->apellidosVendedor = apellidosVendedor;
        this->nombresVendedor = nombresVendedor;
    }

    int getCodigoVendedor() {
        return codigoVendedor;
    }

    void setCodigoVendedor(int codigoVendedor) {
        Vendedor::codigoVendedor = codigoVendedor;
    }
    void setdniVendedor(int DNI) {
        this->dniVendedor = DNI;
    }
    int getdniVendedor() {
        return dniVendedor;
    }
    void setNumCelularVendedor(int numCelularVendedor) {
        this->numCelularVendedor = numCelularVendedor;
    }
    int getNumCelularVendedor() {
        return numCelularVendedor;
    }
    void setNombresVendedor(string nombresVendedor) {
        this->nombresVendedor = nombresVendedor;
    }
    string getnombresVendedor() {
        return nombresVendedor;
    }
    void setApellidosVendedor(string apellidosVendedor) {
        this->apellidosVendedor= apellidosVendedor;
    }
    string getApellidosVendedor() {
        return apellidosVendedor;
    }
};