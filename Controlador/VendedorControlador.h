#include<vector>
#include <iostream>
using namespace std;


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
            archivosdelVendedor.open(si"ListaVendedor.csv", mode ios::app);
            if (archivosVendedor.is.open()) {
                archivosVendedor << objetoVendedor.getCodigoVendedor() << objetoVendedor.getCorreoVendedor() << objetoVendedor.getDireccionVendedor() << objetoVendedor.getDniVendedor() << objetoVendedor.getNombredeVendedor() << objetoVendedor.getTelefonoVendedor() << ";" << endl;
            }
        }
        catch (exception e) {

        }
    }


};