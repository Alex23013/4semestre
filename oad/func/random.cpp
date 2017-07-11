#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std;
int random()
{
	srand((unsigned)time(0)); 
    int random_integer; 
    for(int index=0; index<20; index++){ 
        random_integer = (rand()%14)+1; 
        cout << random_integer << " "; 
    } 
}

int main() 
{ 
    random();
}
