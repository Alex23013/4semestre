#include <iostream>
#include "funciones.h"
using namespace std;

class Afin
{
private:
	int clave_a;
	int clave_b;
public:
	string alfabeto;
    int tam;
	Afin(){
		cout<<"(1 contructor) "<<endl;
		//alfabeto = "abcdefghijklmnopqrstuvwxyz ";
		alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789.,-_";
		tam=alfabeto.size();
		this -> clave_a = generar_clave_a(tam);
		this -> clave_b = generar_clave_b(tam);
		}
	Afin(int a, int b){
		cout<<"(2 contructor) "<<endl;
		//alfabeto = "abcdefghijklmnopqrstuvwxyz ";
		alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789.,-_";
		tam=alfabeto.size();
		this -> clave_a=la_inversa(a,tam,tam);
		if(b>tam){b=mod(b,tam);}
		this -> clave_b =b;
		}

	int get_clave_a(){return clave_a;}
	int get_clave_b(){return clave_b;}

	string cifrar(string mensaje)
	{

		for(int i=0;i<mensaje.size();i++)
        {
            int found = alfabeto.find(mensaje[i]);
            int cambio=(found*clave_a)+clave_b;
            cambio=mod(cambio,tam);
            mensaje[i]= alfabeto[cambio];
        }

		return mensaje;
	}

	string descifrar(string mensaje)
	{

		for(int i=0;i<mensaje.size();i++)
		{
		    int found = alfabeto.find(mensaje[i]);
		    int cambio=clave_a*(found-clave_b);
		    cambio=mod(cambio,tam);
		    mensaje[i]= alfabeto[cambio];
		}

		return mensaje;
	}
};
