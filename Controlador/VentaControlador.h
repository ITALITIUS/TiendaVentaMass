using namespace std;
#include <vector>
#include <iostream>
#include "../Modelo/Venta.h"
#include <fstream>

class VentaControlador{
private:
    vector<Venta> vectorVenta;
    string nombre="VentaControlador";
public:
    VentaControlador(){}
    void registrarVenta(Venta objetoVenta){
        vectorVenta.push_back(objetoVenta);
    }

    Venta obtenerPosicion( int posicion ){
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

    void guardarVentaenArchivo(Venta objetoVenta){
        cout <<"seestaguardandolaVenta" <<endl;

        try{
            fstream archivodelaVenta;
            archivodelaVenta.open("listadelaVenta.csv", ios::app);
            if(archivodelaVenta.is_open()){
                for (Venta venta : vectorVenta)
                {
                    archivodelaVenta << venta.getcodigodeVenta() << ";" << venta.getfechadeVenta() << ";" << venta.gettotaldeVenta() << ";" << venta.getestadodeVenta() << ";" << venta.getnumerodeVenta() << ";"  << endl;
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
            archivoVenta.open("Venta.txt", ios::in);
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
                        //Crear un objeto tipo Venta
                        Venta venta;
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