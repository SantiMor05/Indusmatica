#include <iostream>
#include<vector>
#define MAX 8
#include<algorithm>

using namespace std;

struct nodo {
    int punto = 0;
    int distancia = 0;
};

bool compara(nodo a, nodo b) {
    return a.distancia < b.distancia;
}

int rutaMin(int ini, int fin, int mapa[][MAX]) {
    int ciudad = ini, total = 0;

    while (1) {
        vector<nodo> vecinos;
        nodo paso;
        for (int i = 0; i < MAX; i++) {
            if (mapa[ciudad][i] > 0) {
                paso.punto = i;
                paso.distancia = mapa[ciudad][i];
                vecinos.push_back(paso);
            }
        }
        if (!vecinos.empty()) {
            sort(vecinos.begin(), vecinos.end(), compara);
            ciudad = vecinos[0].punto;
            total += vecinos[0].distancia;
        }
        if (ciudad == fin) break;
        if (vecinos.empty()) {
            total = -1;
        }
    }

    return total;
}

int main() {
    int mapa[][MAX]{
        {0, 4, 5, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int n = rutaMin(0, 6, mapa);

    if (n > 0) {
        cout << "se puede llegar en distancia = " << n << endl;
    } else {
        cout << "No se puede llegar" << endl;
    }

    return 0;
}
