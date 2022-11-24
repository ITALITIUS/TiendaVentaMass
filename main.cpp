#include "iostream"
#include <string>

//Login Inicial
#include <cstdlib>
#include <conio.h>
#include <vector>

#include "Modelo/Producto.h"
#include "Controlador/ProductoControlador.h"
#include "Modelo/Cliente.h"
#include "Modelo/Categoria.h"
#include "Modelo/Vendedor.h"
#include "Modelo/DetalledeVenta.h"
#include "Modelo/Ventas.h"
#include "Controlador/VendedorControlador.h"
#include "Controlador/DetalledeVentaControlador.h"
#include "Controlador/VentaControlador.h"
#include "Controlador/ClienteControlador.h"
#include "Controlador/CategoriaControlador.h"

using namespace std;

//variables de login
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3



void loginInicial();
void menuPrincipal();

void registrarProducto();
void registrarCategoria();
void agregarVendedor();
void registrarCliente();
void registrarVenta();
void registrarDetalledeVenta();

void listarProducto();
void listarCategoria();
void listarVendedor();
void listarCliente();
void listarVenta();
void listarDetalledeVenta();



ProductoControlador* productoControlador= new ProductoControlador();
ClienteControlador* clienteControlador= new ClienteControlador();
CategoriaControlador* categoriaControlador= new CategoriaControlador();
DetalledeVentaControlador* detalledeVentaControlador= new DetalledeVentaControlador();
VendedorControlador* vendedorControlador= new VendedorControlador();
VentaControlador* ventaControlador= new VentaControlador();


int main ()
{
    cout << "bienvenido a tiendaventamas"<<endl;
   menuPrincipal();



}



