#include <iostream>
#include <map>
#include <vector>
using namespace  std;

struct Vecino {
    char nombre;
    int distancia;
};

void llenarVecinos(map<char,vector<Vecino>> &mapa) {
    Vecino vecino;
    //Vecinos de A
    vecino.nombre = 'B';
    vecino.distancia = 4;
    mapa['A'].push_back(vecino);
    vecino.nombre = 'C';
    vecino.distancia = 5;
    mapa['A'].push_back(vecino);
    vecino.nombre = 'D';
    vecino.distancia = 6;
    mapa['A'].push_back(vecino);
    //Vecinos de B
    vecino.nombre = 'E';
    vecino.distancia = 2;
    mapa['B'].push_back(vecino);
    //Vecinos de C
    vecino.nombre = 'H';
    vecino.distancia = 3;
    mapa['C'].push_back(vecino);
    //Vecinos de D
    vecino.nombre = 'F';
    vecino.distancia = 3;
    mapa['D'].push_back(vecino);
    //Vecinos de E
    vecino.nombre = 'G';
    vecino.distancia = 10;
    mapa['E'].push_back(vecino);
    //Vecinos de F
    vecino.nombre = 'G';
    vecino.distancia = 2;
    mapa['F'].push_back(vecino);
    //G y H no tienen vecinos
}

int GoldenGateGirl_BaluBrigada(map<char,vector<Vecino>> mapa, char pPartida, char pLlegada) {
    int recorrido = 0, minDist = 9999;
    char estoyAqui = pPartida, minDistLugar;
    while (true) {
        if (mapa[estoyAqui].size() == 0) return -1;
        for (int i = 0; i < mapa[estoyAqui].size(); i++) {
            if (mapa[estoyAqui][i].nombre == pLlegada)
                return recorrido + mapa[estoyAqui][i].distancia;
            if (mapa[estoyAqui][i].distancia < minDist) {
                minDist = mapa[estoyAqui][i].distancia;
                minDistLugar = mapa[estoyAqui][i].nombre;
            }
        }
        recorrido += minDist;
        estoyAqui = minDistLugar;
    }
}

int main() {
    map<char,vector<Vecino>> mapa;
    llenarVecinos(mapa);

    char pPartida = 'A', pLlegada = 'G';
//    char pPartida = 'D', pLlegada = 'G';
//    char pPartida = 'C', pLlegada = 'G';
    int sol = GoldenGateGirl_BaluBrigada(mapa,pPartida,pLlegada);
    if (sol>0)
        cout << "Tiempo de viaje: " << sol << " min" << endl;
    else cout << "No se encontro solucion";


    return 0;
}