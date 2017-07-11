#include <iostream>
#include<stdlib.h>
using namespace std;

class Juego{
public:
    char  tablero [3][3][3];

    Juego(char casillero){
        int i,j,k;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                   *(*(*(tablero+i)+j)+k)=casillero;
                }
            }
        }
    }

    void print_tablero(){
      //  system("cls");
        int i,j,k;
        for(i=0;i<3;i++){
            cout<<"\n capa " <<i+1 <<"\n";
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                    cout<<*(*(*(tablero+i)+j)+k);
			if(k<2){cout<<" | ";}
                }
                cout<<endl;
		if(j<2){cout<<"---------\n";}
            };
        }
    }

    void jugar(int x,int y, int z, char ficha){
           // tablero[x][y][z]=ficha;
		*(*(*(tablero+x)+y)+z)=ficha;
    }

    bool win(int x,int y, int z, char ficha){
	if(*(*(*(tablero+x)+y)+z)==ficha && *(*(*(tablero+x+1)+y)+z)==ficha && *(*(*(tablero+x+2)+y)+z)==ficha)
	{return true;}
	else{return false;}
	}

};


int main(){
	Juego A(' ');
	char jug_1='X';
	char jug_2='O';
	int clock =0;
	A.print_tablero();
	while(clock<27){
	char jug;
	
	if((clock&1)==0){jug=jug_2;}else{jug=jug_1;}
	cout<<"Es el turno de : "<<jug;
	int x,y,z;
	cout<<" Ingrese sus coordenadas (x,y,z) \n";
	cin>>x;
	cin>>y;
	cin>>z;
	A.jugar(x,y,z,jug);
	A.print_tablero();
	if(A.win(x,y,z,jug)){cout<<"Ganaste jugador "<<jug<<endl;}
	else{cout<<"sigue intentando"<<endl;}
	clock++;
	}
	cout<<"NADIE gano XD \n";
	return 0;
}
