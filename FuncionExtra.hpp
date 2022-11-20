#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Persona
{
    string departamento;
    string DUI;
    string sector;
    string apellidos;
    string nombres;
    string nac;
    Persona *siguiente;
};

ofstream ficheroEscritura;
ifstream ficheroLectura;

Persona *lista = NULL;

void AsignarUrna()
{
    char confir;

    do
    {
        MostrarDui(ficheroLectura);
        cout << endl;
        cout << "Los datos mostrados son los correctos?" << endl;
        cout << "s = si || n = no" << endl;
        cin >> confir;
        cin.ignore();
    } while ((confir == 'n') || (confir == 'N'));

    srand(time(0));
    for (int i = 0; i < 1; i++)
    {
        cout << "SE LE HA ASIGNADO LA URNA NUMERO: " << (rand() % 4 + 1) << endl;
    }
}