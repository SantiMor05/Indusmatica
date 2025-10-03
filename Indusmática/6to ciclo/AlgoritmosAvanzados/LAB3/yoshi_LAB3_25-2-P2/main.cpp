#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Lavadora {
    int id;
    int tiempo_acumulado;
    vector<int> instruccionesRecibidas;
};

struct Instruccion {
    int modo; //secado (0) o lavado (1)
    int kilos;
};

bool compare(Lavadora a, Lavadora b) {
    return a.tiempo_acumulado < b.tiempo_acumulado or (a.tiempo_acumulado == b.tiempo_acumulado
        and a.id < b.id);
}

bool compareFin(Lavadora a, Lavadora b) {
    return a.id < b.id;
}

int main() {
    int n = 5; //numero de lavadoras
    Lavadora lavadoras[n];
    for (int i = 0; i < n; i++) {
        lavadoras[i].id = i+1;
        lavadoras[i].tiempo_acumulado = 0;
        lavadoras[i].instruccionesRecibidas.clear();
    }
    Instruccion instrucciones[] = {
        1,10, 1,10, 0,8, 1,15, 0,9, 0,11, 1,12, 0,15, 1,6, 0,10,
        1,8, 0,15, 1,11, 1,7, 1,7, 0,8, 0,9, 1,11, 0,12, 1,15
    };
    int m = sizeof(instrucciones)/sizeof(Instruccion);
    double multiplicador;
    for (int i = 0; i < m; i++) {
        sort(lavadoras,lavadoras+n,compare);
        lavadoras[0].instruccionesRecibidas.push_back(i+1);
        multiplicador = (instrucciones[i].modo>0) ? 4 : 2;
        lavadoras[0].tiempo_acumulado += instrucciones[i].kilos*multiplicador;
    }
    sort(lavadoras,lavadoras+n,compareFin);
    cout << "Solucion con instrucciones: "<< endl;
    for (int i = 0; i < n; i++) {
        cout << "Lavadora: " << lavadoras[i].id <<  ": ";
        for (int j=0; j<lavadoras[i].instruccionesRecibidas.size(); j++) {
            cout << " " << lavadoras[i].instruccionesRecibidas[j] << " ";
        }
        cout << " | Tiempo acumulado: " << lavadoras[i].tiempo_acumulado <<" min";;
        cout << endl;
    }

    return 0;
}