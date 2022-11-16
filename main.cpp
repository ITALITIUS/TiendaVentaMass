#include <iostream>
#include <string>
#include <conio.h>
#include "Modelo/Producto.cpp"
#include "Controlador/ProductoControlador.cpp"
using namespace std;

int main ()
{
    cout << "hola mundo";
    Producto* producto = new Producto;
    producto->Vernombre();
    ProductoControlador* productoControlador = new ProductoControlador;
    productoControlador->Mostrarnombre();

}
