#include <iostream>
#include<stdlib.h>
using namespace std;


int ternas[45][3][3]={
	{{0,0,0},{1,1,1},{2,2,2}},{{0,0,2},{1,1,1},{2,2,0}},{{0,2,2},{1,1,1},{2,0,0}},
	{{0,2,0},{1,1,1},{2,0,0}},{{0,0,1},{1,1,1},{2,2,1}},{{0,1,2},{1,1,1},{2,1,0}},
	{{0,2,1},{1,1,1},{2,0,1}},{{0,1,0},{1,1,1},{2,1,2}},{{0,1,1},{1,1,1},{2,1,1}},
	{{0,0,0},{0,0,1},{0,0,2}},{{0,1,0},{0,1,1},{0,1,2}},{{0,2,0},{0,2,1},{0,2,2}},
	{{0,0,0},{0,1,0},{0,2,0}},{{0,0,1},{0,1,1},{0,2,1}},{{0,0,2},{0,1,2},{0,2,2}},

	{{0,0,2},{0,1,1},{0,2,0}},{{0,0,0},{0,1,1},{0,2,2}},{{1,0,1},{1,1,1},{1,2,1}},
	{{1,1,0},{1,1,1},{1,1,2}},{{1,0,0},{1,1,1},{1,2,2}},{{1,0,2},{1,1,1},{1,2,0}},
	{{1,0,0},{1,1,0},{1,0,2}},{{1,2,0},{1,2,1},{1,2,2}},{{1,0,0},{1,1,0},{1,2,0}},
	{{1,0,2},{1,1,2},{1,2,2}},{{2,0,0},{2,0,1},{2,0,2}},{{2,1,0},{2,1,1},{2,1,2}},
	{{2,2,0},{2,2,1},{2,2,2}},{{2,0,0},{2,1,0},{2,2,0}},{{2,0,1},{2,1,1},{2,2,1}},

	{{2,0,2},{2,1,2},{2,2,2}},{{2,0,0},{2,1,1},{2,2,2}},{{2,0,2},{2,1,1},{2,2,0}},
        {{0,0,0},{1,0,1},{2,0,2}},{{0,0,2},{1,0,1},{2,0,0}},{{0,0,1},{1,0,1},{2,0,1}},
	{{0,0,2},{1,1,2},{2,2,2}},{{0,2,2},{1,1,2},{2,0,2}},{{0,1,2},{1,1,2},{2,1,2}},
	{{0,2,0},{1,2,1},{2,2,2}},{{0,2,2},{1,2,1},{2,2,0}},{{0,2,1},{1,2,1},{2,2,1}},
	{{0,0,0},{1,1,0},{2,2,0}},{{0,2,0},{1,1,0},{2,0,0}},{{0,1,0},{1,1,0},{2,1,0}},};


//int terna[3]={1,2,2};
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
	//cout<<"\nternas: "<<ternas[0][0]<<endl;
	//cout<<"\nternas: "<<ternas[0][1]<<endl;
	//cout<<"\nternas: "<<ternas[0][2]<<endl;
	//if("111"==ternas[0][1]){cout<<"\yes\n";}else{cout<<"NO\n";}
       
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
            }
        }
    }

	void print_cara(int a){
	int j,k;
	cout<<"1   2   3 \n";
	for(j=0;j<3;j++){
		if(j>0)cout<<j+1<<" ";
		else{cout<<"  ";}
                for(k=0;k<3;k++){
                    cout<<*(*(*(tablero+a)+j)+k);
			if(k<2){cout<<" | ";}
                }
                cout<<endl;
		if(j<2){cout<<"-----------\n";}
            }
        }


    void poner_ficha(int x,int y, int z, char ficha){
           // tablero[x][y][z]=ficha;
		if(*(*(*(tablero+x)+y)+z)==' '){
			*(*(*(tablero+x)+y)+z)=ficha;}
		else{
		cout<<"Ya esta ocupado este casillero\n intenta con otro casillero\n";jugar(ficha);}
   	 }
	
	void jugar(char ficha){
		cout<<"Es el turno de : "<<ficha;
		int x,y,z;
		cout<<" Elija una capa \n";
		cin>>x;
		print_cara(x-1);
		cout<<"Escoja un x,y : \n";
		cin>>y;
		cin>>z;
		poner_ficha(x-1,y-1,z-1,ficha);
		print_tablero();
		if(win(ficha,x-1,y-1,z-1) == true){cout<<" jugador: "<<ficha<<" gano\n";}
		else{cout<<"Sigamos jugando\n";}
	}

	bool win(char ficha,int x,int y, int z){
		for(int i =0;i<45;i++){
			for(int j=0;j<3;j++){
				
				if(*(*(*(ternas+i)+j)+0)==x && *(*(*(ternas+i)+j)+1)==y &&*(*(*(ternas+i)+j)+2)==z)			
				{
					cout<<"*(*(*(ternas+i)+j)+0): "<<*(*(*(ternas+i)+j)+0)<<" x "<<x<<endl;
					cout<<"*(*(*(ternas+i)+j)+1): "<<*(*(*(ternas+i)+j)+1)<<" y "<<y<<endl;
					cout<<"*(*(*(ternas+i)+j)+2): "<<*(*(*(ternas+i)+j)+2)<<" z "<<z<<endl;
					if(j==0 && *(*(*(tablero+i)+j)+1)==ficha && *(*(*(tablero+i)+j)+2)==ficha){return true;}
					cout<<"j: "<<j<<"  "<<*(*(*(tablero+i)+j)+1)<<" == "<<ficha;
					if(j==1 && *(*(*(tablero+i)+j)+0)==ficha && *(*(*(tablero+i)+j)+2)==ficha){return true;}
					if(j==2 && *(*(*(tablero+i)+j)+0)==ficha && *(*(*(tablero+i)+j)+1)==ficha){return true;}
				}
			}
		}
		return false;	
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
	A.jugar(jug);
	clock++;
	}
	cout<<"NADIE gano XD \n";
	return 0;
}
