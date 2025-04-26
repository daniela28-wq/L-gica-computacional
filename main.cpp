#include <iostream>
using namespace std;

struct cliente
    {
         //métodos
        string nombre,categoria,duración,valor;
        int cantidad_llamadas,id_llamada,local_llamada,largadistancia_llamada,celular_llamada;
};

main()

{
   
 //atributos
int tam, i;
cout<<"¿Cuántos clientes agregaremos el día de hoy?\n";
cin>>tam;
int acumulador=0; 
cliente listaClientes[tam];

for(i=0; i<tam; i++)
{
cout<<"¿Cuál es el nombre de tu cliente?\n";
cin>>listaClientes[i].nombre;
cout<<"¿Cuántas llamadas realizo el cliente?\n";
cin>>listaClientes[i].cantidad_llamadas;
cout<<"¿Cuál fue el número que llamo?\n";
cin>>listaClientes[i].id_llamada;
cout<<"¿Cuál es la categoria?\n";
cin>>listaClientes[i].categoria;
cout<<"¿Cuál es la duración?\n";
cin>>listaClientes[i].duración;
cout<<"¿Cuál es el valor?\n";
cin>>listaClientes[i].valor;
}
}
