#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <random>
#include <algorithm>
#include <utility>



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
    Conejo(int xx, int yy);
    int px, py;
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


    return;
}

int main() {
    int num_conejos;
    auto see = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(see);
    num_conejos = mt_rand() %  90 + 20;

    vector<vector<Grilla> >vec(100, vector<Grilla>(100, Grilla()));
    vector<Conejo*> Conejos;

    int ppx, ppy;
    for (int i = 0; i < num_conejos; i++) {
        ppx = mt_rand() % 97 + 1;
        ppy = mt_rand() % 97 + 1;
        while (vec[ppx][ppy].animal == 'c') {
            ppx = mt_rand() % 97 + 1;
            ppy = mt_rand() % 97 + 1;
        }
        vec[ppx][ppy].animal = 'c';

        Conejos.push_back(new Conejo(ppx, ppy));
    }

    for (int i = 0; i < Conejos.size(); i++) {
        cout << "posAnt: " << Conejos[i]->px <<", " << Conejos[i]->py << "-";
        Conejos[i]->movimiento(vec);
        cout  << "posPost: " << Conejos[i]->px <<", " << Conejos[i]->py << endl;
    }
}