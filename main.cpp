#include <iostream>
#include <string>

//Login Inicial
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "LoginInicial.h"

#include "Modelo/Producto.h"
#include "Controlador/ProductoControlador.h"
#include "Modelo/Cliente.h"
#include "Modelo/Categoria.h"
#include "Modelo/Vendedor.h"
#include "Modelo/DetalledeVenta.h"
#include "Modelo/Venta.h"
using namespace std;

//variables de login
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3



void loginInicial();
void menuPrincipal();

void registrarProducto();
void agregarCategoria();
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

int main ()
{
    cout << "bienvenido a tiendaventamas"<<endl;

   registrarProducto();









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
        cout << "\n\n\n\t\t\t*** Ingreso al sistema***\n\n";
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
            cout << "\n\n\n\t\t *****ERROR***\n";
            cout << "\t\t El usuario o contrasenia son incorrectas. \n ";
            cout << "\t\t ********\n";
            cin.get();
            system("pause");
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false) {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else {
        cout << "\n\n\n\t\t *****Ingreso con exito *****\n";
        cout << "\t\t bienvenido al sistema usted ingreso correctamente. \n";
        cout << "\t\t ********\n";
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
        cout<<"Ingresar Nuevos Alumnos	[1]\n";
        cout<<"Eliminar Nuevos Alumnos	[2]\n";
        cout<<"Modificar Nuevos Alumnos	[3]\n";
        cout<<"Buscar Nuevos Alumnos	[4]\n";
        cout<<"Listar Alumnos			[5]\n";
        cout<<"Salir					[6]\n";
        cout<<"Ingrese una opcion[1-6]:";
        cin>>opt;
        switch(opt)
        {
            case 1:	system("cls");
                adicionarAlumnos();
                break;
            case 2:system("cls");eliminarAlumnos();break;
            case 3:system("cls");modificarAlumnos();break;
            case 4:system("cls");buscarAlumno();break;
            case 5:	system("cls");
                listarAlumnos();
                break;
            case 6:	cout<<"###########Gracias por tu compra##########\n";
                exit(0);
                break;
            default:cout<<"Ingrese una opcion correcta[1-6]"<<endl;
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

void agregarCategoria(){}
void agregarVendedor(){}
void registrarCliente(){}
void registrarVenta(){}
void registrarDetalledeVenta(){}



void listarProducto(){
    cout<<"lista de productos"<<endl;
    for(int i=0; i<productoControlador->longitud(); i++){
        cout<< productoControlador->obtenerPosicion(i).getCodigodeProducto()<<"\t"<<productoControlador->obtenerPosicion(i).getNombredeProducto()<<"\t"<<productoControlador->obtenerPosicion(i).getStockdeProducto()<<"\t"<<productoControlador->obtenerPosicion(i).getPreciodeProducto()<<"\t"<<productoControlador->obtenerPosicion(i).getCodigodeCategoria()<<"\t"<<endl;

    }
}
void listarCategoria(){}
void listarVendedor(){}
void listarCliente(){}
void listarVenta(){}
void listarDetalledeVenta(){}