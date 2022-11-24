using namespace std;
#include <iostream>

class Venta {
private:
    int codigodeVenta;
    int totaldeVenta;
    string fechadeVenta;
    string estadodeVenta;

public:
    Venta(){}
    Venta(int codigodeVenta, int totaldeVenta,  string fechadeVenta , string estadodeVenta){
        this->codigodeVenta = codigodeVenta;
        this->fechadeVenta = fechadeVenta;
        this->totaldeVenta = totaldeVenta;
        this->estadodeVenta = estadodeVenta;
    }

    void setcodigodeVenta(int codigodeVenta){
        this->codigodeVenta = codigodeVenta;
    }
    int getcodigodeVenta(){
        return codigodeVenta;
    }

    void settotaldeVenta(int totaldeVenta){
        this->totaldeVenta = totaldeVenta;
    }
    int gettotaldeVenta(){
        return totaldeVenta;
    }

    void setfechadeVenta(string fechadeVenta){
        this->fechadeVenta = fechadeVenta;
    }
    string getfechadeVenta(){
        return fechadeVenta;
    }

    void setestadodeVenta(string estadodeVenta){
        this->estadodeVenta = estadodeVenta;
    }
    string getestadodeVenta(){
        return estadodeVenta;
    }
};