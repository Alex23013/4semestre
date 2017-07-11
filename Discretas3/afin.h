#include <iostream>
#include "funciones.h"
using namespace std;

class Afin
{
private:
	long long clave_a;
	long long clave_b;
public:
	string alfabeto;
    	long long tam;
	Afin(){
		cout<<"(1 contructor) "<<endl;
		alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVXYZ,-_.0123456789";
		tam=alfabeto.size();
		cout<<"TAMANPÑ: "<<tam<<endl;
		//this -> clave_a = generar_clave_a(tam);
		
		this -> clave_a =79;
		if(clave_a>tam)}
		this -> clave_b = generar_clave_b(tam);
		//this -> clave_b =46;
		}
	Afin(long long a, long long b){
		cout<<"(2 contructor) "<<endl;
		alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVXYZ,-_.0123456789";
		tam=alfabeto.size();
		//this -> clave_a=la_inversa(a,tam,tam);
		//cout<<"la inversa:"<<clave_a;
		this -> clave_a=a;
		this -> clave_b =b;
		}
	
	long long get_clave_a(){return clave_a;}
	long long get_clave_b(){return clave_b;}

	string cifrar(string mensaje)
	{

		for(long long i=0;i<mensaje.size();i++)
        {
            long long found = alfabeto.find(mensaje[i]);
	    long long cambio=(found*clave_a)+clave_b;
            cambio=mod(cambio,tam);
            mensaje[i]= alfabeto[cambio];
        }

		return mensaje;
	}

	string descifrar(string mensaje)
	{
		
		for(long long i=0;i<mensaje.size();i++)
		{
		    long long found = alfabeto.find(mensaje[i]);
		    long long cambio=clave_a*(found-clave_b);
		    cambio=mod(cambio,tam);
		    mensaje[i]= alfabeto[cambio];
		}
	
		return mensaje;
	}
	
	
	
};
