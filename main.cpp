#include <iostream>
#include <string>
#include "Modelo/Producto.cpp"
#include "Controlador/ProductoControlador.cpp"
#include "Modelo/Cliente.h"
using namespace std;

int main ()
{
    cout << "hola mundo";
    Producto* producto = new Producto;
    producto->testClaseProducto();
    ProductoControlador* productoControlador = new ProductoControlador;
    productoControlador->Mostrarnombre();
    Cliente* cliente  = new Cliente;
    cliente->verCodigoCliente();

}



