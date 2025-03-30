#include <iostream>
using namespace std;

struct Linea {
    int numLlamadas;
    int totalMinutos;
    int totalCosto;
} lineas[3];//Declarar un arreglo permite almacenar y manipular datos de las tres líneas telefónicas 

int main() {
    int TARIFA_LOCAL = 35;
    int TARIFA_LARGA_DISTANCIA = 380;
    int TARIFA_CELULAR = 999;
    int opcion;

    while (true) {
        cout << "\n---------- Menu Principal ----------\n";
        cout << "1. Agregar una llamada\n";
        cout << "2. Visualizar la información de cada línea\n";
        cout << "3. Visualizar la información consolidada de todas las líneas\n";
        cout << "4. Reiniciar la información de las líneas\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int numeroLinea, tipoLlamada, minutos;
                cout << "\nIngrese el número de línea (1-3): ";
                cin >> numeroLinea;
                if (numeroLinea < 1 || numeroLinea > 3) {
                    cout << "Número de línea inválido.\n";
                    break;
                }
                cout << "\nSeleccione el tipo de llamada:\n1. Local ($" << TARIFA_LOCAL << ")\n2. Larga Distancia ($" << TARIFA_LARGA_DISTANCIA << ")\n3. Celular ($" << TARIFA_CELULAR << ")\nTipo: ";
                cin >> tipoLlamada;
                cout << "Ingrese la duración de la llamada (minutos): ";
                cin >> minutos;
                switch (tipoLlamada) {
                    case 1: lineas[numeroLinea - 1].totalCosto += minutos * TARIFA_LOCAL; break;
                    case 2: lineas[numeroLinea - 1].totalCosto += minutos * TARIFA_LARGA_DISTANCIA; break;
                    case 3: lineas[numeroLinea - 1].totalCosto += minutos * TARIFA_CELULAR; break;
                    default: cout << "Tipo de llamada inválido.\n"; break;
                }
                lineas[numeroLinea - 1].numLlamadas++;
                lineas[numeroLinea - 1].totalMinutos += minutos;
            }
            break;

            case 2:
                for (int i = 0; i < 3; i++) {
                    cout << "\nLínea " << i + 1 << ": "
                         << "Llamadas: " << lineas[i].numLlamadas
                         << ", Minutos: " << lineas[i].totalMinutos
                         << ", Costo: " << lineas[i].totalCosto << " pesos\n";
                }
            break;

            case 3: {
                int totalLlamadas = 0, totalMinutos = 0, totalCosto = 0;
                for (int i = 0; i < 3; i++) {
                    totalLlamadas += lineas[i].numLlamadas;
                    totalMinutos += lineas[i].totalMinutos;
                    totalCosto += lineas[i].totalCosto;
                }
                cout << "\nCosto total: " << totalCosto << " pesos\n"
                     << "Total de llamadas: " << totalLlamadas << "\n"
                     << "Total de minutos: " << totalMinutos << "\n"
                     << "Costo promedio por minuto: " << (totalMinutos ? totalCosto / totalMinutos : 0) << " pesos\n";//Es un operador ternario (condición ? valor_si_verdadero : valor_si_falso). Forma màs corta del if y else
            }
            break;

            case 4:
                for (int i = 0; i < 3; i++) lineas[i] = {0, 0, 0};
                cout << "\nInformación reiniciada.\n";
            break;

            case 5:
                cout << "\nSaliendo...\n";
                return 0;

            default:
                cout << "\nOpción inválida.\n";
        }
    }
}
