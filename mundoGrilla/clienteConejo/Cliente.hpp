//Cliente.hpp

#ifndef __Cliente_hpp__
#define __Cliente_hpp__


#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>



class Cliente
{
public:
    Cliente(int buffer_size);
    ~Cliente();
    bool Conexion (char* nombre_servidor, int num_puerto);
    char* Lectura(char* recibo);
    char* Escritura(char* envio);
    int buffer_size;
    char* buffer; // buffer de IO para los sockets

    // file descriptor usados por socket y accept
    int socket_fd, aceptado_fd;

    //longitud de la direccion del cliente usado por accept
    socklen_t cliente_len;

    // struct necesario para sockaddr_in definida en netinet/in.h 
    struct sockaddr_in servidor_addr;
    struct hostent *servidor;

    //Metodos
    
    
};



#endif // !__Cliente_hpp__
