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

void Eliminar(ifstream &ficheroLectura)
{
    string departamento;
    string DUI;
    string sector;
    string apellidos;
    string nombres;
    string nac;
    string temp_p;

    ficheroLectura.open("registrosPadron.txt", ios::in);
    ofstream temp("tmp.txt", ios::out);

    if (ficheroLectura.is_open())
    {
        cout << "Ingrese el numero de DUI: " << endl;
        cin >> temp_p;
        ficheroLectura >> departamento;
        while (!ficheroLectura.eof())
        {
            ficheroLectura >> DUI;
            ficheroLectura >> sector;
            ficheroLectura >> nombres;
            ficheroLectura >> apellidos;
            ficheroLectura >> nac;
            if (DUI == temp_p)
            {
                cout << "RESGISTRO ELIMINADO";
            }
            else
            {
                temp << departamento << " " << DUI << " " << sector << " " << apellidos << " " << nombres << " " << nac
                     << " "
                     << "\n";
            }
            ficheroLectura >> departamento;
        }
        ficheroLectura.close();
        temp.close();
    }
    else
    {
        cout << "Error al abrir el archivo";
    }
    remove("registrosPadron.txt");
    rename("tmp.txt", "registrosPadron.txt");
}
