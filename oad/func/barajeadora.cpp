
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include"mano.cpp"
using namespace std;

class baraja
{
private:
	mano baraj;
	
public:
	void print_baraj()
		{
			cout << "La baraja es: "	;		
			baraj.print_mano();
		}

	void barajar(){
	    int n_cartas=23;
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
	    for (int i = 0; i < n_cartas; i++) {
		baraj.add_card(arr[i]);
	    }
	}

	void dar_a_jugador(mano *a)
	{
		int pos=baraj.get_size()-1;
		a->add_card(1);
	}
	
	
};
 
int main()
{
	mano a;
	baraja baraj;
	for(int i=0;i<4;i++)
	{	baraj.random_cartas();}
	baraj.print_baraj();
	baraj.dar_a_jugador(&a);
	a.print_mano();
	cout <<"fff";
	   
   return 0;
}
