#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>

char SendBuff[512],RecvBuff[512];
char arrz[512]="00012233";
void mover()
{
    int menordistancia[3];//0=el conejo 1=distancia en x 2=distancia en y;
    int za[2];//zorro actual:x&y
    int ca[2];//conejo actual:x&y
    bool avanzar;
    for(int i=0;i<(sizeof(arrz)-1)/4;i++)
    {
        avanzar=true;
        menordistancia[0]=0;//#del conejo
        menordistancia[1]=abs(arrz[i*4]-48)*10+abs(arrz[i*4+1]-48)-(abs(arrc[0]-48)*10+abs(arrc[1]-48));//#distancia x ; para iniciar debe de ser lo mas grande posible
        menordistancia[2]=abs(arrz[i*4+2]-48)*10+abs(arrz[i*4+3]-48)-(abs(arrc[2]-48)*10+abs(arrc[3]-48));//#distancia y ; para iniciar debe de ser lo mas grande posible o el considerando el menor al primero conejo;
        za[0]=(arrz[i*4]-48)*10+(arrz[i*4+1]-48);
        za[1]=(arrz[i*4+2]-48)*10+(arrz[i*4+3]-48);
        for(int j=0;j<arrc.size()/4;j++)
        {
            ca[0]=(arrc[j*4]-48)*10+(arrc[j*4+1]-48);
            ca[1]=(arrc[j*4+2]-48)*10+(arrc[j*4+3]-48);
            ///DISTACIA DE X & Y DEL CONEJO AL ZORRO  && LA DEL MENOR

            if(abs(za[0]-ca[0])+abs(za[1]-ca[1]) < abs(menordistancia[1])+abs(menordistancia[2]))
            {
                menordistancia[0]=j;
                menordistancia[1]=za[0]-ca[0];//no el valor absoluto para saber a donde ir
                menordistancia[2]=za[1]-ca[1];
            }


        }
        if(menordistancia[1]!=0)
        {
            if(menordistancia[1]<0)
            {
                for(int m=0;m<arrc.size();m++)
                {
                    if(za[0]+1==(arrz[m*4]-48)*10+(arrz[m*4+1]-48))
                    {
                        avanzar=false;
                        break;
                    }

                }
                if (avanzar)
                {
                    arrz[i*4]=(za[0]+1)/10)+48;
                    arrz[i*4+1]=((za[0]+1)-((za[0]+1)/10)*10)=48;
                }

            }
            else
            {
                for(int m=0;m<arrc.size();m++)
                {
                    if(za[0]-1==(arrz[m*4]-48)*10+(arrz[m*4+1]-48))
                    {
                        avanzar=false;
                        break;
                    }

                }
                if (avanzar)
                {
                    arrz[i*4]=(za[0]-1)/10)+48;
                    arrz[i*4+1]=((za[0]-1)-((za[0]-1)/10)*10)=48;
                }

            }
        }
        else if(menordistancia[2]!=0)
        {
            if(menordistancia[2]<0)
            {
                for(int m=0;m<arrc.size();m++)
                {
                    if(za[1]+1==(arrz[m*4+2]-48)*10+(arrz[m*4+3]-48))
                    {
                        avanzar=false;
                        break;
                    }
                }
                if (avanzar)
                {
                    arrz[i*4+2]=(za[1]+1)/10)+48;
                    arrz[i*4+3]=((za[1]+1)-((za[1]+1)/10)*10)=48;
                }
            }
            else
            {
                for(int m=0;m<arrc.size();m++)
                {
                    if(za[1]-1==(arrz[m*4+2]-48)*10+(arrz[m*4+3]-48))
                    {
                        avanzar=false;
                        break;
                    }

                }
                if (avanzar)
                {
                    arrz[i*4+2]=(za[1]-1)/10)+48;
                    arrz[i*4+3]=((za[1]-1)-((za[1]-1)/10)*10)=48;
                }


            }
        }
    }
}




int main()
{

  WSADATA wsaData;
  SOCKET conn_socket;
  struct sockaddr_in server;
  struct hostent *hp;
  int resp;

  //Inicializamos la DLL de sockets
  resp=WSAStartup(MAKEWORD(1,0),&wsaData);
  if(resp){
    printf("Error al inicializar socket\n");
    getchar();return -1;
  }

  //Obtenemos la IP del servidor... en este caso
  // localhost indica nuestra propia máquina...
  hp=(struct hostent *)gethostbyname("localhost");

  if(!hp){
    printf("No se ha encontrado servidor...\n");
    getchar();WSACleanup();return WSAGetLastError();
  }

  // Creamos el socket...
  conn_socket=socket(AF_INET,SOCK_STREAM, 0);
  if(conn_socket==INVALID_SOCKET) {
    printf("Error al crear socket\n");
    getchar();WSACleanup();return WSAGetLastError();
  }

  memset(&server, 0, sizeof(server)) ;
  memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
  server.sin_family = hp->h_addrtype;
  server.sin_port = htons(6000);

  // Nos conectamos con el servidor...
  if(connect(conn_socket,(struct sockaddr *)&server,sizeof(server))==SOCKET_ERROR){
    printf("Fallo al conectarse con el servidor\n");
    closesocket(conn_socket);
    WSACleanup();getchar();return WSAGetLastError();
  }
  printf("Conexión establecida con: %s\n", inet_ntoa(server.sin_addr));

  strcpy(SendBuff,"Hola servidor... .P");
  //Enviamos y recibimos datos...
  printf("Enviando Mensaje... \n");
  send(conn_socket,SendBuff,sizeof(SendBuff),0);
  printf("Datos enviados: %s \n", SendBuff);

  printf("Recibiendo Mensaje... \n");
  recv(conn_socket,RecvBuff, sizeof(RecvBuff), 0);
  printf("Datos recibidos: %s \n", RecvBuff);

    string arrc=RecvBuff;
    mover ();
    SendBuff=arrz;
  getchar();

  // Cerramos el socket y liberamos la DLL de sockets
  closesocket(conn_socket);
  WSACleanup();
  return EXIT_SUCCESS;




}
