#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include "Funciones.hpp"

using namespace std;

int main()
{

    system("color 09");

    ofstream ficheroEscritura;
    ifstream ficheroLectura;

    int opc;
    string depart, dui, sect, apellido, nombre, nac;


    // MENÚ
    do
    {
        system("cls");
        cout << "----------BIENVENIDO AL SISTEMA DE PADRON ELECTORAL----------" << endl;
        cout << endl;
        cout << "DIGITE UNA OPCION" << endl;
        cout << "1) AGREGAR DATOS" << endl;
        cout << "2) BUSCAR DATOS POR NUMERO DE DUI" << endl;
        cout << "3) MOSTRAR PADRON ELECTORAL COMPLETO" << endl;
        cout << "4) ELIMINAR DATOS" << endl;
        cout << "5) ASIGNAR URNA" << endl;
        cout << "6) SALIR" << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            cout << "NOTA: Cada vez que ponga un espacio, por favor utilice un _" << endl;
            cout << endl;
            Agregar(ficheroEscritura);
            cout << "DATOS INGRESADO CORRECTAMENTE" << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "\t------BUSQUEDA POR NUMERO DE DUI------" << endl;
            cout << endl;
            cout << "NOTA: Si no muestra los datos, el DUI que ingreso no existe o has escrito algo mal" << endl;
            cout << endl;
            MostrarDui(ficheroLectura);
            cout << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "\t------PADRON ELECTORAL------" << endl;
            cout << endl;
            Imprimir(ficheroLectura);
            cout << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "\t------ELIMINAR REGISTRO------" << endl;
            cout << endl;
            cout << "NOTA: Si no muestra el mensaje de REGISTRO ELIMINADO, el DUI que ingreso no existe o has escrito algo mal" << endl;
            cout << endl;
            Eliminar(ficheroLectura);
            cout << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "\t------ASIGNAR URNA------" << endl;
            cout << endl;
            cout << "NOTA: Si no muestra los datos, el DUI que ingreso no existe o has escrito algo mal" << endl;
            cout << endl;
            AsignarUrna();
            cout << endl;
            system("pause");
        default:
            break;
        }
    } while (opc < 6);

    cout << "QUE TENGA UN BUEN DIA! :D" << endl;

    system("pause");
    return 0;
}
