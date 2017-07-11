#include<iostream>
#include <cstdlib>
#include <NTL/ZZ.h>
#include <string.h>
#include <sstream>
#include <ctime>
using namespace std;
using namespace NTL;

ZZ stringToNumber(string str)
{
    ZZ number,diez;
    int temp;
    long j=str.length()-1;
    diez=2;
    for(int i = 0; i < str.length(); i++)
    {
        temp=str[i]-48;
        number+=temp*power(diez,j-i);
    }

    return number;
}


string ZZ_to_string(ZZ n){

    stringstream bufer;
    bufer<<n;
    return bufer.str();
}
ZZ modu(ZZ num,ZZ mod)
{
	ZZ r,q;
	q=num/mod;
	r=num-(mod*q);
	if(r<0){return r+mod;}
	return r;
}
ZZ modu_con_int(ZZ num,int mod)
{
	ZZ r,q;
	q=num/mod;
	r=num-(mod*q);
	if(r<0){return r+mod;}
	return r;
}
ZZ exp_modular_int(ZZ a,int exp,ZZ modulo){
	ZZ result=to_ZZ("1");
	while(exp>0){
		if((exp&1)==1){
			result=modu(result*a,modulo);
			//cout<<"1";
		}
		a=modu(a*a,modulo);
		//cout<<"a:"<<a;
		exp>>=1;
		//cout<<" result:"<<result<<endl;
	}
	return result;
}
ZZ exp_modular(ZZ a,ZZ exp,ZZ modulo){
	ZZ result=to_ZZ("1");
	while(exp>0){
		if((exp&1)==1){
			result=modu(result*a,modulo);
		}
		a=modu(a*a,modulo);
		exp=exp/2;
	}
	return result;
}

ZZ blum(int bits,ZZ seed){

    ZZ p=to_ZZ("199");
    ZZ q=to_ZZ("17651618741475280279");
    cout<<"p: "<<p<<endl;cout<<"q: "<<q<<endl;
    ZZ Xo=seed;//to_ZZ("317");
    ZZ n=p*q;
   // cout<<"n: "<<n<<endl;
    string aleatorio;//(bits,'0');
    for(int i=0;i<bits-1;i++){
        string bit =ZZ_to_string(Xo&1);
        aleatorio+=bit;
        Xo=exp_modular_int(Xo,2,n);
        //cout<<"Xo"<<i <<" es: "<<Xo<<" \n";

    }
    aleatorio+='1';

    cout<<"bits_aleatorio: "<<aleatorio<<endl;

    ZZ number_aleatorio=stringToNumber(aleatorio);
   // cout<<"end 5? "<<number_aleatorio<<endl;
    //if(modu_con_int(number_aleatorio,5)==0){number_aleatorio=blum(bits,seed+13);}
    cout<<"number_aleatorio "<<number_aleatorio<<endl;
    return number_aleatorio;
}
ZZ mod_long(long nu,ZZ mod)
{
	ZZ r,q;
	ZZ num =to_ZZ(nu);
	q=num/mod;
	r=num-(mod*q);
	if(r<0){return r+mod;}
	return r;
}
bool Fermat(ZZ p,int iterations){
    if(p == 1){ // 1 isn't prime
        return false;
    }
    for(int i=0;i<iterations;i++){
        // choose a random integer between 1 and p-1 ( inclusive )
        srand((unsigned)time(NULL));
        ZZ a = mod_long(rand()+37*i,(p-1)+1);
        cout<<"a "<<a<<endl;
        // modulo is the function we developed above for modular exponentiation.
        //if(modulo(a,p-1,p) != 1){
        if(exp_modular(a,p-1,p) != 1){
            return false; /* p is definitely composite */
        }
    }
    return true; /* p is probably prime */
}
ZZ my_random(int bits){

   // ZZ seed =to_ZZ("9889970276666040779");
    ZZ seed;
    GenPrime(seed,8);
    seed=seed+(unsigned)time(NULL);
    //cout<<"seed "<<seed<<endl;
    ZZ p=blum(bits,seed);
    while(Fermat(p,5)== false){ GenPrime(seed,8);
    seed=seed+(unsigned)time(NULL);p=blum(bits,seed);cout<<"buscando \n";}
    //cout<<"primo"<<endl;
    return p;
}

int main()
{
    ZZ resultado;
    //resultado=blum(64);
    //cout<<"resultado "<<resultado<<endl;
    cout<<"RANDOM ALEX \n";
    resultado=my_random(64);
    cout<<"resultado "<<resultado<<endl;
}

/*
    int phi_n=(p-1)*(q-1);

    cout<<"phi_n: "<<phi_n<<endl;

    int exp=7;//su inversa es 103
	cout<<"la nversa "<<la_inversa(exp,phi_n)<<endl;
	int exp2=la_inversa(exp,phi_n);//la iversa//103
	cout<<exp2<<endl;
*/
