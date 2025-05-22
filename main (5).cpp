#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Indica el tamaño de la matriz de cabinas";
    cin >> n;

    int cabinas[100][100] = {0}; // Todas las cabinas comienzan disponibles (0)

    int cantidadOcupadas;
    cout << "¿Cuántas cabinas deseas marcar como NO disponibles? ";
    cin >> cantidadOcupadas;

    // Ciclo para ingresar posiciones ocupadas
    for (int i = 0; i < cantidadOcupadas; ++i) {
        int fila, columna;
        cout << "Cabina" << (i + 1) << " - Ingrese fila (0 a " << (n - 1) << "): ";
        cin >> fila;
        cout << "Cabina" << (i + 1) << " - Ingrese columna (0 a " << (n - 1) << "): ";
        cin >> columna;

        // Validar que esté dentro de la matriz
        if (fila >= 0 & fila < n & columna >= 0 & columna < n) {
            cabinas[fila][columna] = 1; // Marcamos como ocupada
        } else {
            cout << "Posición inválida. Se omite.\n";
            --i; // Volvemos a intentar este número
        }
    }

    // Mostrar matriz de cabinas
    cout << "\nPlano de cabinas:\n";
    cout << "0 = disponible | 1 = NO disponible\n\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << cabinas[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}