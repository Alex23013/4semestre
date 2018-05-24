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
	cout<<" 1   2   3 \n";
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
		if(*(*(*(tablero+x)+y)+z)==' '){
			*(*(*(tablero+x)+y)+z)=ficha;}
		else{
		cout<<"Ya esta ocupado este casillero\n intenta con otro casillero\n";jugar(ficha);}
   	 }
	
	bool jugar(char ficha){
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
		if(win(ficha,x-1,y-1,z-1) == true){cout<<" jugador: "<<ficha<<" ganó\n";return true;}
		else{cout<<"Sigamos jugando\n";return false;}
	}

	bool win(char ficha,int x,int y, int z){
		for(int i =0;i<45;i++){
			for(int j=0;j<3;j++){
				
				if(*(*(*(ternas+i)+j)+0)==x && *(*(*(ternas+i)+j)+1)==y &&*(*(*(ternas+i)+j)+2)==z)			
				{
				
				
					cout <<"terna a evaluar "<<i<<":\t";
					
					if(j==0 ){
					cout<<"es 0 elem ter ";
					int xx =ternas[i][1][0];
				  int yy =ternas[i][1][1];
				  int zz =ternas[i][1][2];
				  cout<<" 1elTer:  "<<xx<<","<<yy<<","<<zz<<"}\t";
				  int xxx =ternas[i][2][0];
				  int yyy =ternas[i][2][1];
				  int zzz =ternas[i][2][2];
				  cout<<" 2elTer:   "<<xxx<<","<<yyy<<","<<zzz<<"}\n";
				  			  
				  if(tablero[xx][yy][zz]== ficha && tablero[xxx][yyy][zzz]== ficha ){return true;}
          }
					
					if(j==1){
					cout<<"es 1 elem ter ";
					int xx =ternas[i][0][0];
				  int yy =ternas[i][0][1];
				  int zz =ternas[i][0][2];
				  cout<<" 0elTer:  "<<xx<<","<<yy<<","<<zz<<"}\t";
				  int xxx =ternas[i][2][0];
				  int yyy =ternas[i][2][1];
				  int zzz =ternas[i][2][2];
				  cout<<" 2elTer:   "<<xxx<<","<<yyy<<","<<zzz<<"}\n";
				  			  
				  if(tablero[xx][yy][zz]== ficha && tablero[xxx][yyy][zzz]== ficha ){return true;}
					}
					
					if(j==2){
					cout<<"es 2 elem ter ";
					int xx =ternas[i][1][0];
				  int yy =ternas[i][1][1];
				  int zz =ternas[i][1][2];
				  cout<<" 1elTer:  "<<xx<<","<<yy<<","<<zz<<"}\t";
				  int xxx =ternas[i][0][0];
				  int yyy =ternas[i][0][1];
				  int zzz =ternas[i][0][2];
				  cout<<" 0elTer:   "<<xxx<<","<<yyy<<","<<zzz<<"}\n";
				  			  
				  if(tablero[xx][yy][zz]== ficha && tablero[xxx][yyy][zzz]== ficha ){return true;}
					}
					
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
	
	bool flagAlguienGana = false;
    
  	
	while(!flagAlguienGana && clock <27){
	char jug;
	if((clock&1)==0){jug=jug_2;}else{jug=jug_1;}
	flagAlguienGana =A.jugar(jug);
	clock++;
	}
	if(!flagAlguienGana) {cout<<"NADIE ganó XD \n";}
	return 0;
}
