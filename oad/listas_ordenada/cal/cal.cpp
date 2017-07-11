#include <iostream>
#include "cola.h"
#include "pila.h"
using namespace std;

class Calculadora{
private:	
	cola mycola;
	pila mypila;
public:
	string rpn(string input){
	int contador=0;
	string numeros="0123456789";
/*	
	for(contador=1;contador<6;contador++){
	cout<<"lo que entra: "<<input[contador]<<endl;
	a_pila(input[contador]);
	cout<<"pila: "<<endl;
	mypila.print_pila();}
	for(contador=8;contador<13;contador++){
	a_cola(input[contador+1]);
	cout<<"cola: "<<endl;
	mycola.print_cola();}
*/
	for(contador=1;contador<6;contador++){
		//if(numeros.find(input[contador])>0 && numeros.find(input[contador])<numeros.size() )
		while(numeros.find(input[contador])>0 && numeros.find(input[contador])<numeros.size() )
			{
			cout<<"->"<<numeros.find(input[contador])<<" --> "<<input[contador];
			a_cola(input[contador]);
			contador++;
			}
		cout<<"cola: "<<endl;
	mycola.print_cola();}
	
	return input;
	}

	void a_pila(char n){
	mypila.add_nodo(n);	
	}

	void a_cola(char n){
	mycola.add_nodo(n);	
	}
};

int main()
{
	Calculadora OAD;
	string input;
	cout<<"escriba la operación: "<<endl;
	getline(cin,input);
	cout<<"la operacion era: "<<input<<endl;
	string output;	
	output=OAD.rpn(input);
	cout<<"Respuesta: "<<output<<endl;
}


/*mycola.add_nodo(n);
mycola.print_cola();
mycola.get_dato();*/

/*
mypila.add_nodo(n);
mypila.print_pila();
mypila.get_dato();
*/

//ggdelgado@ucsp.edu.pe
