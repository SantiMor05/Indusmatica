#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 8

struct nodo {
    int punto;
    int distancia;
};

bool operator<(const nodo &n1, const nodo &n2) {
    return n1.distancia < n2.distancia;
}

int rutaMinima(int ini, int fin, int mapa[][MAX]) {
    int ciudad = ini;
    int total = 0;
    while (1) {
        vector<nodo> vecinos;
        for (int i = 0; i < MAX; i++) {
            if (mapa[ciudad][i]!=0) {
                nodo paso;
                paso.punto = i;
                paso.distancia = mapa[ciudad][i];
                vecinos.push_back(paso);
            }
        }
        if (!vecinos.empty()) {
            sort(vecinos.begin(), vecinos.end()); //tmbn se puede ptr a funcion
            ciudad = vecinos[0].punto;
            total+=vecinos[0].distancia;
            if (ciudad == fin) break;
        }else {
            cout<<"No existe solución pipipi"<<endl;
            return 0;
        }
    }
    return total;
}

int main() {
    int mapa[][MAX] {
        {0,4,5,6,0,0,0,0},//A
        {0,0,0,0,2,0,0,0},//B
        {0,0,0,0,0,0,0,3},//C
        {0,0,0,0,0,3,0,0},//D
        {0,0,0,0,0,0,10,0},//E
        {0,0,0,0,0,0,2,0},//F
        {0,0,0,0,0,0,0,0},//G
        {0,0,0,0,0,0,0,0}//H
    };
    cout<<rutaMinima(0,6,mapa)<<endl;
    return 0;
}