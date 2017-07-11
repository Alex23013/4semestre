
#include <iostream>
#include <stdlib.h>
#include<sstream>
using namespace std;

#define s 100
class CasillaGrilla {
   int NYerba; //la cantidad de yerba por casilla
   char Animal; //por un char sabemos que animal tiene
   public:
   void CrearCasilla (){
      NYerba = rand()%4;
      Animal=' '; // iniciamos con ning�n animal
   }

   bool UpdateAnimal (char NuevoAnimal){ // le puse bool para que nos confirme que se actualiz�, aunque tambi�n podr�a ser void pero interrumpiendo el proceso
       if (NuevoAnimal == 'c' || NuevoAnimal == 'z' ){
         Animal=NuevoAnimal;
         return true;
       }
      cout << "error ingrese un valor valido";
      return false;
   }

   void UpdateYerba (){
      NYerba=rand()%4; // igual que la anterior hay que llamar a random de 0 a 3
   }
   char VerCasilla(){
       return Animal;
   }
   int VerYerba(){
       return NYerba;
   }
   void EditarAnimal(char NuevoAnimal){
       Animal=NuevoAnimal;
   }
};

class Grilla{
public:
    CasillaGrilla MundoGrilla[100][100];

    char VerCasilla(int a, int b){
        return MundoGrilla[a][b].VerCasilla();
    }
    int VerYerba(int a, int b){
        return MundoGrilla[a][b].VerYerba();
    }
    void EditCasilla(char Nuevo, int a, int b){
        MundoGrilla[a][b].EditarAnimal(Nuevo);
    }
    void CreceHierba(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            MundoGrilla[i][j].UpdateYerba ();
        }
    }
    }

    bool insertaranimal(string coordenadas, char animal)
    {
        if (coordenadas.size() % 4 != 0)
        {
            cout << "coordenadas invalidas" << endl;
            return 0;
        }
        int posx, posy;
        for(int i = 0; i < coordenadas.size(); i+=4)
        {
            string tmp1(coordenadas,i,i+2);
            string tmp2(coordenadas,i+2,i+4);
            posx = atoi(tmp1.c_str()); //funcion que transforma de string a int
            posy = atoi(tmp2.c_str());
	     EditCasilla(animal, posx, posy);
        }
	     return 1;
    }

    string pocisioneszorros(){
    string coordenadas;
    char temp;
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            if(VerCasilla(i,j)=='Z'){
                if(i<10){
                    coordenadas.push_back('0');
                    temp =i+'0';
                    coordenadas.push_back(temp);
                    }
                else {
                    stringstream ss; ss << i;
                    coordenadas += ss.str();
                }
                if(j<10){
                    coordenadas.push_back('0');
                    temp =j+'0';
                    coordenadas.push_back(temp);
                    }
                else {
                    stringstream ss; ss << j;
                    coordenadas += ss.str();
                    }
                }
            }
        }
        return coordenadas;
    }
};


/*
void CantidadDeHierba(string cadena, char matriz[s][s])
{
    if(cadena.size()%6==0)
    {
        int l=cadena.size()/6;  //"l" contiene la cantidad de veces que se repetir� la acci�n
        int cont=0;
        long numero=atoi(cadena.c_str());    // "numero" sera el numero del string a entero
        char coord_x[l],coord_y[l],contenido[l]; //Se crean chars que contendr�n las coordenadas y la cantidad de hierbas en cada uno

        for(int i=l;i>0;i--)
        {
            contenido[l]=numero%100;
            coord_y[l]=(numero/100)%100;
            coord_y[l]=(numero/10000)%100;
            numero/=1000000;
        }


        //Se reemplaza en la matriz la cantidad de hierba en sus respectivas coordenadas
        for(int i=0;i<=s;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(coord_x[cont]==i&&coord_y[cont]==j)
                {
                    matriz[i][j]==contenido[cont];
                    cont++;
                }
            }
        }
    }

}*/
