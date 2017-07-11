
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include"mano.cpp"
using namespace std;

class baraja
{
private:
	lista baraj;

	
public:
	void print_baraj()
		{
			cout << "La baraja es: "	;		
			baraj.print_lista();
		}

	
	void barajar(){
	    int n_cartas=80;
	    srand(time(NULL));
	    int tmp;
	    int r;
	    int arr[n_cartas];
		for (int i = 0; i < n_cartas; i++) {
			arr[i]=i;
		    }   
		for(int i = 0; i < n_cartas; i++) {
			r = rand()%n_cartas;
			//cout<<"\nr: "<<r<<endl;
			tmp = arr[i];
			arr[i] = arr[r];
			arr[r] = tmp;
		    }
		char colores[4]={'B','Y','R','G'};
		int j=0;
		int mas_2;
		int salto_turno;
		    for (int i = 0; i < n_cartas; i++) {
			r = rand()%7;if(r==1 && mas_2 <8){baraj.add_nodo(2,'+');mas_2++;}
			baraj.add_nodo(arr[i],colores[j]);
			r = rand()%8;if(r==1 && salto_turno <8){baraj.add_nodo(0,'~');salto_turno++;}
			j++;j=j%4;    
			}
	}
	
	nodo* sacar_carta(int tope){
		nodo* cent=baraj.start;
		nodo* temp;
		int count =0;
		while(count != tope){
		//cent->print_carta();
		temp =cent;
		cent =cent->sig;
		count++;
	    	}
		
	return temp;
	}

	void dar_a_jugador(mano *a)
	{
		int pos=baraj.len_lista-2;
		if(pos<2){cout<<"se acabaron las cartas\n";baraj.len_lista =80;}
		nodo* del_top =sacar_carta(pos);
		a->add_card((del_top->num)%10,del_top->color);
		baraj.len_lista--;
		//del_top->print_carta();		
		
		/*int pos=baraj.len_lista-2;
		baraj.len_lista--;
		char color =		'a';
		//cout<<"\npos:"<<pos;
		a->add_card(baraj[pos%10],color);
		baraj.delete_nodo(baraj[pos]);*/
			
	}
	
	
};
/*
 
int main()
{
	mano a;
	baraja baraj;
	baraj.barajar();
	baraj.print_baraj();
	for(int i =0;i<8;i++){
		baraj.dar_a_jugador(&a);
	}
	
	a.print_mano();
	baraj.print_baraj();
   
   return 0;
}*/
