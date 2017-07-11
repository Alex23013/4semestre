using namespace std;
class pila
{
public:
	nodo *start;
	nodo *end;
	nodo *cent;
	
	
	int size ;

	pila(){start=NULL;end=NULL;cent=NULL;size=0;}

	int ask_size(){return size;}
	bool ask_vacio(){
		if(start == NULL)
		{return true;}
		return false;
		}	
	void add_nodo(char dato)
	{
		cent=new nodo(dato);
		size++;
		if(start == NULL){
			start = cent;
			end =start;}
		else{
		end->sig =cent;
		cent->ant =end;		
		end =cent;		
		}
	}
	
	
	void get_dato()
	{
		cent=end;
		if (cent == NULL)
			{cout << "La pila esta vacia"<< endl;
			return ;}
		cout << cent->dato<<endl;
		end =cent->ant;
		delete cent;
	}
	void print_pila()
	{
	cent=end;
	if (cent == NULL)
			{cout << "La pila esta vacia"<< endl;
			return ;} 
	while(cent->ant)
		{
		cout <<" "<<cent->dato<<endl; 
		cent =cent->ant;
		}
	cout <<" "<< start->dato<<endl;
	}
	

};
