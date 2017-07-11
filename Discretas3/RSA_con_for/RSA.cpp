#include <iostream>
#include "RSA.h"
using namespace std;


int main()
{
	cout<<"RECEPTOR: ";
	RSA Receptor(19,17);
	cout<<"emisor: ";
	RSA Emisor(23,17);

	string mensaje;
	cout<<"escriba el mensaje: "<<endl;
	getline(cin,mensaje);
	cout<< "mensaje: " <<mensaje<<endl;
    int tam= mensaje.size();
    int cifrado[tam];
	Emisor.cifrar(mensaje,Receptor.clave_pub,Receptor.N,tam,cifrado);
	cout<<"El vector cifrado: "<<endl;
	for(int i =0;i<tam;i++){
        cout<<cifrado[i]<<" ";
	}
	cout<<endl;
	string original = Receptor.descifrar(cifrado,tam);
	cout<<"original: "<<original<<endl;
}
