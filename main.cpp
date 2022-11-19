#include <iostream>
#include <string>
#include "Modelo/Producto.h"
#include "Controlador/ProductoControlador.h"
#include "Modelo/Cliente.h"
#include "Modelo/Categoria.h"
#include "Modelo/Vendedor.h"
#include "Modelo/DetalledeVenta.h"
#include "Modelo/Venta.h"


using namespace std;

ProductoControlador* productoControlador= new ProductoControlador();

int main ()
{
    cout << "creando Producto";
    int codigodeProducto;
    string nombredeProducto;
    float preciodeProducto;
    string  stockdeProducto;
    int codigodeCategoria;


    codigodeProducto= productoControlador->obtenerCorrelativo();
    cin.ignore();
    getline(cin,nombredeProducto);
    cin>>preciodeProducto;
    getline(cin,stockdeProducto);
    cin>>codigodeCategoria;


    Producto objetoProducto(codigodeProducto, nombredeProducto, preciodeProducto, stockdeProducto, codigodeProducto);
    productoControlador->registrarProducto(objetoProducto);
    productoControlador->guardarProductoenArchivo(objetoProducto);









}



