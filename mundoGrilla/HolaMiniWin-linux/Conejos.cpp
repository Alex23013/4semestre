#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <random>
#include <algorithm>
#include <utility>
#include <map>
#include "Cliente.cpp"

using namespace std;

struct Grilla {
	char animal;
	int hierba;
	Grilla() {
		animal = 'v';
		hierba = 0;
	}
};

class Conejo {
public:
  Conejo(int xx,int yy);
  int px,py;
  int energia;
  int edad;
  void movimiento(vector<vector<Grilla> >& world);
  Grilla* contenidoLat(int movX, int movY, vector<vector<Grilla> >& world);
  vector<pair<int, int> >laterales(vector<vector<Grilla> >& world);
};

Conejo::Conejo(int xx, int yy) {
  this->px = xx;
  this->py = yy;
  this->energia = 3;
  this->edad = 0;
}

Grilla* Conejo::contenidoLat(int movX, int movY, vector<vector<Grilla> >& world) {
  //Cuando sale de los límites de la matriz:
  if (this->px + movX < 0 or this->px + movX > world.size() or this->py + movY < 0 or this->py + movY > world[0].size()) {
    return nullptr;
  }
  else {
    return &(world[px + movX][py + movY]);
  }
}
vector<pair<int, int> > Conejo::laterales(vector<vector<Grilla> >& world) {
  Grilla* ptr;
  vector<pair<int, int> > movs;
  bool hayZ = 0;
  Grilla* up = contenidoLat(1, 0, world);
  Grilla* down = contenidoLat(-1, 0, world);
  Grilla* right = contenidoLat(0, 1, world);
  Grilla* left = contenidoLat(0, -1, world);
  Grilla* downR = contenidoLat(1, 1, world);
  Grilla* downL = contenidoLat(1, -1, world);
  Grilla* upR = contenidoLat(-1, 1, world);
  Grilla* upL = contenidoLat(-1, -1, world);

  //Si está vacío: puede moverse ahí
  //Si hay un zorro: escapa a posición contraria y solo acepta más entradas si también hay z
  if (up) {
    if (!hayZ and up->animal == 'v' )
      movs.push_back(make_pair(1, 0));
    else  if (up->animal == 'z' and down and down->animal == 'v') {
      movs.push_back(make_pair(-1, 0));
      hayZ = 1;
    }
  }

  if (down) {
    if (!hayZ and down->animal == 'v' )
      movs.push_back(make_pair(-1, 0));
    else if ( down->animal == 'z' and up and up->animal == 'v') {
      movs.push_back(make_pair(1, 0));
      hayZ = 1;
    }
  }

  if (right) {
    if (!hayZ and right->animal == 'v' )
      movs.push_back(make_pair(0, 1));
    else if ( right->animal == 'z' and left and left->animal == 'v') {
      movs.push_back(make_pair(0, -1));
      hayZ = 1;
    }
  }

  if (left) {
    if (!hayZ and left->animal == 'v' )
      movs.push_back(make_pair(0, -1));
    else if ( left->animal == 'z' and right and right->animal == 'v') {
      movs.push_back(make_pair(0, 1));
      hayZ = 1;
    }
  }
  
  if (downR) {
    if (!hayZ and downR->animal == 'v' )
      movs.push_back(make_pair(1, 1));
    else if ( downR->animal == 'z' and upL and upL->animal == 'v') {
      movs.push_back(make_pair(-1, -1));
      hayZ = 1;
    }
  }

  if (downL) {
    if (!hayZ and downL->animal == 'v' )
      movs.push_back(make_pair(1, -1));
    else if ( downL->animal == 'z' and upR and upR->animal == 'v') {
      movs.push_back(make_pair(-1, 1));
      hayZ = 1;
    }
  }

  if (upR) {
    if (!hayZ and upR->animal == 'v' )
      movs.push_back(make_pair(-1, 1));
    else if ( upR->animal == 'z' and downL and downL->animal == 'v') {
      movs.push_back(make_pair(1, -1));
      hayZ = 1;
    }
  }

  if (upL) {
        if (!hayZ and upL->animal == 'v' )
            movs.push_back(make_pair(-1, -1));
        else if ( upL->animal == 'z' and downR and downR->animal == 'v') {
            movs.push_back(make_pair(1, 1));
            hayZ = 1;
        }
  }
  // si no hay zorros se puede quedar quieto
  if (!hayZ) {
    movs.push_back(make_pair(0, 0));
  }
  return movs;
}

