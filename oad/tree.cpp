#include<iostream>
using namespace std;

class nodo
{
  public:
  int info;
  nodo* hijo_izq;
  nodo* hijo_der;
  
  nodo(int info=0){
      this->info=info;
      this->hijo_izq= NULL;
      this->hijo_der=NULL;
    }
    

};

bool ascendente(int a,int b){
	//cout<<"por criterio ascendente: \n";
	if(a<b){return true;}
	else{return false;}
}
bool descendente(int a,int b){
	//cout<<"por criterio descendente: \n";
	if(a>b){return true;}
	else{return false;}
}

bool comparacion(bool (*p)(int,int), int info, int aux){
	if(p(info,aux)==true){
		return true;
	}
	else{
		return false;
	}
}
  
class Arbol
{
  public:
  nodo *start;
  
  Arbol(){
  this->start=NULL;
  }
  
  void add_nodo(int info){
     if(start == NULL){
      nodo *cent= new nodo(info);
      start=cent;
      }
      else
     {
       nodo *aux=start;
       nodo *cent= new nodo(info);
       while(aux->hijo_izq !=NULL && aux->hijo_der !=NULL)
         {
           if(comparacion(descendente,info,aux->info)==true){
             aux=aux->hijo_izq;
           }
           else{
           aux=aux->hijo_der;
           }
         }
        if(comparacion(descendente,info,aux->info)==true){
             aux->hijo_izq=cent;
           }
        else{
           aux->hijo_der=cent;
        }
         
     }
  }
  
  void print_nodo_inorden(nodo* yop){
    if(yop->hijo_izq ==NULL && yop->hijo_der ==NULL){
      cout<<yop->info<<endl;}
    else{
      //cout<<"tengo hijos"<<endl;
      if(yop->hijo_izq !=NULL){print_nodo_inorden(yop->hijo_izq);}
      if(yop->hijo_der !=NULL){cout<<yop->info<<endl;print_nodo_inorden(yop->hijo_der);}
     // cout<<yop->hijo_izq->info<<endl;
     // cout<<yop->hijo_der->info<<endl;
    }
  } 
  
  	void print_arbol(){
		if(start == NULL)
			{cout<<"El arbol esta vacio"<<endl;}
		else{
		 	cout<<"El arbol impreso  es: "<<endl;
		 	print_nodo_inorden(start);
		}
	}
	
};



int main(){
  cout<<"    ARBOLES BINARIOS   "<<endl;
  Arbol tree;
//tree.print_arbol();
  tree.add_nodo(15);
  for (int i=0;i<100000000;i++){
	tree.add_nodo(i);
}
 tree.add_nodo(10);
 tree.add_nodo(25);

 tree.add_nodo(14);
 tree.add_nodo(5);
 tree.add_nodo(18);
 tree.add_nodo(78);
tree.print_arbol();
  

}



 /*cout<<tree.start->info<<endl;
  cout<<tree.start->hijo_izq->info<<endl;
  cout<<tree.start->hijo_der->info<<endl;*/
  

