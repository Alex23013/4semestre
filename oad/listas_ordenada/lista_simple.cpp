#include <iostream>
using namespace std;

class nodo
{
  public:
  int info;
  nodo*sig;
  nodo(int info=0)
    {
      this->info=info;
      sig=NULL;
    }
  };

class lista
{
  public:
  nodo *start;
  lista()
  {start=NULL;}
  
  void add_nodo(int info)
  {
    
    if(start == NULL){
      nodo *cent= new nodo(info);
      start=cent;
      }
    else
     {
       nodo *aux=start;
       while(aux->sig != NULL)
         {aux=aux->sig;}
       nodo *cent= new nodo(info);
       aux->sig = cent;
     }
  }

  void print_lista()
  {
    nodo *cent;
    cent=start;
    if(cent == NULL)
    {cout<<"La lista sta vacia"<<endl;return;}
    while(cent){
        cout<<cent->info;
        cout<<"-> ";
        cent =cent->sig;
    }
	cout<<endl;
  }
  
};

