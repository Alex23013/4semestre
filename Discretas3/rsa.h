#include <iostream>
using namespace std;

class rsa{
private:
	int p,q;
	int k_priv;
public:
	int k_pub;
	int n;
	int phi_n;

	rsa(){
		cout<<"\n objeto YO creado \n ";
		p=23;
		q=17;
		k_pub =generar_k_pub();
		n=p*q;
		phi_n=(p-1)*(q-1);
		k_priv;//=inversa_modular();
		
	}
	
	rsa(int k_pub,int n){
		this->k_pub=k_pub;
		this->n=n;
		cout<<"\nobjeto cifrador creado\n";
	}

	int generar_K_priv();
	int generar_k_pub();
	int cifrar(int mensaje);
	int descifrar(int cifrado);
};
