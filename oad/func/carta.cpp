#include <iostream>
using namespace std;
class card
{
public:
	int num;

card(){num=0;}
card(int num){this-> num =num;}

void print_card()
{
cout << " ___  "<<endl;
cout << "|   | "<<endl;
cout << "| "<<num<<" | "<<endl;
cout << "| "<<"$"<<" | "<<endl;
cout << "|___| "<<endl;
}


};

/*
int main()
{
card a;
card b(3);
a.print_card();
b.print_card();

}*/
