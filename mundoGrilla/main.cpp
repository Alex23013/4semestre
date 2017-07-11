
#include "miniwin.h"
using namespace std;
using namespace miniwin;


#include "grilla.h"

void pintar_casillero(int col,int x, int y,int lado_c){
color(col);
for(int i=(y*lado_c)+lado_c;i<(y*lado_c)+2*lado_c;i++){
    for(int j=(x*lado_c)+lado_c;j<(x*lado_c)+2*lado_c;j++){
        punto(i,j);
    }
}
refresca();
}

void pintar_grilla(int lado_c,int n_filas,int col){
    for(int i=1;i<n_filas+1;i++){
        linea(lado_c,lado_c*i,lado_c*n_filas,lado_c*i);//inix_ iniy _x_fin y y_fin
        linea(lado_c*i,lado_c,lado_c*i,lado_c*n_filas);
        if(lado_c%lado_c==0){color(col);punto(lado_c*i,lado_c*i);}
    }

}
//0 -1-2-3-4-5-6-7
// NEGRO, ROJO, VERDE, AZUL, AMARILLO, MAGENTA, CYAN y BLANCO
int main() {
    Grilla TC;
    TC.CreceHierba();
    int lado_c=7;
    int n_filas=100;
   vredimensiona(1100, 1100);
   pintar_grilla(lado_c,n_filas,3);

   rectangulo(800, 100, 1000, 200);
   refresca();

    color(BLANCO);
    if(pregunta("\tDesea iniciar? ")){
            rectangulo(800, 300, 1000, 400);
            texto(830, 140 , "MUNDO GRILLA");
            texto(830, 340, "\tACTUALIZAR");
            if(TC.VerCasilla(1,1)=='a'){pintar_casillero(MAGENTA,10,10,lado_c);}else{pintar_casillero(BLANCO,10,10,lado_c);}
    refresca();
    }else{
        texto(830, 142, "salir");
    }

    espera(1000);
    while(raton_dentro()){
        float x;
        float y;
        raton(x,y);
        if(x>830 &&x<972 && y >340 && y<500){
               //for(int i=0;i<5;i++){pintar_casillero(VERDE,i,i+1,lado_c);espera(500);}
               //pintar_casillero(MAGENTA,3,5,lado_c);
               //pintar_casillero(BLANCO,3,1,lado_c);
               for(int i=0;i<100;i++){
                    for(int j=0;j<100;j++){
                        int co = TC.VerYerba(i,j);
                        pintar_casillero(co,i,j,lado_c);
                    }
                }
        }
    }
    return 0;
}

