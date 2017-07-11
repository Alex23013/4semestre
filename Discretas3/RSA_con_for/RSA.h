#include <iostream>
#include "funciones_RSA.h"
#include <vector>
using namespace std;

class RSA
	{
	private:
		int p,q;
		int clave_priv;
	public:
		int clave_pub;
		string alfabeto;
		int tam;
		int N;
		int phi;
		RSA(int p,int q){
			alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,-_";
			this->p=p;
			this->q=q;
			tam=alfabeto.size();
			N=p*q;
			phi=(p-1)*(q-1);
			clave_pub=generar_clave_pub(phi,tam);
			clave_priv=generar_clave_priv(clave_pub,phi);
			cout<<"\n <K-pub,N>  <"<<clave_pub<<" , "<<N<<" >"<<endl;
		}
		void cifrar(string mensaje,int clave_pub,int N_otro,int tam,int* cifrado)
		{
		    //cout<<"elemntos a cifrar: "<<endl;
			for(int i=0;i< tam;i++){
				int found = alfabeto.find(mensaje[i]);
				//cout<<"("<<mensaje[i]<<")- "<<found<<" ";
				cifrado[i]=exp_modular(found,clave_pub,N_otro);
			}
		}

		string descifrar(int* cifrado,int tam)
		{
		    int original_vec[tam];
			for(int i=0;i< tam;i++){
				original_vec[i]=0;
			}
			string original;
			cout<<"\n descifrado: "<<endl;
			for(int i=0;i< tam;i++){
				//cout<<"riginal_vec[i]"<<original_vec[i]<<endl;
				original_vec[i]=(exp_modular(cifrado[i],clave_priv,N));
                original+=alfabeto[original_vec[i]];
                //cout<<"i: "<<i<<endl;
                //cout<<"cifrado riginal_vec[i]"<<alfabeto[original_vec[i]]<<endl;
				//cout<<alfabeto[i];
               }
			return original;
		}

	} ;
