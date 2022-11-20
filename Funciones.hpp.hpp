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

void Imprimir(ifstream &ficheroLectura)
{
    string departamento;
    string DUI;
    string sector;
    string apellidos;
    string nombres;
    string nac;
    ficheroLectura.open("registrosPadron.txt", ios::in);
    if (ficheroLectura.is_open())
    {
        ficheroLectura >> departamento;
        while (!ficheroLectura.eof())
        {
            ficheroLectura >> DUI;
            ficheroLectura >> sector;
            ficheroLectura >> apellidos;
            ficheroLectura >> nombres;
            ficheroLectura >> nac;

            cout << "Departamento: " << departamento << endl;
            cout << "DUI: " << DUI << endl;
            cout << "Sector: " << sector << endl;
            cout << "Apellidos: " << apellidos << endl;
            cout << "Nombres: " << nombres << endl;
            cout << "Fecha de Nacimiento: " << nac << endl;
            cout << "*******" << endl;
            ficheroLectura >> departamento;
        }

        ficheroLectura.close();
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    }
}