void Conejo::movimiento(vector<vector<Grilla> >& world) {
  vector<pair<int, int> > movs = laterales(world);
  auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
  mt19937 mt_rand(seed);
  int ir = mt_rand() % movs.size();
  px += movs[ir].first;
  py += movs[ir].second;
  if(world[px][py].hierba>0)this->energia++;
  else this->energia--;
  return;
}
int main() {
  int num_conejos;
  auto see = chrono::high_resolution_clock::now().time_since_epoch().count();
  mt19937 mt_rand(see);
  num_conejos = mt_rand() %  90 + 20;
  vector<vector<Grilla> >vec(100,vector<Grilla>(100,Grilla()));
  map<pair<int,int>,Conejo *> Conejos;
  int ppx,ppy;
  for(int i=0;i<num_conejos;i++) {
    ppx=mt_rand() % 97 + 1;ppy=mt_rand() % 97 + 1;
    while(vec[ppx][ppy].animal=='c') {
      ppx=mt_rand() % 97 + 1;ppy=mt_rand() % 97 + 1;
    }
    vec[ppx][ppy].animal='c';
    Conejos[make_pair(ppx,ppy)] = new Conejo(ppx,ppy);
  }
  char paramundo[4*Conejos.size()];
  int li=0;
  for(auto con:Conejos) {
    paramundo[li] = char(((con.first.first) / 10) + '0');
    paramundo[li + 1] = char(((con.first.first) % 10) +'0');
    paramundo[li + 2] = char(((con.first.second) / 10) + '0');
    paramundo[li + 3] = char(((con.first.second) % 10) + '0');
    li+=4;
  }
  //cout<<"Se creo a los conejos y listos para enviar"<<endl;
  paramundo[4*Conejos.size()]='\0';
  cout<<"Mundo generado: "<<endl;
  cout<<paramundo<<endl;
  //cout<<"conejos.size "<<Conejos.size()<<endl;
  char nombre_servidor[] = "localhost"; //el nombre del CPU servidor
  Cliente Agente(1638400); //Constructor con tamaño de buffer
  Agente.Conexion(nombre_servidor, 4003); //Intento conexion a numero de puerto
  char envio[1638400];
  for(int i=0; i<(4*Conejos.size()); i++)
    envio[i] = paramundo[i];
  //cout<<"LO Q DEBE ENVIAR: "<<envio<<endl;
  envio[4*Conejos.size()]='\0';
  Agente.Escritura(envio);
  //envio[4*Conejos.size()]='\0';
  char recibo[16384];
  //Agente.Lectura(recibo);
  /////////////////////////////////////////
  // Enviar la data a mundo sobre conejos//
  /////////////////////////////////////////
  //int recibo_size = sizeof( (std::string) recibo);
  //char *a = new char[recibo_size];
  //for(int i=0; i<(recibo_size); i++)
  //	*(a+i) = recibo[i];
  //cout<<"Se envio a los conejos"<<endl;
  char a[16384];
  int anhos =0;
  while(true){
    //esperar a q se reciva datos de mundo guardar en "a
    //Agente.Lectura(a);
    char *b = Agente.Lectura(a);
    //bzero(Agente.buffer,Agente.buffer_size);
    //cout<<"my agent: "<<sizeof(Agente.buffer)<<endl;
    //string AGENTE(Agente.buffer);
    //cout<<"myagent2: " <<AGENTE.length()<<endl;
    //cout<<b<<endl;
    string datos(b);
    //cout<<"b: "<<b<<endl;
    int i=0;
    bool hz=false;
    while(i < datos.length()) {
      if(datos[i]=='z') {
	i++;
	hz=true;
	continue;
      }
      int posx = (datos[i] - '0') * 10 + (datos[i + 1] - '0');
      int posy = (datos[i + 2] - '0') * 10 + (datos[i + 3] - '0');
      if(!hz) {
	int numhierba = (datos [i + 4]-'0') * 10 + (datos[i + 5] - '0');
	vec[posx][posy].hierba = numhierba;
	i += 6;
	continue;
      }
      else {
	if(vec[posx][posy].animal=='c') {
	  vec[posx][posy].animal='z';
	  delete Conejos[make_pair(posx,posy)];
	  Conejos.erase(make_pair(posx,posy));
	  cout<<"comido: "<<posx<<' '<<posy<<endl;
	}
	else {
	  vec[posx][posy].animal='z';
	}
	i+=4;
	continue;
      }
    }
    for(auto con: Conejos) {
      (con.second)->edad++;
      (con.second)->movimiento(vec);
      Conejo *pp; pp=con.second;
      Conejos.erase(con.first);
      Conejos[make_pair((con.second)->px, (con.second)->py)] = pp;
    }
    for(auto con: Conejos){
      if((con.second)->edad>=10 && (con.second)->energia<=0){
	cout<<"otras causas"<<con.first.first<<' '<<con.first.second<<endl;
    	delete (con.second);
	Conejos.erase(con.first);
     }
    }
    if(anhos%4)
    for(int i=0;i<10;i++) {
    ppx=mt_rand() % 97 + 1;ppy=mt_rand() % 97 + 1;
    while(vec[ppx][ppy].animal=='c') {
      ppx=mt_rand() % 97 + 1;ppy=mt_rand() % 97 + 1;
    }
    if(vec[ppx][ppy].animal!='z'){vec[ppx][ppy].animal='c';
      Conejos[make_pair(ppx,ppy)] = new Conejo(ppx,ppy);}
  }
    char paraMundo[4*Conejos.size()];
    int ii=0;
    /**/
    /**/
    for(auto con:Conejos){
      paraMundo[ii] = char(((con.first.first) / 10) + '0');
      paraMundo[ii + 1] = char(((con.first.first) % 10) +'0');
      paraMundo[ii + 2] = char(((con.first.second) / 10) + '0');
      paraMundo[ii + 3] = char(((con.first.second) % 10) + '0');
      ii+=4;
    }
    paraMundo[4*Conejos.size()]='\0';
    //cout<<"paramundo"<<paramundo<<endl;
    char envio1[1638400];
    for(int i=0; i<(4*Conejos.size()); i++)
      envio1[i] = paraMundo[i];
    Agente.Escritura(envio1);
    //cout<<"Modified"<<endl;
    //cout<<paraMundo<<endl;
    //cout<<"fin de ciclo"<<endl;
    /////////////////////////////////////////
    //Enviar a Mundo info sobre los conejos//
    /////////////////////////////////////////
  }
  return 0;
}
