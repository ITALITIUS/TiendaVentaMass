#pragma once
using namespace std;
#include<string>

class Vendedor {
private:
    int dniVendedor;
    int numCelularVendedor;
    string  nombresVendedor;
    string  apellidosVendedor;
public:
    Vendedor(int DNI, int numCelularVendedor, string  apellidosVendedor, string nombresVendedor) {
        this->dniVendedor = DNI;
        this-> numCelularVendedor = numCelularVendedor;
        this->apellidosVendedor = apellidosVendedor;
        this->nombresVendedor = nombresVendedor;
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