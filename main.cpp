#include <iostream>
#include <string>
#include "Modelo/Producto.h"
#include "Controlador/ProductoControlador.cpp"
#include "Modelo/Cliente.h"
#include "Modelo/Categoria.h"
#include "Modelo/Vendedor.h"
#include "Modelo/DetalledeVenta.h"
#include "Modelo/Venta.h"


using namespace std;

int main ()
{
    cout << "hola mundo";
    Producto* producto = new Producto;
    ProductoControlador* productoControlador = new ProductoControlador;
    productoControlador->Mostrarnombre();
    Cliente* cliente  = new Cliente;
    cliente->verCodigoCliente();



}



