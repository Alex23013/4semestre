
#include<iostream>
#include <cstdlib>

#include <NTL/ZZ.h>
#include <ctime>
using namespace std;
using namespace NTL;
ZZ mod(ZZ num,ZZ mod)
{
	ZZ r,q;
	q=num/mod;
	r=num-(mod*q);
	if(r<0){return r+mod;}
	return r;
}

ZZ mod_int(ZZ num,int mod)
{
	ZZ r,q;
	q=num/mod;
	r=num-(mod*q);
	if(r<0){return r+mod;}
	return r;
}

ZZ euclides(ZZ A,ZZ b)
{
	ZZ q;
	ZZ r;
	ZZ mcd;
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

ZZ extendido(ZZ r1,ZZ r2){
    ZZ s1=to_ZZ("1");
	ZZ s2=to_ZZ("0");
	ZZ r=to_ZZ("0");
	ZZ q=to_ZZ("0");
	ZZ x=to_ZZ("0");
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
ZZ la_inversa_modular(ZZ r1,ZZ r2,ZZ tam)
{
    ZZ x;
    x=extendido(r1,r2);
	if(x<0){x=mod(x,tam);}
	return x;
}

ZZ ramdom(ZZ top,ZZ i)
{
	srand((unsigned)time(NULL));
	ZZ d=RandomBnd(top)+i;
	return d;
}


ZZ exp_modular(ZZ a,ZZ exp,ZZ modulo){
	ZZ result=to_ZZ("1");
	while(exp>0){
		if(mod_int(exp,2)==1){
			result=mod(result*a,modulo);
		}
		a=mod(a*a,modulo);
		exp=exp/2;
	}
	return result;
}
