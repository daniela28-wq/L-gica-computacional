#include <iostream>
#include <string>

using namespace std;

struct llamadas
{
    //atributos
    int llamada;
    int idllamada;
    string Nombre;
    string categoria;
    //métodos
    void mostrarNombre();
    void asignaridllamada();
};

void llamadas::asignaridllamada(){
    cout<<"Ingresa el número a llamar: \n";
    cin>>idllamada;
}

struct tarifa
{
    //atributos
    int idllamada_tarifa;
    string duración;
    string valor;
    //métodos
    void mostrarcategoria();
    void asignaridllamada_tarifa();
};

void tarifa::mostrarcategoria(){
    cout<<"la duración de la llamada es: \n";
    cout<<duración;
    cin>>duración;
};

void tarifa::asignaridllamada_tarifa(){
    cout<<"\nIngresa el valor de cada llamada: \n";
    cin>>valor;
}

int main()
{
    llamadas local_llamada, largadistancia_llamada, celular_llamada;
    tarifa local_tarifa, distancia_tarifa, celular_tarifa;

    celular_llamada.asignaridllamada();
    cout << celular_llamada.idllamada;
    cout << "\nIngresa la categoria de la llamada: ";
    cin >> celular_llamada.categoria;

    local_tarifa.asignaridllamada_tarifa();
    cout << local_tarifa.idllamada_tarifa;
    cout << "\nIngresa la duración de la llamada: ";
    cin >> local_tarifa.duración;

    return 0;
}