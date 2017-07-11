#include <iostream>
#include "afin.h"
using namespace std;


int main()
{
	Afin Emisor;
	cout<<"CLAVE A: "<<Emisor.get_clave_a()<<endl;
	cout<<"CLAVE B: "<<Emisor.get_clave_b()<<endl;
	Afin Receptor(Emisor.get_clave_a(),Emisor.get_clave_b() );
    //Afin Receptor(47,4665);
	cout<<"CLAVE A: "<<Receptor.get_clave_a()<<endl;
	cout<<"CLAVE B: "<<Receptor.get_clave_b()<<endl;

	string mensaje;
	cout<<"escriba el mensaje: "<<endl;
	getline(cin,mensaje);
	string cifrado = Emisor.cifrar(mensaje);
	//string cifrado ="zLDXFh5xEYrEh5xyQLDlhMD.QLhIvIpI1p8PWPi";
	string original = Receptor.descifrar(cifrado);
	cout<< "mensaje: " <<mensaje<<endl;
	cout<<"cifrado: "<<cifrado <<endl;
	cout<<"original: "<<original<<endl;
 }
