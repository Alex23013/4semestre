#include <iostream>
#include "lista_simple.h"

using namespace std;
class mano
{
public:
	lista  Mis_cartas; 
	
	int get_size(){
   		return Mis_cartas.len_lista;}

   	void add_card(int i,char color){
      		Mis_cartas.add_nodo(i,color);}

	void print_mano()
		{
		cout<<"\n son mis cartas:\n";
		Mis_cartas.print_lista();
		}
	void last_card(){
	      	nodo *cent;
		cent=Mis_cartas.start;
		    if(cent == NULL)
		    {cout<<"La lista sta vacia :/";}// tiene "<<len_lista<<" elementos"<<endl;return;}
		    while(cent->sig){
			//cent->print_carta();
			//cent->print_nodo();
			cent =cent->sig;
		    }
			cent->print_nodo();
		}

};
/*
int main()
{
	/*mano a;
	a.add_card(3);a.add_card(6);a.add_card(5);
	a.print_mano();
	mano b;
	b.add_card(9);
	b.print_mano();   
	cout<<"\n la first carat:"<<b[0];*/
	/*
	lista a;
	a.add_nodo(3,'y');
	a.add_nodo(3,'y');
	cout<<a[0]<<endl; 
  return 0;
}*/
