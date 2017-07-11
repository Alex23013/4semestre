#include <iostream>

#include <NTL/ZZ.h>
#include "funciones_RSA.h"
using namespace std;

using namespace NTL;

class RSA
	{
	private:
		ZZ p,q;
		ZZ clave_priv;
	public:
		ZZ clave_pub;
		ZZ N;
		ZZ phi;
		RSA(){//constructor del receptor
			this->p=3;
			this->q=7;
			N=p*q;
			phi=(p-1)*(q-1);
			clave_pub=generar_clave_pub(phi);
			clave_priv=generar_clave_priv(clave_pub,phi);
			cout<<" < K-pub, N > "<<" < "<<clave_pub<<" , "<<N<<" > "<<endl;
		}


        RSA ( ZZ k_pub, ZZ N){//constructor del emisor
        this->clave_pub= k_pub;
        this->N=N;
        }

		ZZ generar_clave_pub(ZZ phi){
			ZZ a=to_ZZ("2");
			ZZ i=to_ZZ("0");
			while (euclides(a,phi)!=1){
				a=ramdom(phi,i);
				i++;
			}
			if(a>=phi){mod(a,phi);}
			return a;
		}
		ZZ generar_clave_priv(ZZ clave_pub,ZZ N){
			return la_inversa_modular(clave_pub,N,N);
		}
		ZZ cifrar(ZZ letra)
		{
			return exp_modular(letra, clave_pub, N);
		}

		ZZ descifrar(ZZ cifrado)
		{
			return exp_modular(cifrado,clave_priv,N);
		}
	} ;
