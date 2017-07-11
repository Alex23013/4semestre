#include <iostream>
#include "card.cpp"
using namespace std;

int one=1;
class lista
{public:
	int num;//es el turno del player
};
class lista_player:public lista
{
public:	
	mano cartasxjugar;
	bool win;
	nodo* start;
	int len_lista;

	lista_player(int num=0){this->num =num;}
	bool win(){
	if(cartasxjugar.get_size() ==0){return true;}
	return false;
	}

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

};

class lista_cartas:public lista
{
public:
	nodo* start;
	int len_lista;
	char color;


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


	void delete_nodo(int dato){
	//cout<<"\ndato a borrar:"<<dato<<endl;
		nodo* aux=start;
		nodo* elsig=NULL;
		if(esta_nodo(dato)){
			nodo* aborrar=find_nodo(dato);
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

  bool esta_nodo(int dato){

        nodo* temp=start;
        while(temp){
                if(temp->num == dato){return true;}
            temp=temp->sig;
        }
        return false;
    }

   nodo* find_nodo(int dato){
        nodo* temp=start;
        while(temp){
                if(temp->num == dato){return temp;}
            temp=temp->sig;
        }
    }
};



