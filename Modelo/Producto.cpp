using namespace std;
#include <iostream>

class Producto{
private:
    int codigoProducto;
    string nombreProducto="manzana";
    float precio;

public:
    void testClaseProducto(){
        cout <<"nombre" << nombreProducto<<endl;
    }
};