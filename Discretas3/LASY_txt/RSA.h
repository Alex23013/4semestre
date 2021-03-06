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
		RSA(){//constructor del receptor
			this->p=3;
			this->q=21;
			N=p*q;
			phi=(p-1)*(q-1);
			clave_pub=generar_clave_pub(phi);
			clave_priv=generar_clave_priv(clave_pub,phi);
			cout<<"Receptor: "<<" < K-pub, N > "<<" < "<<clave_pub<<" , "<<N<<" > "<<endl;
		}


        RSA (int k_pub, int N){//constructor del emisor
        this->clave_pub= k_pub;
        this->N=N;
	cout<<"Emisor: "<<" < K-pub, N > "<<" < "<<clave_pub<<" , "<<N<<" > "<<endl;
        }

		int generar_clave_pub(int phi){
			int a=2;
			int i=0;
			while (euclides(a,phi)!=1){
				a=ramdom(phi,i);
				i++;
			}
			if(a>=phi){mod(a,phi);}
			return a;
		}
		int generar_clave_priv(int clave_pub,int N){
			return la_inversa_modular(clave_pub,N,N);
		}
		int cifrar(int letra)
		{
			return exp_modular(letra, clave_pub, N);
		}

		int descifrar(int cifrado)
		{
			return exp_modular(cifrado,clave_priv,N);
		}
	} ;
