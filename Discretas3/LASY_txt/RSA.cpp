#include <iostream>
#include <fstream>
#include "RSA.h"
using namespace std;
/*
int RSA::com()
{

}*/


int pow(int base, int exp){
int re =1;
for(int i=0;i<exp;i++)
	{re =re*base;}
return re;
}

int stringToNumber(string str)
{
    int number=0;
    int temp;
    long j=str.length()-1;
    int diez=10;
    for(int i = 0; i < str.length(); i++)
    {
        temp=str[i]-48;
	//cout<<"t: "<<temp<<" ";
	//cout<<"temp*(pow(diez,j-i)"<<temp*(pow(diez,j-i));
	if(temp != -35){
		number=number+(temp*(pow(diez,j-i)));
        }
    }

    return number;
}
/*
int main(){
int a;
a= stringToNumber("45"); cout<<"a: "<<a<<endl;}
*/

int main()
{
	RSA Receptor;
	int mensaje;


	fstream ficheroEntrada;
    string nombre_fichero;
   	string frase1;
   	string frase2;

        //cout << "Dime el nombre del fichero: ";
    	//getline(cin,nombre_fichero);
        nombre_fichero="plano.txt";

	    ficheroEntrada.open ( nombre_fichero.c_str() , ios::in);
	    if (ficheroEntrada.is_open()) {

		getline(ficheroEntrada,frase1);
		getline(ficheroEntrada,frase2);
	       ficheroEntrada.close();
	    }
	    else {
		cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;
	    }

	/*cout<<"Ingrese las claves: \n";
	cout<<"clave publica: \n";
	cin>>k_p;//19
	cout<<" N: \n";
	cin>>N_p;//91*/

	int k_p=stringToNumber(frase1);
	int N_p=stringToNumber(frase2);
	cout<<"(k_p,N_p) "<<k_p<<" , "<<N_p<<endl;
	RSA Emisor(k_p,N_p);
	int opcion =4;
	while(opcion != 0){



	cout<<"escriba el mensaje: "<<endl;
	cin>>mensaje;
	cout<< "mensaje: " <<mensaje<<endl;

	int cifrado = Emisor.cifrar(mensaje);
	cout<<"cifrado: "<<cifrado <<endl;
	int original = Receptor.descifrar(cifrado);
	cout<<"original: "<<original<<endl;

	cout<<"que desea hacer? 1: continuar 0:salir \n";
	cin>>opcion;
	}
	cout<<"Sesion terminada \n";

}
