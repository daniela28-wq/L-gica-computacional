#include <iostream>
#include <cstdlib>
using namespace std;

// Estructura para almacenar la información de cada cliente y sus llamadas
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
    // system("cls"); // Solo necesario si deseas limpiar la pantalla
    // Se agrega estructura de portada con system.cls.
    cout << "--------------------------------------------------------------\n";
    cout << "     Les presenta Laura Forero, Daniela Portela y Evelin Solano\n";
    cout << "              La cabina titulada: MINUTEAM\n";
    cout << "--------------------------------------------------------------\n";
    cout << "Presiona ENTER para continuar...\n";
    cin.ignore();
    cin.get();

    int opcion;
    int tam = 0;
    cliente listaClientes[100]; // hasta 100 clientes
    
   //Menú al principio para una mejor navegación del usuario
   
    do {
        cout << "\n--------------- MENÚ ---------------\n";
        cout << "1. Registrar clientes y llamadas\n";
        cout << "2. Ver información detallada de un cliente\n";
        cout << "3. Ver resumen general del sistema\n";
        cout << "4. Reiniciar sistema\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción:\n";
        cin >> opcion;
        
 //Dependiendo la opción se agaregan clientes
 
        switch(opcion) 
        {
            case 1: 
            {
                cout << "¿Cuántos clientes agregaremos el día de hoy?\n";
                cin >> tam;

                if (tam > 100) {
                    cout << "El máximo permitido es 100. Se establecerá ese límite.\n";
                    tam = 100;
                }

                for(int i = 0; i < tam; i++) 
                {
                    cout << "Nombre del cliente #" << (i+1) << ":\n";
                    cin >> listaClientes[i].nombre;

                    cout << "¿Cuántas llamadas realizó " << listaClientes[i].nombre << "?\n";
                    cin >> listaClientes[i].cantidad_llamadas;

                    if(listaClientes[i].cantidad_llamadas > 100) 
                    {
                        cout << "El número máximo de llamadas es 100. Se establecerá este límite.\n";
                        listaClientes[i].cantidad_llamadas = 100;
                    }

                    for(int x = 0; x < listaClientes[i].cantidad_llamadas; x++) 
                    {
                        cout << "ID de la llamada " << (x+1) << ":\n";
                        cin >> listaClientes[i].id_llamada[x];
                        
//Se establecen categorías para almacenar

                        int categoria_opcion;
                        cout << "Categoría de la llamada:\n1. Local\n2. Larga distancia\n3. Celular\n";
                        cin >> categoria_opcion;

                        switch(categoria_opcion) 
                        {
                            case 1: listaClientes[i].categoria[x] = "local"; break;
                            case 2: listaClientes[i].categoria[x] = "larga"; break;
                            case 3: listaClientes[i].categoria[x] = "celular"; break;
                            default: listaClientes[i].categoria[x] = "desconocida";
                        }
//Se calcula las duraciones y precios de cada llamada registrada

                        cout << "¿Cuántos minutos duró la llamada?\n";
                        cin >> listaClientes[i].duracion[x];

                        switch(categoria_opcion) 
                        {
                            case 1: listaClientes[i].valor[x] = listaClientes[i].duracion[x] * 35; break;
                            case 2: listaClientes[i].valor[x] = listaClientes[i].duracion[x] * 380; break;
                            case 3: listaClientes[i].valor[x] = listaClientes[i].duracion[x] * 999; break;
                            default: listaClientes[i].valor[x] = 0;
                        }
                    }
                }
                break;
            }
//En caso de seleccionar en el menú una opción diferente, se deben de agregar primero clientes
            case 2: 
            {
                if (tam == 0) {
                    cout << "Primero debe registrar clientes.\n";
                    break;
                }

                int posCliente;
                cout << "Ingrese el número del cliente (de 0 a " << tam - 1 << "): ";
                cin >> posCliente;

                if(posCliente >= 0 && posCliente < tam) 
                {
                    cout << "\nInformación del cliente: " << listaClientes[posCliente].nombre << "\n";

                    int llamadas_local = 0, llamadas_larga = 0, llamadas_celular = 0;
                    float total_local = 0, total_larga = 0, total_celular = 0;
                    float tiempo_local = 0, tiempo_larga = 0, tiempo_celular = 0;

                    for(int x = 0; x < listaClientes[posCliente].cantidad_llamadas; x++) 
                    {
                        string _categoria = listaClientes[posCliente].categoria[x];
                        float _duracion = listaClientes[posCliente].duracion[x];
                        float _valor = listaClientes[posCliente].valor[x];

                        if(_categoria == "local") {
                            llamadas_local++;
                            tiempo_local += _duracion;
                            total_local += _valor;
                        } else if (_categoria == "larga") {
                            llamadas_larga++;
                            tiempo_larga += _duracion;
                            total_larga += _valor;
                        } else if (_categoria == "celular") {
                            llamadas_celular++;
                            tiempo_celular += _duracion;
                            total_celular += _valor;
                        }
                    }
//Muestra las informaciones para los resumenes

                    cout << "\nDetalle por categoría:\n";
                    cout << "Locales: " << llamadas_local << " llamadas, " << tiempo_local << " minutos, $" << total_local << "\n";
                    cout << "Larga distancia: " << llamadas_larga << " llamadas, " << tiempo_larga << " minutos, $" << total_larga << "\n";
                    cout << "Celulares: " << llamadas_celular << " llamadas, " << tiempo_celular << " minutos, $" << total_celular << "\n";
                }
                else 
                {
                    cout << "Número de cliente inválido.\n";
                }
                break;
            }

            case 3: 
            {
                if (tam == 0) {
                    cout << "Primero debe registrar clientes.\n";
                    break;
                }

                int total_llamadas = 0;
                float total_duracion = 0;
                float total_valor = 0;
                
//Muestra el resumen general en el sistema

                cout << "\nResumen general del sistema:\n";
                for(int i = 0; i < tam; i++) 
                {
                    for(int x = 0; x < listaClientes[i].cantidad_llamadas; x++) 
                    {
                        total_llamadas++;
                        total_duracion += listaClientes[i].duracion[x];
                        total_valor += listaClientes[i].valor[x];
                    }
                }

                cout << "Total de llamadas registradas: " << total_llamadas << "\n";
                cout << "Duración total de llamadas: " << total_duracion << " minutos\n";
                cout << "Costo total del sistema: $" << total_valor << "\n";
                break;
            }
//Se reinicia el sistema
            case 4: 
            {
                tam = 0;
                cout << "Sistema reiniciado. Se borraron todos los datos.\n";
                break;
            }

            case 0:
                cout << "Gracias por comunicarte con nosotros. ¡Adiós!\n";
                break;

            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }

    } while(opcion != 0);

    return 0;
}
