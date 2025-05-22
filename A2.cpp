#include <iostream>
using namespace std;

int main() 
{
    int categoria_opcion;
    cout<<"Ingresar una opción de categoría?";
    cin>>categoria_opcion;// Valor inválido

    string categoria;
    cout << "Opcion ingresada para categoria: " << categoria_opcion << endl;

    switch(categoria_opcion) 
    {
        case 1: categoria = "local"; break;
        case 2: categoria = "larga"; break;
        case 3: categoria = "celular"; break;
        default: categoria = "desconocida";
    }

    cout << "Resultado de la categoria asignada: " << categoria << endl;

    return 0;
}
