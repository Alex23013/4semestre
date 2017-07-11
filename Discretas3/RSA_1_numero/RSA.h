#include <iostream>
#include "funciones_RSA.h"
using namespace std;

class RSA
	{
	private:
		int p,q;
		int clave_priv;
	public:
		int clave_pub;
		int N;
		int phi;
		RSA(int p,int q){
			this->p=p;
			this->q=q;
			N=p*q;
			phi=(p-1)*(q-1);
			cout<<"N :"<<N<<endl;
			clave_pub=generar_clave_pub(phi);
			clave_priv=generar_clave_priv(clave_pub,phi);
			cout<<" C-pub: "<<clave_pub<<" C-priv: "<<clave_priv<<endl;
		}
		int cifrar(int letra,int clave_pub,int N_otro)
		{
			return exp_modular(letra,clave_pub,N_otro);
		}

		int descifrar(int cifrado)
		{
			return exp_modular(cifrado,clave_priv,N);
		}
	} ;
