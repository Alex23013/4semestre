#include<iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void print(vector<int> cifrado){
    cout<<"es: ";
	for(vector<int> ::iterator it=cifrado.begin();it!=cifrado.end();++it){
		cout<<" "<<*it;
	}
	cout<<endl;
}

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
	//cout<<"r: "<<r<<endl;
	while(r>0){
		mcd=r;
		q=A/b;
		r=mod(A,b);
		//cout<<A<<"="<<q<<"*"<<b<<"+"<<r<<endl;
		A=b;
		b=r;
	}
	return mcd;
}

int la_inversa(int r1,int r2,int tam)
{
	int s1=1;
	int s2=0;
	int r=0;
	int q=0;
	int x=0;
	while(r2>0){
		q=r1/r2;//cout<<" q: "<<q<<endl;
		r=r1-q*r2;
		r1=r2;
		r2=r;

		x=s1-q*s2;
		s1=s2;
		s2=x;
		//cout<<" r: "<<r<<" r1: "<<r1<<" r2: "<<r2<< "   "<<" x: "<<x<<" s1: "<<s1<<" s2: "<<s2<<"   "<<endl;
	}
	x=s1;
	if(x<0){x=mod(x,tam);}
	return x;
}

int ramdom(int top,int i)
{
	srand((unsigned)time(NULL));
	int d=rand()%top+i;
	return d;
}

int generar_clave_pub(int phi,int tam){
	int a=2;
	int i=0;
	while (euclides(a,phi)!=1 ){
		a=ramdom(phi,i);
		//cout<<"pMCD"<<euclides(a,phi);
		i++;
	}
	if(a>=phi){mod(a,phi);}
	//if(a>=tam){mod(a,tam);}
	return a;
}
int generar_clave_priv(int clave_pub,int N){
	int c;
	c=la_inversa(clave_pub,N,N);
	return c;
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
