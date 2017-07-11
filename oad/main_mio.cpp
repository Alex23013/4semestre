
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include"pila.cpp"
#include"mano.cpp"
#include "baraja.cpp"
#include "card.cpp"

 
int main()
{
	mano a;
	baraja baraj;
	baraj.barajar();
	baraj.print_baraj();
	baraj.dar_a_jugador(&a);
	a.print_mano();
	cout <<"fff";
	   
   return 0;
}
