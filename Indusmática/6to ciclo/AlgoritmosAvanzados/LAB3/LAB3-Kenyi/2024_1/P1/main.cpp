#include <iostream>
#define P 8
using namespace std;

enum nodos{A,B,C,D,E,F,G};

void caminoVoraz(int(* caminos)[8], int pos,int fin) {
    int distancia=0,posNueva;
    while (pos!=fin) {
        int min=999;
        for (int j = 0; j < P; j++) {
            if (min > caminos[pos][j] and caminos[pos][j]!=0) {
                min = caminos[pos][j];
                posNueva=j;
            }
        }
        if (min==999)break;
        distancia+=min;
        pos=posNueva;
    }

    if (pos==fin) {
        cout <<  "Tiempo de viaje "<<distancia<< endl;
    }
    else cout << "No se encontro solucion"<< endl;
}

int main() {
    int caminos[][P]={
        {0,4,5,6,0,0,0,0},
        {0,0,0,0,2,0,0,0},
        {0,0,0,0,0,0,0,3},
        {0,0,0,0,0,3,0,0},
        {0,0,0,0,0,0,10,0},
        {0,0,0,0,0,0,2,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    };


    caminoVoraz(caminos,C,G);

    return 0;
}