void menuPrincipal(){
    //Declarar Variables
    int opt;
    do
    {
        cout<<"MENU DE OPCIONES\n";
        cout<<" Registrar Productos [1]\n";
        cout<<"Registrar Ventas	    [2]\n";
        cout<<"Registrar Categoria	[3]\n";
        cout<<"Registrar cliente	[4]\n";
        cout<<"Registrar Vendedor	[5]\n";
        cout<<" Listar Producto	    [6]\n";
        cout<<"Listar Ventas	    [7]\n";
        cout<<"Listar Categoria	    [8]\n";
        cout<<"Listar Cliente	    [9]\n";
        cout<<"Listar Vendedor	    [10]\n";





        cout<<"Salir					[11]\n";
        cout<<"Ingrese una opcion[1-11]:";
        cin>>opt;
        switch(opt)
        {
            case 1:system("cls");registrarProducto();break;
            case 2:system("cls");registrarVenta();break;
            case 3:system("cls");registrarCategoria();break;
            case 4:system("cls");registrarCliente();break;
            case 5:	system("cls");agregarVendedor();break;
            case 6:system("cls");listarProducto();break;
            case 7:system("cls");listarVenta();break;
            case 8:system("cls");listarCategoria();break;
            case 9:system("cls");listarCliente();break;
            case 10:	system("cls");listarVendedor();break;
            case 11:	cout<<"###########Gracias por tu compra##########\n";
                exit(0);
                break;
            default:cout<<"Ingrese una opcion correcta[1-10]"<<endl;
        }
    }
    while(opt!=6);
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

void registrarCategoria(){
    string opcion;
    int codigoCategoria;
    string nombreCategoria;
    do{
        codigoCategoria=categoriaControlador->obtenerCorrelativo();
        cout<<"*("<<codigoCategoria<<")***\n";
        cin.ignore();
        cout<<"Nombre de Categoria: ";
        getline(cin, nombreCategoria);
        cout<<""<<endl;
        cout<<"Codigo de Categoria: ";
        //listarItemCategorias();
        cin>>codigoCategoria;

        cout<<"Continuar(S/s):";
        cin>>opcion;

        Categoria objetoCategoria(codigoCategoria, nombreCategoria);
        categoriaControlador->registrarCategoria(objetoCategoria);

        categoriaControlador->generarProductoCategoria(objetoCategoria);
        system("cls");
        //listarItemProductos();

    }while(opcion=="S" ||opcion=="s");
}
void agregarVendedor(){
    string opcion;
    int codigoVendedor;
    int dniVendedor;
    int  numCelularVendedor;
    string nombresVendedor;
    string apellidosVendedor;
    do{
        codigoVendedor=vendedorControlador->obtenerCorrelativo();
        cout<<"("<<codigoVendedor<<")**\n";

        cout<<"(<<dniVendedor<<)**\n";
        cin>>dniVendedor;
        cout<<"Numero celular del Vendedor: ";
        cin>> numCelularVendedor;
        cout<<""<<endl;
        cout<<"Nombres del Vendedor: ";
        cin>>nombresVendedor;
        cout<<"Apellidos del Vendedor: ";
        cin>>apellidosVendedor;



        cout<<"Continuar(S/s):";
        cin>>opcion;

        Vendedor objetoVendedor(codigoVendedor, dniVendedor, numCelularVendedor,  apellidosVendedor, nombresVendedor);
        vendedorControlador->regitrarVendedor(objetoVendedor);


        system("cls");


    }while(opcion=="S" ||opcion=="s");
}
void registrarCliente(){
    string opcion;
    int codigoCliente;
    string nombredeCliente;
    string telefonoCliente;
    string correoCliente;
    string direccionCliente;
    do{
        codigoCliente= clienteControlador->obtenerCorrelativo();
        cout<<"("<<codigoCliente<<")**\n";
        cin.ignore();

        cout<<"Nombre de cliente: ";
        getline(cin, nombredeCliente);
        cout<<""<<endl;
        cout<<"Telefono del cliente:";
        cin>>telefonoCliente;

        cout<<"Correo del cliente: ";
        cin>>correoCliente;

        cout<<"Direccion de cliente: ";
        cin>>direccionCliente;

        cout<<"Continuar(S/s):";
        cin>>opcion;

        Cliente objetoCliente (codigoCliente,nombredeCliente,telefonoCliente,correoCliente, direccionCliente);
        clienteControlador->registrarCliente(objetoCliente);

        clienteControlador->guardarClienteenArchivo(objetoCliente);
        system("cls");
        //listarItemProductos();

    }while(opcion=="S" ||opcion=="s");
}
void registrarVenta(){
    string opcion;
    int codigodeVenta;
    int  totaldeVenta;
    string fechadeVenta;
    string estadodeVenta;
    do{
        codigodeVenta=ventaControlador->obtenerCorrelativo();
        cout<<"("<<codigodeVenta<<")**\n";
        cin.ignore();
        cout<<"Total de la Ventas: ";
        cin>> totaldeVenta;
        cout<<""<<endl;
        cout<<"Fecha de la Ventas: ";
        cin>>fechadeVenta;
        cout<<"Estado de la Ventas: ";
        cin>>estadodeVenta;



        cout<<"Continuar(S/s):";
        cin>>opcion;

        Ventas objetoVenta(codigodeVenta, totaldeVenta, fechadeVenta, estadodeVenta );
        ventaControlador->registrarVenta(objetoVenta);

        //ventaController->guardarEnArchivo(objetoVenta);
        system("cls");


    }while(opcion=="S" ||opcion=="s");
}
void registrarDetalledeVenta(){
    string opcion;
    int codigoVenta;
    string codigoProducto;
    string  cantidadProducto;
    string precioDeVenta;

    do {
        codigoVenta =detalledeVentaControlador->obtenerCorrelativo();
        cout << "*(" << codigoVenta << ")***\n";
        cin.ignore();
        cout << "Codigo de producto: ";
        getline(cin, codigoProducto);
        cout << "" << endl;

        cout << "Cantidad a comprar:";
        cin >> cantidadProducto;

        cout << "Precio de venta: ";
        cin >> precioDeVenta;

        cout << "Continuar(S/s):";
        cin >> opcion;

        DetalleDeVenta objetoDetalledeVenta(codigoVenta, codigoProducto, cantidadProducto, precioDeVenta);
        detalledeVentaControlador->registrarDetalledeVenta(objetoDetalledeVenta);

        //DetalledeVentaController->guardarEnArchivo(objetoDetalle);
        system("cls");
        //listarItemDetalledeVenta();


    }
    while(opcion=="S" ||opcion=="s");
};



void listarProducto(){
    cout<<"lista de productos"<<endl;
    for(int i=0; i<productoControlador->longitud(); i++){
        cout<< productoControlador->obtenerPosicion(i).getCodigodeProducto()<<"\t"<<productoControlador->obtenerPosicion(i).getNombredeProducto()<<"\t"<<productoControlador->obtenerPosicion(i).getStockdeProducto()<<"\t"<<productoControlador->obtenerPosicion(i).getPreciodeProducto()<<"\t"<<productoControlador->obtenerPosicion(i).getCodigodeCategoria()<<"\t"<<endl;

    }
}
void listarCategoria() {
    cout << "Lista de categoria." << endl;
    for (int i = 0; i <categoriaControlador->longitud(); i++) {
        cout << categoriaControlador->obtenerPosicion(i).getCodigoCategoria() << "\t" << categoriaControlador->obtenerPosicion(i).getNombreCategoria() << "\t" << endl;
    }
}
void listarVendedor() {
    cout << "Lista vendedor." << endl;
    for (int i = 0; i < vendedorControlador->longitud(); i++) {
        cout << vendedorControlador->obtenerPosicion(i).getdniVendedor() << "\t" << vendedorControlador->obtenerPosicion(i).getNumCelularVendedor() << "\t" << vendedorControlador->obtenerPosicion(i).getnombresVendedor() << "\t" << vendedorControlador->obtenerPosicion(i).getApellidosVendedor() << "\t" << endl;
    }
}
void listarCliente() {
    cout << "Lista de clientes." << endl;
    for (int i = 0; i < clienteControlador->longitud(); i++) {
        cout << clienteControlador->obtenerPosicion(i).getCodigoCliente() << "\t" << clienteControlador->obtenerPosicion(i).getNombredeCliente() << "\t" << clienteControlador->obtenerPosicion(i).getTelefonoCliente() << "\t" << clienteControlador->obtenerPosicion(i).getCorreoCliente() << "\t" << clienteControlador->obtenerPosicion(i).getDireccionCliente() << "\t" << endl;
    }
}
void listarVenta() {
    cout << "Lista de venta." << endl;
    for (int i = 0; i < ventaControlador->longitud(); i++) {
        cout << ventaControlador->obtenerPosicion(i).getcodigodeVenta() << "\t" << ventaControlador->obtenerPosicion(i).gettotaldeVenta() << "\t" << ventaControlador->obtenerPosicion(i).getfechadeVenta() << "\t" << ventaControlador->obtenerPosicion(i).getestadodeVenta() << "\t" << endl;
    }
}
void listarDetalledeVenta(){
    cout<<"lista de detalles: "<<endl;
    for(int i=0; i<detalledeVentaControlador->longitud(); i++){
        cout<< detalledeVentaControlador->obtenerPosicion(i).getCodigoVenta()<<"\t"<<detalledeVentaControlador->obtenerPosicion(i).getcodigoProducto()<<"\t"<<detalledeVentaControlador->obtenerPosicion(i).getcantidadProducto()<<"\t"<<detalledeVentaControlador->obtenerPosicion(i).getprecioDeVenta()<<"\t"<<endl;

    }
}