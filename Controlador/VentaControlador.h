using namespace std;
#include <vector>
#include <iostream>
#include "../Modelo/Ventas.h"
#include <fstream>

class VentaControlador{
private:
    vector<Ventas> vectorVenta;
    string nombre="VentaControlador";
public:
    VentaControlador(){}
    void registrarVenta(Ventas objetoVenta){
        vectorVenta.push_back(objetoVenta);
    }

    Ventas obtenerPosicion(int posicion ){
        return vectorVenta[posicion];
    }

    int longitud(){
        return vectorVenta.size();
    }

    int obtenerCorrelativo(){
        if(longitud()==0){
            return 1;
        }else{
            return vectorVenta[longitud()-1].getcodigodeVenta()+1;
        }
    }

    void guardarVentaenArchivo(Ventas objetoVenta){
        cout <<"seestaguardandolaVenta" <<endl;

        try{
            fstream archivodelaVenta;
            archivodelaVenta.open("listadelaVenta.csv", ios::app);
            if(archivodelaVenta.is_open()){
                for (Ventas venta : vectorVenta)
                {
                    archivodelaVenta << venta.getcodigodeVenta() << ";" << venta.getfechadeVenta() << ";" << venta.gettotaldeVenta() << ";" << venta.getestadodeVenta() <<endl;
                }
                archivodelaVenta.close();
            }

        }catch(exception e){
            cout <<"ocurrio un error al guardar la venta" <<endl;
        }
    }

    void cargarDatosDelArchivoAlVector() {
        try {
            int i;
            size_t posicion; //Cantida Maxima
            string linea;
            string temporal[4];
            fstream archivoVenta;
            archivoVenta.open("Ventas.txt", ios::in);
            if (archivoVenta.is_open())
            {
                while (!archivoVenta.eof())
                {
                    while (getline(archivoVenta, linea))
                    {
                        i = 0;
                        while ((posicion = linea.find(".")) != string::npos) //npos vale -1
                        {
                            temporal[i] = linea.substr(0, posicion);
                            linea.erase(0, posicion + 1);
                            i++;
                        }
                        //Crear un objeto tipo Ventas
                        Ventas venta;
                        venta.setcodigodeVenta(std::stoi(temporal[0]));
                        venta.setestadodeVenta(temporal[1]);
                        venta.setfechadeVenta(temporal[2]);
                        venta.settotaldeVenta(std::stof(temporal[3]));



                        registrarVenta(venta);
                    }
                }
            }
            archivoVenta.close();
        } catch (exception e) {
            cout << "¡Ocurrio un ERROR al momento de leer el archivo!";
        }
    }

    void Mostrarnombre(){
        cout <<"nombre" << nombre<<endl;
    }
};