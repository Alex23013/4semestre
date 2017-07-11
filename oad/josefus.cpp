#include <iostream>
#include"lista_simple.h"
using namespace std;

void matar_deX(lista JOS, int razon){
	nodo* aux= JOS.start;
	nodo* start=JOS.start;
	int tama=JOS.len_lista;
	//cout<<"aux <-> "<<aux->info;
	nodo*end=start;
	for(int i=0;i<tama-1;i++){
	end=end->sig;
	}
	end->sig=start;
	//JOS.start->sig->sig->sig->sig->sig=JOS.start;
	

	while(tama>2){
	aux=start->sig->sig;
	start->sig->sig=start->sig->sig->sig;
	start=aux->sig;
	tama=tama-1;
	//cout<<"tam: "<<tama;
	}
	JOS.print_lista();
	cout<<"sob 1: "<<start->num<<endl;
	cout<<"sob 2: "<<start->sig->num<<endl;

}

int main(){
	lista JOSEFUS;
	for(int i =0;i<6;i++){
	JOSEFUS.add_nodo(i,'t');}
	JOSEFUS.print_lista();
	cout<<"size "<<JOSEFUS.len_lista<<endl;
	matar_deX(JOSEFUS,2);
}

