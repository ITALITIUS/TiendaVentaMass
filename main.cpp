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
#include "LoginInicial.h"

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
void registrarDetalledeVenta(int codVenta);

void listarProducto();
void listarCategoria();
void listarVendedor();
void listarCliente();
void listarVenta();
void listarDetalledeVenta();
void loginInicial();


ProductoControlador* productoControlador= new ProductoControlador();
ClienteControlador* clienteControlador= new ClienteControlador();
CategoriaControlador* categoriaControlador= new CategoriaControlador();
DetalledeVentaControlador* detalledeVentaControlador= new DetalledeVentaControlador();
VendedorControlador* vendedorControlador= new VendedorControlador();
VentaControlador* ventaControlador= new VentaControlador();


int main ()
{
    cout << "bienvenido a tiendaventamas"<<endl;
    loginInicial();
   //menuPrincipal();
   //registrarProducto();
   //registrarVenta();




}

void loginInicial(){
    vector<string> usuarios;
    vector<string> claves;

    usuarios.push_back("grupo2poo");


    claves.push_back("sacamos20");


    string usuario, password, nuevo;
    int contador = 0;
    bool ingresa = false;

    do {
        system("cls");
        cout << "\n\n\n\t\t\t******* Ingreso al sistema*******\n\n";
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = _getch();
        password = "";

        while (caracter != ENTER) {

            if (caracter != BACKSPACE) {
                password.push_back(caracter);
                cout << "*";
            }
            else {
                if (password.length() > 0) {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = _getch();
        }
        cout << "\n";
        nuevo = Sustitucion::Cifrar(password);
        cout << "\n\tContrasena Encriptada: " << nuevo;

        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios[i] == usuario && claves[i] == password) {
                ingresa = true;
                break;
            }
        }

        if (!ingresa) {
            cout << "\n\n\n\t\t ************ERROR**********\n";
            cout << "\t\t El usuario o contrasenia son incorrectas. \n ";
            cout << "\t\t ********************\n";
            cin.get();
            system("pause");
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false) {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else {
        cout << "\n\n\n\t\t ************Ingreso con exito **********\n";
        cout << "\t\t bienvenido al sistema usted ingreso correctamente. \n";
        cout << "\t\t ********************\n";
        menuPrincipal();
    }

    cin.get();

    //return 0;
}

void menuPrincipal(){
    //Declarar Variables
int opt;

    do
    {
        cout<<"MENU DE OPCIONES\n";
        cout<<"Menu del administrador -------------[1]\n";
        cout<<"Menu del vendedor-------------------[2]\n";
        cout<<"Salir-------------------------------[3]\n";
        cout<<"Ingrese una opcion[1-3]:";
        cin>>opt;
        switch(opt)
        {
            case 1:system("cls");
                do
                {
                    cout<<"MENU DE OPCIONES\n";
                    cout<<"Registrar Productos-------------[1]\n";
                    cout<<"Registrar Categoria-------------[2]\n";
                    cout<<"Registrar Vendedor--------------[3]\n";
                    cout<<"Listar Producto-----------------[4]\n";
                    cout<<"Listar Ventas-------------------[5]\n";
                    cout<<"Listar Categoria----------------[6]\n";
                    cout<<"Listar Cliente------------------[7]\n";
                    cout<<"Listar Vendedor-----------------[8]\n";
                    cout<<"Salir---------------------------[9]\n";
                    cout<<"Ingrese una opcion[1-9]:";
                    cin>>opt;
                    switch(opt)
                    {
                        case 1:system("cls");registrarProducto();break;
                        case 2:system("cls");registrarCategoria();break;
                        case 3:	system("cls");agregarVendedor();break;
                        case 4:system("cls");listarProducto();break;
                        case 5:system("cls");listarVenta();break;
                        case 6:system("cls");listarCategoria();break;
                        case 7:system("cls");listarCliente();break;
                        case 8:system("cls");listarVendedor();break;
                        case 9:cout<<"###########Gracias por tu compra##########\n";break;
                        default:cout<<"Ingrese una opcion correcta[1-10]"<<endl;
                    }
                }
                while(opt!=9);

           break;
            case 2:system("cls");
                do
                {
                    cout<<"MENU DE OPCIONES\n";
                    cout<<"Registrar Ventas----------------[1]\n";
                    cout<<"Registrar cliente---------------[2]\n";
                    cout<<"Listar Ventas-------------------[3]\n";
                    cout<<"Salir---------------------------[4]\n";
                    cout<<"Ingrese una opcion[1-4]:";
                    cin>>opt;
                    switch(opt)
                    {
                        case 1:system("cls");registrarVenta();break;;
                        case 2:system("cls");registrarCliente();break;
                        case 3:system("cls");listarVenta();break;
                        case 4:cout<<"###########Gracias por tu compra##########\n";break;
                        default:cout<<"Ingrese una opcion correcta[1-4]"<<endl;
                    }
                }
                while(opt!=4);

            break;
            case 3:cout<<"###########Gracias por tu compra##########\n";break;
            default:cout<<"Ingrese una opcion correcta[1-3]"<<endl;
        }
    }
    while(opt!=3);
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
    cout<<"codigo de producto: "<<codigodeProducto<<")*****\n";
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

    productoControlador->guardarProductoenArchivo(objetoProducto);
    system("cls");
    listarProducto();

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
    string  fechadeVenta = "24/11/2022";
    string  estadodeVenta = "registrado";
    do{
        codigodeVenta=ventaControlador->obtenerCorrelativo();
        cout<<"codigo de Venta: "<<codigodeVenta<<")**\n";
        cin.ignore();
        cout<<"Total de la Ventas: ";
        cin>> totaldeVenta;
        cout<<""<<endl;
        cout<<"Fecha de la Ventas: "<<fechadeVenta<<endl;
        cin.ignore();
        cout<<"Estado de la Ventas: "<<estadodeVenta<<endl;
        cin.ignore();
        registrarDetalledeVenta(codigodeVenta);

        cout<<"Continuar(S/s):";
        cin>>opcion;

        Ventas objetoVenta(codigodeVenta, totaldeVenta, fechadeVenta, estadodeVenta );
        ventaControlador->registrarVenta(objetoVenta);

        //ventaController->guardarEnArchivo(objetoVenta);
        system("cls");


    }while(opcion=="S" ||opcion=="s");
}
void registrarDetalledeVenta(int codVenta){
    string opcion;
    int codigoVenta = codVenta;
    string codigoProducto;
    string  cantidadProducto;
    string precioDeVenta;

    //do {
    cout << "-----------------------------"<<endl;
        listarProducto();
    cout << "-----------------------------"<<endl;
        cout << "Codigo de producto: ";
        getline(cin, codigoProducto);
        cout << "" << endl;

        cout << "Cantidad a comprar:";
        cin >> cantidadProducto;

        cout << "Precio de venta: ";
        cin >> precioDeVenta;

        //cout << "Continuar(S/s):";
        //cin >> opcion;

        DetalleDeVenta objetoDetalledeVenta(codigoVenta, codigoProducto, cantidadProducto, precioDeVenta);
        detalledeVentaControlador->registrarDetalledeVenta(objetoDetalledeVenta);

        detalledeVentaControlador->generarDetalleenArchivo(objetoDetalledeVenta);
        system("cls");
        listarDetalledeVenta();


    //}
    //while(opcion=="S" ||opcion=="s");
};



void listarProducto(){
    cout<<"lista de productos"<<endl;
    cout<<"|CODIGO | NOMBRE | STOCK | PRECIO | CODCATEGORIA | "<<endl;
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
    cout<<"|CODIGO DE VENTA | CODIGO DE PRODUCTO | CANTIDAD DE PRODUCTO | PRECIO DE VENTA  : "<<endl;
    for(int i=0; i<detalledeVentaControlador->longitud(); i++){
        cout<< detalledeVentaControlador->obtenerPosicion(i).getCodigoVenta()<<"\t"<<detalledeVentaControlador->obtenerPosicion(i).getcodigoProducto()<<"\t"<<detalledeVentaControlador->obtenerPosicion(i).getcantidadProducto()<<"\t"<<detalledeVentaControlador->obtenerPosicion(i).getprecioDeVenta()<<"\t"<<endl;

    }
}