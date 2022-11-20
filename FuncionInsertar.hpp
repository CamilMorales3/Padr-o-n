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

bool Comprobar(string _dui)
{
    ifstream FicheroLectura("registrosPadron.txt", ios::in);
    string departamento;
    string DUI;
    string sector;
    string apellidos;
    string nombres;
    string nac;
    FicheroLectura >> DUI;
    // Leer hasta llegar al final
    while (!FicheroLectura.eof())
    {
        FicheroLectura >> sector;
        if (DUI == _dui)
        {
            FicheroLectura.close();
            return false;
        }
        FicheroLectura >> DUI;
    }
    FicheroLectura.close();
    // Permite escribir en el archivo
    return true;
}

void Agregar(ofstream &ficheroEscritura)
{
    string departamento;
    string DUI;
    string sector;
    string apellidos;
    string nombres;
    string nac;

    ficheroEscritura.open("registrosPadron.txt", ios::out | ios::app);

    cin.ignore();
    cout << "Digite su departamento" << endl;
    getline(cin, departamento);
    cout << "Digite su numero de DUI" << endl;
    cin >> DUI;
    cin.ignore();
    cout << "Digite el sector (municipio) en donde desea votar" << endl;
    getline(cin, sector);
    cout << "Digite sus nombres (primero_segundo)" << endl;
    getline(cin, nombres);
    cout << "Digite sus apellidos (primero_segundo)" << endl;
    getline(cin, apellidos);
    cout << "Digite fecha de nacimineto en el formato DD/MM/AAAA" << endl;
    cin >> nac;

    if (Comprobar(DUI))
    {
        ficheroEscritura << departamento << " " << DUI << " " << sector << " " << apellidos << " " << nombres << " " << nac
                         << " "
                         << "\n";
    }
    ficheroEscritura.close();
}