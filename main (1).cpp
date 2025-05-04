#include <iostream>
using namespace std;

struct cliente {
    string nombre;
    int cantidad_llamadas;
    int id_llamada[100];         // Límite de llamadas por cliente (100 como ejemplo)
    string categoria[100];
    string duracion[100];
    string valor[100];
    string local_llamada,largadistancia_llamada,celular_llamada;
};

int main() {
    int tam, i, x;
    
    cout << "¿Cuántos clientes agregaremos el día de hoy?\n";
    cin >> tam;

    cliente listaClientes[tam];  // Cantidad de clientes dinàmico depende de tam

    // Capturar los datos de cada cliente
    for(i = 0; i < tam; i++) {
        cout << "¿Cuál es el nombre de tu cliente?\n";
        cin >> listaClientes[i].nombre;

        cout << "¿Cuántas llamadas realizó el cliente " << listaClientes[i].nombre << "?\n";
        cin >> listaClientes[i].cantidad_llamadas;

        // Verificar que no exceda el límite máximo de llamadas (en este caso 100)
        if (listaClientes[i].cantidad_llamadas > 100) {
            cout << "El número máximo de llamadas es 100. Se establecerá este límite.\n";
            listaClientes[i].cantidad_llamadas = 100;
        }

        // Capturar los datos de las llamadas del cliente
        for(x = 0; x < listaClientes[i].cantidad_llamadas; x++) {
            cout << "¿Cuál fue el número de la llamada " << (x+1) << "?\n";
            cin >> listaClientes[i].id_llamada[x];
            
            cout << "¿Cuál es la categoría de la llamada?\n";
            cin >> listaClientes[i].categoria[x];
            
            cout << "¿Cuál fue la duración de la llamada?\n";
            cin >> listaClientes[i].duracion[x];
            
            cout << "¿Cuál es el valor de la llamada?\n";
            cin >> listaClientes[i].valor[x];
        }
    }

    // Mostrar los datos ingresados
    for(i = 0; i < tam; i++) {
        cout << "\nCliente: " << listaClientes[i].nombre << endl;
        for(x = 0; x < listaClientes[i].cantidad_llamadas; x++) {
            cout << "Llamada " << (x+1) << " - ID: " << listaClientes[i].id_llamada[x]
                 << ", Categoría: " << listaClientes[i].categoria[x]
                 << ", Duración: " << listaClientes[i].duracion[x]
                 << ", Valor: " << listaClientes[i].valor[x] << endl;
        }
    }

    return 0;
}
