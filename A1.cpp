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
    int tam = 1;  // Solo un cliente para prueba
    cliente listaClientes[tam];

    // Datos simulados para prueba
    listaClientes[0].nombre = "Juan";
    listaClientes[0].cantidad_llamadas = 150;  // Valor fuera del rango permitido (más de 100)

    // Validación del límite de llamadas
    if(listaClientes[0].cantidad_llamadas > 100) 
    {
        cout << "El numero maximo de llamadas es 100. Se establecera este limite.\n";
        listaClientes[0].cantidad_llamadas = 100;
    }

    for(int x = 0; x < listaClientes[0].cantidad_llamadas; x++) 
    {
        listaClientes[0].id_llamada[x] = x + 1;
    return 0;
}
}
