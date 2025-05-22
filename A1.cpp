#include <iostream>
using namespace std;

struct cliente 
{
    string nombre;
    int cantidad_llamadas;
    int id_llamada[100];
    string categoria[100];
    float duracion[100];
    float valor[100];
};

int main() 
{
    cliente x;
    cout<<"Ingrese el nombre del cliente";
   cin>>x.nombre;
    
    // Valor fuera del rango
    x.cantidad_llamadas;
    cout<<"Ingrese cantidad de llamadas";
    cin>>x.cantidad_llamadas;

    cout << "Cliente: " << x.nombre << endl;
    cout << "Cantidad de llamadas ingresadas: " << x.cantidad_llamadas << endl;

    if (x.cantidad_llamadas > 100) 
    {
        cout << "El numero maximo de llamadas es 100. Se establecera este limite." << endl;
        x.cantidad_llamadas = 100;
    }

    return 0;
}
