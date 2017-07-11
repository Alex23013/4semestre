//mainServidor.cpp

#include "Cliente.hpp"
#include <iostream>
#include <string>

using std::cout; using std::cin;

int main()
{
    char nombre_servidor[] = "localhost"; //el nombre del CPU servidor
    Cliente Agente(512); //Constructor con tamaño de buffer
    Agente.Conexion( nombre_servidor, 4003); //Intento conexion a numero de puerto

    char mensaje[512];

    cout << "Mensaje?: "; cin.getline(mensaje, 512);
    Agente.Escritura(mensaje);

    Agente.Lectura();

}