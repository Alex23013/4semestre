#include "nodo.h"
using namespace std;
class cola
{
public:
	nodo *start;
	nodo *end;
	nodo *cent;
	
	
	int size ;
	cola(){start=NULL;end=NULL;cent=NULL;size=0;}

	int ask_size(){return size;}
	bool ask_vacio(){
		if(start == NULL)
		{return true;}
		return false;
		}	
	void add_nodo(char dato)
	{
		cent=new nodo(dato);
		size++;
		if(start == NULL){
			start = cent;
			end =start;}
		else{
		end->sig =cent;
		cent->ant =end;		
		end =cent;		
		}
	}
	
	
	void get_dato()
	{
		cent=start;
		if (cent == NULL)
			{cout << "La cola esta vacia"<< endl;
			return ;}
		cout << cent->dato<<endl;
		start =cent->sig;
		delete cent;
	}
	nodo* find(char dato)
	{	nodo*out =NULL;
		out=start;
		while(out && out-> dato!=dato)
		{
			out =out->sig;
		}		
		return out;
	}
	
	void print_cola()
	{
	cent=start;
	if (cent == NULL)
			{cout << "La cola esta vacia"<< endl;
			return ;} 
	cout<<"ini ";
	while(cent->sig)
		{
		
		cout <<" "<<cent->dato << " " ; 
		cent =cent->sig;
		}
	cout <<" "<< end->dato<<endl;
	}
	
	cola operator+(cola b) {
	cola tmp ;
	cent=start;
	while(cent->sig)
		{
		
		tmp.add_nodo(cent->dato); 
		cent =cent->sig;
		}
	tmp.add_nodo(cent->dato); 
	cent=b.start;
	while(cent->sig)
		{
		
		tmp.add_nodo(cent->dato); 
		cent =cent->sig;
		}
	tmp.add_nodo(cent->dato);
	return tmp;
	}

	cola operator-(cola b) {
	cola tmp ;
	cent=start;
	while(cent->sig)
		{
		tmp.add_nodo(cent->dato); 
		cent =cent->sig;
		}
	tmp.add_nodo(cent->dato); 
	cent=b.start;
	while(cent)
		{
		if(tmp.find(cent->dato) == NULL)
			{//cout<<"no esta";
			tmp.add_nodo(cent->dato);
			}
		cent =cent->sig;
		}
	return tmp;
	}

};
