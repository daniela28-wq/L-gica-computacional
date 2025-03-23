#include <iostream>
#include <iomanip>
using namespace std;

struct Linea {
    int numLlamadas;
    int totalMinutos;
    double totalCosto;
};

int main() {
    const int TARIFA_LOCAL = 35;
    const int TARIFA_LARGA_DISTANCIA = 380;
    const int TARIFA_CELULAR = 999;

    Linea lineas[3];

    for (int i = 0; i < 3; i++) {
        lineas[i].numLlamadas = 0;
        lineas[i].totalMinutos = 0;
        lineas[i].totalCosto = 0;
    }

    int opcion;

    do {
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
            
                int numeroLinea;
                cout << "\nIngrese el número de línea (1-3): ";
                cin >> numeroLinea;
                if (numeroLinea < 1 || numeroLinea > 3) {
                    cout << "Número de línea inválido.\n";
                    break;
                }
                
                int tipoLlamada;
                cout << "\nSeleccione el tipo de llamada:\n";
                cout << "1. Llamada Local ($" << TARIFA_LOCAL << " por minuto)\n";
                cout << "2. Llamada Larga Distancia ($" << TARIFA_LARGA_DISTANCIA << " por minuto)\n";
                cout << "3. Llamada a Celular ($" << TARIFA_CELULAR << " por minuto)\n";
                cout << "Tipo de llamada: ";
                cin >> tipoLlamada;
                
                int minutos;
                cout << "Ingrese la duración de la llamada (en minutos): ";
                cin >> minutos;
                
                double costo = 0;
                switch (tipoLlamada) {
                    case 1:
                        costo = minutos * TARIFA_LOCAL;
                        break;
                    case 2:
                        costo = minutos * TARIFA_LARGA_DISTANCIA;
                        break;
                    case 3:
                        costo = minutos * TARIFA_CELULAR;
                        break;
                    default:
                        cout << "Tipo de llamada inválido.\n";
                    
                }
                
                // Actualizamos la información de la línea seleccionada (adjustamos el índice)
                lineas[numeroLinea - 1].numLlamadas++;
                lineas[numeroLinea - 1].totalMinutos += minutos;
                lineas[numeroLinea - 1].totalCosto += costo;
                
                cout << "Llamada agregada exitosamente.\n";
            }
            break;
            
            case 2: {
                // Mostrar información de cada línea
                cout << "\n--- Información de cada línea ---\n";
                for (int i = 0; i < 3; i++) {
                    cout << "\nLínea " << i + 1 << ":\n";
                    cout << "  Número total de llamadas: " << lineas[i].numLlamadas << "\n";
                    cout << "  Duración total de llamadas (minutos): " << lineas[i].totalMinutos << "\n";
                    cout << "  Costo total de llamadas (pesos): " << fixed << setprecision(2) << lineas[i].totalCosto << "\n";
                }
            }
            break;
            
            case 3: {
                // Mostrar información consolidada sobre todas las líneas
                int totalLlamadas = 0;
                int totalMinutos = 0;
                double totalCosto = 0;
                
                for (int i = 0; i < 3; i++) {
                    totalLlamadas += lineas[i].numLlamadas;
                    totalMinutos += lineas[i].totalMinutos;
                    totalCosto += lineas[i].totalCosto;
                }
                
                double costoPromedio = (totalMinutos != 0) ? totalCosto / totalMinutos : 0;
                
                cout << "\n--- Información Consolidada ---\n";
                cout << "Costo total (pesos): " << fixed << setprecision(2) << totalCosto << "\n";
                cout << "Número total de llamadas: " << totalLlamadas << "\n";
                cout << "Duración total de llamadas (minutos): " << totalMinutos << "\n";
                cout << "Costo promedio por minuto: " << fixed << setprecision(2) << costoPromedio << "\n";
            }
            break;
            
            case 4:
                for (int i = 0; i < 3; i++) {
                    lineas[i].numLlamadas = 0;
                    lineas[i].totalMinutos = 0;
                    lineas[i].totalCosto = 0;
                }
                cout << "\nLa información ha sido reiniciada.\n";
                break;
            
            case 5:
                cout << "\nSaliendo del programa...\n";
                break;
            
            default:
                cout << "\nOpción inválida. Por favor seleccione una opción del menú.\n";
        }
    } while (opcion != 5);

    return 0;
}