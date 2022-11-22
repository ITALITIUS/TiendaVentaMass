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
void registrarProducto();
ProductoControlador* productoControlador= new ProductoControlador();

int main ()
{
    cout << "bienvenido a tiendaventamas"<<endl;

   registrarProducto();









}

void registrarProducto(){
    string opcion;
    int codigodeProducto;
    string nombredeProducto;
    int  stockdeProducto;
    float preciodeProducto;
    int codigodeCategoria;
do{
    codigodeProducto=productoControlador->obtenerCorrelativo();
    cout<<"***("<<codigodeProducto<<")*****\n";
    cin.ignore();
    cout<<"Nombre de Producto: ";
    getline(cin, nombredeProducto);
    cout<<""<<endl;
    cout<<"Precio: ";
    cin>>preciodeProducto;
    cout<<"Stock: ";
    cin>>stockdeProducto;

    cout<<"Codigo de Categoria: ";
    //listarItemCategorias();
    cin>>codigodeCategoria;

    cout<<"Continuar(S/s):";
    cin>>opcion;

    Producto objetoProducto(codigodeProducto, nombredeProducto,  preciodeProducto, stockdeProducto, codigodeCategoria);
    productoControlador->registrarProducto(objetoProducto);

    //productoController->guardarEnArchivo(objetoProducto);
    system("cls");
    //listarItemProductos();

}while(opcion=="S" ||opcion=="s");
}

