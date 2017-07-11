#include <iostream>
#include "card.cpp"
using namespace std;

class lista{
public:
    nodo* start;

    int len_lista;

    lista(){start=NULL;len_lista=0;}

    void add_nodo(int num,char color){


        if(start == NULL){
                nodo* cent =new nodo(num,color);
                start=cent;
                len_lista++;
        }
        else{
                  nodo* aux=start;
            while(aux->sig != NULL){aux=aux->sig;}
            nodo* cent =new nodo(num,color);
            aux->sig=cent;
            len_lista++;
        }
    }

	void delete_nodo(int dato,char color){
	//cout<<"\ndato a borrar:"<<dato<<endl;
		nodo* aux=start;
		nodo* elsig=NULL;
		if(esta_nodo(dato,color)){
			nodo* aborrar=find_nodo(dato,color);
			if(aborrar == aux){
				elsig=aux->sig;
				delete aux;
				start=elsig;}
			else{
				while(aux->sig != NULL)
					{if(aborrar==aux->sig){
						aux->sig=aux->sig->sig;
						delete aborrar;

						}
					aux=aux->sig;}
			}
		}

		else{cout<<"el nodo "<<dato<<" no esta  en la lista\n";}
		len_lista--;
	}


  void print_lista()
  {
	cout<<" \n";
    nodo *cent;
    cent=start;
    if(cent == NULL)
    {cout<<"La lista sta vacia :/";}// tiene "<<len_lista<<" elementos"<<endl;return;}
    while(cent){
        //cent->print_carta();
	cent->print_nodo();
        cent =cent->sig;
    }
  //  cout<<": tiene "<<len_lista<<" elementos"<<endl;
	cout<<endl;
  }

  bool esta_nodo(int dato, char color){

        nodo* temp=start;
        while(temp){
                if(temp->num == dato && temp->color ==color){return true;}
            temp=temp->sig;
        }
        return false;
    }

   nodo* find_nodo(int dato, char color){
        nodo* temp=start;
        while(temp){
                if(temp->num == dato && temp->color ==color){return temp;}
            temp=temp->sig;
        }
    }

	int operator [](int i){
	if(i>len_lista-1){cout<<"ERROR: indice inexistente\n";return 0;}
	int count =0;
	nodo* temp =start;
	while(temp){
		if(count ==i){return temp->num;}
		temp=temp->sig;
		count++;
		}
	}
};
/*
int main()
{
    lista numeros;
    numeros.print_lista();
    for(int i =0;i<12;i++){
        numeros.add_nodo(i);
    }
    numeros.print_lista();

for(int i =1;i<12;i=i+3){

numeros.delete_nodo(i);
numeros.print_lista();}

numeros.delete_nodo(0);
numeros.print_lista();

numeros.delete_nodo(34);
numeros.print_lista();


numeros.delete_nodo(8);
numeros.print_lista();
cout<<numeros[0]<<endl;
return 0;
} */
