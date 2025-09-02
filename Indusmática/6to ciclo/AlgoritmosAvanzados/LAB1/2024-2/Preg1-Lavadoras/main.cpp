#include <iostream>
#define PISOS 5
#define Q 50

using namespace  std;

int  maximinarLavado(int pos, int peso, int &maxPeso, double costo, int internos, int *ropas,
    int *internosLavados, int *solucion) {

    if (peso > Q)
        return 0;
    if (pos == internos) {
        if (maxPeso < peso) {
            maxPeso = peso;
            for (int i = 0; i < internos; i++) {
                solucion[i] = internosLavados[i];
            }
        }
        return 0;
    }
    internosLavados[pos] = pos + 1;
    if (maximinarLavado(pos + 1, peso + ropas[pos], maxPeso, costo, internos,
                        ropas, internosLavados, solucion)) return 1;
    internosLavados[pos] = 0;
    maximinarLavado(pos + 1, peso, maxPeso, costo, internos, ropas, internosLavados, solucion);

    return 0;
}

void imprimirSegunCriterio(int *solucion, int internos, int opcion) {
    if (opcion == 1) {
        for (int j = 0; j < internos; j++) {
            if (solucion[j] != 0) {
                cout << "R" << j+1 << "  ";
            }
        }
    }
    else {
        for (int j = 0; j < internos; j++) {
            if (solucion[j] == 0) {
                cout << "R" << j+1 << "  ";
            }
        }
    }
    cout << endl;

}

int calcularRopaALavar(int *solucion,int internos, int *ropa) {
    int suma = 0;
    for (int i = 0; i < internos; i++) {
        if (solucion[i] == 0)
            suma += ropa[i];
    }
    return suma;
}

void calcularLavado(double *costos, int *internos, int ropa[PISOS][7]) {
    int suma = 0;
    int maxUso = 0, minUso = 99999999;
    int pisoMax = 0, pisoMin = 0;
    int ropaALavar, maxRopaLavar = 0, minRopaLavar = 9999999;
    int pisoMaxLavar = 0, pisoMinLavar = 0;
    for (int i = 0; i < PISOS; i++) {
        int internosLavados[7]{}, solucion[7]{};
        int maxPeso = 0;
        maximinarLavado(0, 0, maxPeso, costos[i], internos[i], ropa[i], internosLavados,solucion);
        cout << "Para el piso " << i + 1 << " se lavara las ropas de: " << endl;
        imprimirSegunCriterio(solucion, internos[i], 1);
        cout << "Para el piso " << i + 1 << " NO se lavara las ropas de: " << endl;
        imprimirSegunCriterio(solucion, internos[i], 0);
        suma += maxPeso;
        ropaALavar = calcularRopaALavar(solucion, internos[i], ropa[i]);
        if (maxPeso > maxUso) {
            maxUso = maxPeso;
            pisoMax = i + 1;
        }
        if (maxPeso < minUso) {
            minUso = maxPeso;
            pisoMin = i + 1;
        }

        if (ropaALavar > maxRopaLavar) {
            maxRopaLavar = ropaALavar;
            pisoMaxLavar = i + 1;
        }

        if (ropaALavar < minRopaLavar) {
            minRopaLavar = ropaALavar;
            pisoMinLavar = i + 1;
        }

    }
    double porcentaje = (double)suma / (Q * PISOS) * 100;
    cout << "Porcentaje uso lavadora: " << porcentaje << "%" << endl;
    cout << "Piso que mas ocupa la lavadora: " << pisoMax << endl;
    cout << "Piso que menos ocupa la lavadora: " << pisoMin << endl;

    cout << "Piso con mas kilos de ropa a lavar por parientes: " << pisoMaxLavar << endl;
    cout << "Piso con menos kilos de ropa a lavar por parientes: " << pisoMinLavar << endl;

}


int main() {

    double costos[PISOS] = {5,6,8,5,9};
    int internos[PISOS] = {6,7,4,5,2};

    int ropa[PISOS][7] {
        {14,11,10,19,14,11},
        {20,11,11,10,15,17,8},
        {15,16,15,16},
        {11,4,19,12,10},
        {18,12}
    };

    calcularLavado(costos, internos, ropa);

    return 0;
}