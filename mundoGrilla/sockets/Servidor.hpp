//Servidor.hpp

#ifndef __Servidor_hpp__
#define __Servidor_hpp__


#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>




class Servidor
{
public:
    Servidor(int buffer_size);
    ~Servidor();
    bool Conexion (int num_puerto);
    bool Lectura();
    bool Escritura(char* mensaje );

private:
    int buffer_size;
    char* buffer; // buffer de IO para los sockets

    // file descriptor usados por socket y accept
    int socket_fd, aceptado_fd;

    //longitud de la direccion del cliente usado por accept
    socklen_t cliente_len;

    // struct necesarios para sockaddr_in definida en netinet/in.h 
    struct sockaddr_in servidor_addr, cliente_addr;

    //Metodos
    
};

#endif