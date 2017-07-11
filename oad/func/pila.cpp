#include<iostream>
#include "card.cpp"
using namespace std;


class pila
{
public:
	nodo *start;
	nodo *end;
	nodo *cent;


	int size ;

	pila(){start=NULL;end=NULL;cent=NULL;size=0;}

	int ask_size(){return size;}
	bool ask_vacio(){
		if(start == NULL)
		{return true;}
		return false;
		}
	void add_nodo(int num, char color)
	{
		cent=new nodo(num,color);
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


	void delete_num()
	{
		cent=end;
		if (cent == NULL)
			{cout << "La pila esta vacia"<< endl;
			return ;}
		//cout << cent->num<<endl;
		end =cent->ant;
		delete cent;
	}

	int get_num(){
		cent=end;
		return cent->num;

	}

	void print_pila()
	{
	cent=end;
	if (cent == NULL)
			{cout << "La pila esta vacia"<< endl;
			return ;}
	while(cent->ant)
		{
		cout <<" "<<cent->num<<endl;
		cent =cent->ant;
		}
	cout <<" "<< start->num<<endl;
	}


};

/*
int main(){
 pila AA;
 AA.print_pila();
 for(int i =2;i<23;i=i+5){
    AA.add_nodo(i);
 }
 AA.print_pila();
 cout<<"\n size de la pila "<<AA.ask_size()<<endl;
 cout<<"\n si se atendio al nodo: "<<AA.get_num()<<endl;
 //solo se ve el ultimono se borra
 AA.print_pila();
 cout<<"\n si borramos un num:\n ";
 AA.delete_num();
 AA.print_pila();
 nodo* result=AA.start;
 cout<<"\nel nodo inicio contiene "<<result->num<<endl;
 }*/

