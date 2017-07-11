
#include <iostream>
#include <algorithm>  
#include <vector> 
#include <math.h>

using namespace std;

int stringToNumber(string str)
{
    int number,diez;
    int temp;
    long j=str.length()-1;
    diez=2;
    for(int i = 0; i < str.length(); i++)
    {
        temp=str[i]-48;
        number+=temp*pow (10,j-i);
    }

    return number;
}
bool myfunction (int i,int j) { return (i>j); }

int petya(int top,string cm){
cout<<"\ncm: "<<cm;
cout<<"\ntop: "<<top<<endl;
int min;
int total;
int len_cm=cm.length();
cout<<len_cm<<"\n";
vector<int> myvector;
for(int i=0;i<len_cm;i++){
	string num;
	int tmp;
	if(cm[i] != ' '){
		num=num+cm[i];
		if(cm[i+1] != ' ') 
			{num+=cm[i+1];}
		else if(cm[i+2] == '0' && cm[i+1] == '0' && cm[i] == '1') 
			{num+=cm[i+2];i+=2;}
		cout<<" n: "<<num<<"\n";
		tmp=stringToNumber(num);
		myvector.push_back(tmp);}
	//else{cout<<";";}
}
for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    cout << ' ' << *it;
cout<<"\n";
sort (myvector.begin(), myvector.end(),myfunction);
for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    cout << ' ' << *it;

return min;
}

int main(){
cout<<"Hello\n";
string pal="1 2 32 7 100 32 2 3 1 1 2 5";

petya(4,pal);
}
