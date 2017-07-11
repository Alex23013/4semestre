#include <iostream>
#include "lista_simple.cpp"
using namespace std;

void ordenar(lista A,lista B){
nodo *cent1;
    cent1=A.start;
nodo *cent2;
    cent2=B.start;
nodo *vigia;
	vigia=A.start;

	cout<<"Recorriendo la lista"<<endl;
while(vigia){
	nodo* aux1;
	nodo *aux2;
	 cout<<vigia->info<<" ";
	if(cent1->info <= cent2->info){aux1=cent1->sig;cent1->sig=cent2;}
	else{cent2->sig=cent1;}        
	vigia =vigia->sig;
	cent1=aux1;
	
   }	
cout<<endl;
A.print_lista();
}

int main()
{
	lista mylista;	
	for(int i =1;i< 14;i=i+3)
			{mylista.add_nodo(i);}
	lista listaB;
	for(int i =2;i< 5;i++)
			{listaB.add_nodo(i);}

		cout << "la lista A es " <<endl;
		mylista.print_lista();
	
		cout << "la lista B es " <<endl;
		listaB.print_lista();
	ordenar(mylista,listaB);

}
