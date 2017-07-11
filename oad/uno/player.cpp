#include <iostream>
#include "baraja.cpp"
using namespace std;


class player
{	
	public:
		int turno;
		mano cartas;
		player(int turno=0){this->turno =turno;}
	bool win(){
	if(cartas.get_size() == 4){cout<<"\nGANASTE XD\n";return true;}
	return false;
	}

	void tirar_carta(int num, char color,mano* mesa){
		mesa->add_card(num,color);
		cartas.Mis_cartas.delete_nodo(num,color);		
	}
	
	void jugar(mano* mesa){	
	int pos_carta;
	char colo;	
	cout<<"Que carta desea colocar en mesa?\n";
	cout<<"\n numero:";cin>>pos_carta;
	cout<<"\t color:";cin>>colo;
	tirar_carta(pos_carta,colo,mesa);
	
	}
};


int main()
{
	cout<<"\n BIENVENIDOS\n";
	mano mesa;	
	baraja baraj;
	int cantidad=4;
	baraj.barajar();
	baraj.print_baraj();	
	player a(1);
	player b(2);
	player c(3);
	player d(4);
	for(int i =0;i<7;i++){baraj.dar_a_jugador(&a.cartas);}//a.cartas.print_mano();
	for(int i =0;i<7;i++){baraj.dar_a_jugador(&b.cartas);}//b.cartas.print_mano();
	for(int i =0;i<7;i++){baraj.dar_a_jugador(&c.cartas);}//c.cartas.print_mano();
	for(int i =0;i<7;i++){baraj.dar_a_jugador(&d.cartas);}//d.cartas.print_mano();
	int turno=1;
	while(a.win() ==false){
	cout<<"\nes el turno del jugador "<<turno<<":\n";	
	if(mesa.Mis_cartas.len_lista>=1){cout<<"LA mesa:";mesa.last_card();}
	else{cout<<"El juego acaba de iniciar\n";}	
//////////////////////	
	if(a.turno == turno){
		a.cartas.print_mano();
		int opt;
		cout<<"Que desea hacer? \n 1: jugar una carta \n 2: sacar una de la baraja";
		cin>>opt;
		if(opt ==1){a.jugar(&mesa);}
		if(opt ==2){baraj.dar_a_jugador(&a.cartas);}
		cout<<"ahora ";a.cartas.print_mano();
		//cout<<"\nsize: "<<a.cartas.Mis_cartas.len_lista<<endl;
	}
////////////////////
	turno ++;
	turno =turno %cantidad;	
	}
	
			
}
