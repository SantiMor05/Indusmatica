#include <iostream>

#define MAX 8
using namespace std;


void minimaRuta(int *map, int &ruta, int &pos) {
    int min = 999;
    for (int i = 0; i < MAX; i++) {
        if (map[i] < min && map[i] != 0) {
            min = map[i];
            pos = i;
        }
    }

    if (min == 999) {
        ruta = 0;
    } else ruta = min;
}

void calcularRuta(int map[][MAX],int pos,int fin) {
    int ruta =999;
    int sol = 0;
    while ((pos != fin) and ruta != 0) {
        minimaRuta(map[pos], ruta, pos);
        sol += ruta;
    }

    if (pos != fin) {
        cout << "No llego a la ciudad"<<endl;
    }
    else cout << "Si llego a la ciudad" << endl;
    cout << "distancia recorrida: " << sol << endl;
}

int main() {
    int map[][MAX] = {
        {0, 4, 5, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

   calcularRuta(map,0,7) ;

    return 0;
}
