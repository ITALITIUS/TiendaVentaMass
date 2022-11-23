#include<vector>
#include <iostream>
using namespace std;
#include "../Modelo/Vendedor.h"
#include <fstream>


class VendedorControlador {
private:
    vector <Vendedor> vectorVendedor;
    string nombre = "VendedorControlador";
public:
    VendedorControlador() {

    }
    void regitrarVendedor(Vendedor objetoVendedor) {
        vectorVendedor.push_back(objetoVendedor);
    }

    void mostrarNombre() {
        cout << "Nombre del vendedor: " << nombre << endl;
    }

    void generarProductoVendedor(Vendedor objetoVendedor) {
        cout << "Se esta guardando el vendedor." << endl;
        try {
            fstream archivosVendedor;
            archivosVendedor.open("ListaVendedor.csv",ios::app);
            if (archivosVendedor.is_open()) {
                archivosVendedor << objetoVendedor.getdniVendedor()  << objetoVendedor.getnombresVendedor() << objetoVendedor.getNumCelularVendedor() << objetoVendedor.getApellidosVendedor() << ";" << endl;
            }
        }
        catch (exception e) {

        }
    }


};