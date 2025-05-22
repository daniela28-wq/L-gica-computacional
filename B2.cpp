#include <iostream>
using namespace std;

struct cliente {
    string nombre;
    int cantidad_llamadas;
    int id_llamada[100];
    string categoria[100];
    float duracion[100];
    float valor[100];
};

int main() {
    int tam = 2;
    cliente listaClientes[2];

    // Pedir datos de cada cliente
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el nombre del cliente #" << (i + 1) << " (sin espacios): ";
        cin >> listaClientes[i].nombre;

        cout << "Ingrese la cantidad de llamadas del cliente " << listaClientes[i].nombre << ": ";
        cin >> listaClientes[i].cantidad_llamadas;

        for (int j = 0; j < listaClientes[i].cantidad_llamadas; j++) {
            cout << "\nLlamada #" << (j + 1) << " del cliente " << listaClientes[i].nombre << endl;

            cout << "  ID de llamada: ";
            cin >> listaClientes[i].id_llamada[j];

            cout << "  Categoria (local, larga, celular): ";
            cin >> listaClientes[i].categoria[j];

            cout << "  Duracion (minutos): ";
            cin >> listaClientes[i].duracion[j];

            // Calcular valor según categoria
            if (listaClientes[i].categoria[j] == "local") {
                listaClientes[i].valor[j] = listaClientes[i].duracion[j] * 35;
            } else if (listaClientes[i].categoria[j] == "larga") {
                listaClientes[i].valor[j] = listaClientes[i].duracion[j] * 380; // tarifa usada en ejemplo original
            } else if (listaClientes[i].categoria[j] == "celular") {
                listaClientes[i].valor[j] = listaClientes[i].duracion[j] * 999;
            } else {
                listaClientes[i].valor[j] = 0;
                cout << "  Categoria desconocida, valor asignado 0.\n";
            }
        }
        cout << "\n";
    }

    // Mostrar resumen general
    int total_llamadas = 0;
    float total_duracion = 0;
    float total_valor = 0;

    cout << "Resumen general del sistema\n";
    for (int i = 0; i < tam; i++) {
        for (int x = 0; x < listaClientes[i].cantidad_llamadas; x++) {
            total_llamadas++;
            total_duracion += listaClientes[i].duracion[x];
            total_valor += listaClientes[i].valor[x];
        }
    }

    cout << "Total de llamadas registradas: " << total_llamadas << endl;
    cout << "Duracion total de llamadas: " << total_duracion << " minutos\n";
    cout << "Costo total del sistema: $" << total_valor << endl;

    return 0;
}
