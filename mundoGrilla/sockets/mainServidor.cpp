//mainServidor.cpp

#include "Servidor.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Servidor Server(512); //Constructor con tamaño de buffer
    Server.Conexion(4003); //Intento conexion a numero de puerto

    char mensaje[512];

    Server.Lectura();
    
    cout << "Mensaje?: "; cin.getline(mensaje, 512);

    //cout << "antes" << mensaje << std::endl;
    Server.Escritura(mensaje);

}