//Cliente.cpp

#include "Cliente.hpp"
#include <iostream>
using namespace std;
using std::cout;
using std::cin;

Cliente::Cliente(int buffer_size)
{
    this-> buffer_size = buffer_size;
    buffer = new char[buffer_size];
}

Cliente::~Cliente()
{
    close(aceptado_fd);
    close(socket_fd);
}

bool Cliente::Conexion (char* nombre_servidor, int num_puerto)
{
    // Creacion del Socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) 
    {
        perror("ERROR opening socket");
        return 1;
    }

    //Setear variable server puntero a struct hostent que
    //contiene informacion del server host

    servidor = gethostbyname(nombre_servidor);
    if (servidor == NULL)
    {
        perror("ERROR, no existe el host\n");
        exit(1);
    }

    // Setear a 0 el buffer del servidor
    bzero((char *) &servidor_addr, sizeof(servidor_addr));
    
    // Seteando struct servidor_addr
    servidor_addr.sin_family = AF_INET;
    //direccion IP del servidor
    bcopy((char *)servidor->h_addr, (char *)&servidor_addr.sin_addr.s_addr, servidor->h_length);
    servidor_addr.sin_port = htons(num_puerto); // conversion network byte order

    //Conexion al socket
    if (connect(socket_fd, (struct sockaddr *) &servidor_addr, sizeof(servidor_addr)) < 0)
    {
        perror ("ERROR en conexion");
        return 1;
    }

    return 0;
}

char* Cliente::Lectura(char* recibo)
{
    //int status_IO; // valor retornado por read() y write() calls
    int status_IO;
    bzero(buffer, buffer_size);
    //status_IO = recv(socket_fd, buffer, buffer_size,0);
    status_IO = read(socket_fd, buffer, buffer_size-1);
    if (status_IO < 0) 
    {
        perror("ERROR de lectura de socket");
    }
    while(status_IO == 0)status_IO=read(socket_fd,buffer,buffer_size-1);
    cout << "Recibido: " << buffer << "\n";
	recibo = buffer;
    return recibo;
}

char* Cliente::Escritura(char* envio)
{
    //cout<<envio<<endl;
    int status_IO;
    string temp(envio);
    //cout<<"envio_size: "<<temp.length()<<endl;
    bzero(buffer, buffer_size);
    status_IO = write(socket_fd, envio, temp.length());
    if (status_IO < 0)
    {
        perror("ERROR de escritura a socket");
    }
    cout << "Enviado: " << envio << "\n";
	return envio;
}
