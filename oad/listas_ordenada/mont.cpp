#include <iostream>
#include <time.h>
using namespace std;
int modulo(int a, int b)
{
    int mod = a - b * (a/b);
    if(mod >= 0)
    {
        return mod;
    }
    mod = mod + b;
    return mod;
}
int Mont_p1(int p,int a, int& k){
	int u=p;
	int v=modulo(a,p);
	int r=0;
	int s=1;
	int x=0;
	cout<<"INICIO-- u:"<<u<<" v:"<<v<<" s:"<<s<<" r: "<<r<<" K:"<<k <<endl;
	//k =0;

	while(v>0)
	{
    	if((u &1) ==0 )
    	    {u >>=1; s <<=1;}
    	else {
                if((v&1) ==0)
                    {v >>=1; r <<=1;}
                else {
                    x=(u-v);
                    if(x>0){
                    u=x>>=1;r=r+s;s<<=1;
                }
                else{
                v=-(x>>=1);s=s+r;r<<=1;
                }
            }}
    	k=k+1;
	}
    	 //  -- n <= k <= 2n
    	cout<<" u:"<<u<<" v:"<<v<<" s:"<<s<<" r: "<<r<<" K:"<<k <<endl;

	if(r >= p)
	{
	    r=r-p;
	}
	r=p-r;
	return r;
}


int Mont_p2(int r,int p, int & k) // phase 2 --n bits de p
{
    for(int i =1;i<=k;i++)
    {
        if(modulo(r,2) ==0)
        {
            r=r/2;
        }
        else
        {
            r=(r+p)/2;
        }
        //cout<<"R:"<<r<<endl;
    }
    return r;
}

int Mont_Tot(int a,int p)//Mont_Tot(aa,bb); int aa=23;   int bb=79;
{   clock_t tiempo = clock(); 
	int inversa;
	int  k =0;
	inversa=Mont_p1(p,a,k);
    cout<<"y fuera del looop"<<" K:"<<k <<endl;
    cout<<"almost: "<<inversa<<endl;
   // {inversa=modulo_int(inversa,p);}
	inversa = Mont_p2(inversa,p,k);

	cout<<"almost2: "<<inversa<<endl;
	cout << "extendido MONT time: " << (double(clock() - tiempo)/CLOCKS_PER_SEC) << endl;


	return inversa;
}
int la_inversa(int r1,int r2)
{   clock_t tiempo = clock();
	int s1=1;
	int s2=0;
	int r=0;
	int q=0;
	int x=0;
	int mod =r2;
	while(r2>0){
		q=r1/r2;//cout<<" q: "<<q<<endl;
		r=r1-q*r2;
		r1=r2;
		r2=r;

		x=s1-q*s2;
		//if(x<0 ){x=modulo(x,tam);}
		s1=s2;
		s2=x;
	}

	x=s1;
	if(x<0 ){x=modulo(x,mod);}
	cout << "extendido ORIGINAL time: " << (double(clock() - tiempo)/CLOCKS_PER_SEC) << endl;
	return x;

}
int main()
{
   //PRIMOS
   int aa=412;//puede ser cualquier numero
   int bb=261;//tiene que ser primo

// INVERSA MODULAR

    int respuesta;
	int x;
    respuesta = Mont_Tot(aa,bb);
    cout<<respuesta<<endl;
    x = la_inversa(aa,bb);
    cout<<"original"<<endl;
    cout<<x<<endl;
    if(x==respuesta){cout<<"ES IGUALL"<<endl;}

    return 0;
}
