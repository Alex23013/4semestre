#include <iostream>
#include "rsa.h"
using namespace std;

int rsa :: generar_k_pub(){
	
}

int rsa :: generar_K_priv(){
	
}

int rsa :: cifrar(int mensaje){
	return mensaje;
}

int rsa :: descifrar(int cifrado){
	return cifrado;
}


int main(){

cout<<"\n INicio de sesion =) \n "	;
	rsa YO;
	int opcion =5;
	while(opcion != 0){
		int k_pub;
		int n;
		rsa emisor(k_pub,n);
		int cambiar_objeto=5;
		while(cambiar_objeto != 4){
			int mensaje;
			cout<<"\n Ingrese el mensaje a cifrar \n ";
			cin>>mensaje;
			int cifrado= emisor.cifrar(mensaje);
			cout<<"cifrado: "<< cifrado << "\n";
			int original = YO.descifrar(cifrado);
			cout<<"originalL: "<< original << "\n";
			cout<<"\n Que desea hacer? 1:continuar con este objeto 4:cambiar de objeto \n";
			cin>>cambiar_objeto ;
		}
		cout<<"\n Que desea hacer? 1:continuar en sesion 0:cerrar sesion \n";
		cin>>opcion;
	}
	
cout<<"\n Sesion terminada XD \n "	;
}
