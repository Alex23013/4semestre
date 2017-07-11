//template<typename T>
class nodo
{
public:
	char dato;
	nodo *sig;
	nodo *ant;

nodo(char datos)
	{
	this->dato=datos;
	sig=NULL;
	ant=NULL;
	}

void add_dato(char dato){this->dato=dato;}
};
