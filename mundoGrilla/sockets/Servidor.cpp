//Servidor

//#include <stdio.h>
#include "Servidor.hpp"

#include <iostream>

using std::cout;
using std::cin;

Servidor::Servidor(int buffer_size)
{
    this-> buffer_size = buffer_size;
    buffer = new char[buffer_size];

}

Servidor::~Servidor()
{
    close(aceptado_fd);
    close(socket_fd);
}

bool Servidor::Conexion (int num_puerto)
{
    // Creacion del Socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) 
    {
        perror("ERROR opening socket");
        return 1;
    }
        
    // Setear a 0 el buffer del servidor
    bzero((char *) &servidor_addr, sizeof(servidor_addr));
    
    // Seteando struct servidor_addr
    servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_addr.s_addr = INADDR_ANY; //direccion IP del servidor
    servidor_addr.sin_port = htons(num_puerto); // conversion network byte order

    //Asignacion de un nombre al socket
    if (bind(socket_fd, (struct sockaddr *) &servidor_addr, sizeof(servidor_addr)) < 0)
    {
        perror ("ERROR on binding");
        return 1;
    }

    // listen a socket por conexion, 2 numero maximo de conexiones en espera
    listen(socket_fd,2); 

    //En espera por conexion
    cliente_len = sizeof(cliente_addr);
    aceptado_fd = accept(socket_fd, (struct sockaddr *) &cliente_addr, &cliente_len);
    if (aceptado_fd < 0) 
    {
       perror("ERROR on accept");
       return 1;
    }
    return 0;
}

bool Servidor::Lectura()
{
    //int status_IO; // valor retornado por read() y write() calls
    int status_IO;
    bzero(buffer, buffer_size);
    status_IO = read(aceptado_fd, buffer, buffer_size -1); //socket_id = aceptado_fd
    if (status_IO < 0) 
    {
        perror("ERROR de lectura de socket");
        return 1;
    }
    //mensaje_recibido = buffer;
    cout << "Recibido: " << buffer << "\n";
    return 0;
}

bool Servidor::Escritura(char* mensaje )
{
    int status_IO;
    std::string temp = mensaje;
    int mensaje_size = temp.length();
    
    bzero(buffer, buffer_size);    
    status_IO = write(aceptado_fd, mensaje, mensaje_size);
    if (status_IO < 0)
    {
        perror("ERROR de escritura a socket");
        return 1;
    } 
}