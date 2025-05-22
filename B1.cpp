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
    cliente listaClientes[1];

    // Pedir datos del cliente
    cout << "Ingrese el nombre del cliente (sin espacios): ";
    cin >> listaClientes[0].nombre;

    cout << "Ingrese la cantidad de llamadas: ";
    cin >> listaClientes[0].cantidad_llamadas;

    // Pedir datos de cada llamada
    for (int i = 0; i < listaClientes[0].cantidad_llamadas; i++) {
        cout << "\nLlamada #" << (i + 1) << endl;

        cout << "  ID de llamada: ";
        cin >> listaClientes[0].id_llamada[i];

        cout << "  Categoria (local, larga, celular): ";
        cin >> listaClientes[0].categoria[i];

        cout << "  Duracion (minutos): ";
        cin >> listaClientes[0].duracion[i];

        // Calcular valor según categoria
        if (listaClientes[0].categoria[i] == "local") {
            listaClientes[0].valor[i] = listaClientes[0].duracion[i] * 35;
        } else if (listaClientes[0].categoria[i] == "larga") {
            listaClientes[0].valor[i] = listaClientes[0].duracion[i] * 100; // Puedes ajustar la tarifa
        } else if (listaClientes[0].categoria[i] == "celular") {
            listaClientes[0].valor[i] = listaClientes[0].duracion[i] * 999;
        } else {
            listaClientes[0].valor[i] = 0;
            cout << "  Categoria desconocida, valor asignado 0.\n";
        }
    }

    // Mostrar detalle del cliente
    cout << "\nInformacion del cliente: " << listaClientes[0].nombre << "\n";

    int llamadas_local = 0, llamadas_larga = 0, llamadas_celular = 0;
    float total_local = 0, total_larga = 0, total_celular = 0;
    float tiempo_local = 0, tiempo_larga = 0, tiempo_celular = 0;

    for (int x = 0; x < listaClientes[0].cantidad_llamadas; x++) {
        if (listaClientes[0].categoria[x] == "local") {
            llamadas_local++;
            tiempo_local += listaClientes[0].duracion[x];
            total_local += listaClientes[0].valor[x];
        } else if (listaClientes[0].categoria[x] == "larga") {
            llamadas_larga++;
            tiempo_larga += listaClientes[0].duracion[x];
            total_larga += listaClientes[0].valor[x];
        } else if (listaClientes[0].categoria[x] == "celular") {
            llamadas_celular++;
            tiempo_celular += listaClientes[0].duracion[x];
            total_celular += listaClientes[0].valor[x];
        }
    }

    cout << "\nDetalle por categoria\n";
    cout << "Locales: " << llamadas_local << " llamadas, " << tiempo_local << " minutos, $" << total_local << endl;
    cout << "Larga distancia: " << llamadas_larga << " llamadas, " << tiempo_larga << " minutos, $" << total_larga << endl;
    cout << "Celulares: " << llamadas_celular << " llamadas, " << tiempo_celular << " minutos, $" << total_celular << endl;

    return 0;
}
