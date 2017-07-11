#include <iostream>
#include <NTL/ZZ.h>
#include <time.h>
#include <fstream>
#include "RSA.h"

using namespace std;
using namespace NTL;


int main()
{
	RSA Receptor;
	ZZ mensaje;


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

	ZZ k_p(INIT_VAL ,frase1.c_str());
	ZZ N_p(INIT_VAL ,frase1.c_str());
	cout<<"(k_p,N_p) "<<k_p<<" , "<<N_p<<endl;
	RSA Emisor(k_p,N_p);
	int opcion =4;
	while(opcion != 0){



	cout<<"escriba el mensaje: "<<endl;
	cin>>mensaje;
	cout<< "mensaje: " <<mensaje<<endl;

	ZZ cifrado = Emisor.cifrar(mensaje);
	cout<<"cifrado: "<<cifrado <<endl;
	ZZ original = Receptor.descifrar(cifrado);
	cout<<"original: "<<original<<endl;

	cout<<"que desea hacer? 1: continuar 0:salir \n";
	cin>>opcion;
	}
	cout<<"Sesion terminada \n";

}


