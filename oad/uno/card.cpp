#include <iostream>

using namespace std;

class nodo{

public:
	int num;
	char color;
	nodo* sig;

nodo(int num,char color){ 
        sig = NULL;
	this-> num =num;
	this->color =color;}

void print_carta()
{
cout << " ___  "<<endl;
cout << "|   | "<<endl;
cout << "| "<<num<<" | "<<endl;
cout << "| "<<color<<" | "<<endl;
cout << "|___| "<<endl;
}

void print_nodo(){
cout<<num<<"("<<color<<") "<<" - ";
}
	char get_color(){
		return color;
	}
};


