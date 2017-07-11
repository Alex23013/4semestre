#include <iostream>
#include "nodo.h"
#include "pila.h"
using namespace std;

void caratula()
{
	cout << "Ingrese una opcion: "<<endl;
	cout << "1: añadir nodo"<<endl;
	cout << "3: sacar un  nodo"<<endl;
	
}
int main()
{
	pila mypila;
	int opcion;
	int salida =5;
	while(salida != 0)
	{
	caratula();
	cin >> opcion;
	if(opcion ==1){
		int datos;
		cout << "cuantos datos quiere añadir" <<endl;
		cin>>datos;	
		for(int i =0;i< datos;i++){
			cout << "Ingrese el dato "<< i+1 <<endl;
			int n;
			cin>>n;		
			mypila.add_nodo(n);}
		cout << "la nueva pila es " <<endl;
		mypila.print_pila();
	}
	if(opcion ==3)	
		{cout << "el dato es:  ";
		mypila.get_dato();
		cout << "la pila contiene:  " <<endl;
		mypila.print_pila();}
	cout << "Que desea hacer ahora? "<<endl;
	cout << "1: volver al menu    0: salir"<<endl;
	cin >> salida;
	}
}
