#include <iostream>
#include "RSA.h"
using namespace std;


int main()
{
	cout<<"RECEPTOR: ";
	RSA Receptor(13,17);
	cout<<"emisor: ";
	RSA Emisor(3,7);
	int mensaje;
	cout<<"escriba el mensaje: "<<endl;
	cin>>mensaje;
	cout<< "mensaje: " <<mensaje<<endl;
	int cifrado = Emisor.cifrar(mensaje,Receptor.clave_pub,Receptor.N);
	cout<<"cifrado: "<<cifrado <<endl;
	int original = Receptor.descifrar(cifrado);
	cout<<"original: "<<original<<endl;
}
