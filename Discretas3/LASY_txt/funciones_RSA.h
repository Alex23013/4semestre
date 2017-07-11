#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int mod(int num,int mod)
{
	int r,q;
	q=num/mod;
	r=num-(mod*q);
	if(r<0){return r+mod;}
	return r;
}
int euclides(int A,int b)
{
	int q;
	int r;
	int mcd;
	r=mod(A,b);
	while(r>0){
		mcd=r;
		q=A/b;
		r=mod(A,b);
		A=b;
		b=r;
	}
	return mcd;
}

int extendido(int r1,int r2){
int s1=1;
	int s2=0;
	int r=0;
	int q=0;
	int x=0;
	while(r2>0){
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;

		x=s1-q*s2;
		s1=s2;
		s2=x;
	}
	x=s1;
	return x;
}
int la_inversa_modular(int r1,int r2,int tam)
{
    int x;
    x=extendido(r1,r2);
	if(x<0){x=mod(x,tam);}
	return x;
}

int ramdom(int top,int i)
{
	srand((unsigned)time(NULL));
	int d=rand()%top+i;
	return d;
}


int exp_modular(int a,int exp,int modulo){
	int result=1;
	while(exp>0){
		if(mod(exp,2)==1){
			result=mod(result*a,modulo);
		}
		a=mod(a*a,modulo);
		exp=exp/2;
	}
	return result;
}
