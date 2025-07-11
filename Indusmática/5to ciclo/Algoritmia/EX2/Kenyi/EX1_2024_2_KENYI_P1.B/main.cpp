/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 10 de julio de 2025, 12:38 AM
 */

#include <iostream>
#include "Plato.h"
using namespace std;

/*
 * 
 */

void cambiar(Plato &platosI, Plato &platosK) {
    Plato aux = platosI;
    platosI = platosK;
    platosK = aux;
}

void qsort(Plato *platos, int ini, int fin) {
    if (ini > fin)return;
    int pivot = fin, lim = fin - 1;

    for (int i = fin - 1; i >= ini; i--) {
        if (platos[i].porcentajeReservas < platos[pivot].porcentajeReservas) {
            cambiar(platos[i], platos[lim]);
            lim--;
        }
    }

    //    int pivot = fin, lim = ini;
    //    for (int i = ini; i < fin; i++) {
    //        if (platos[i].porcentajeReservas > platos[pivot].porcentajeReservas) {
    //            cambiar(platos[i], platos[lim]);
    //            lim++;
    //        }
    //    }
    cambiar(platos[lim+1], platos[pivot]);
    qsort(platos, ini, lim);
    qsort(platos, lim +2, fin);
}

int main(int argc, char** argv) {
    Plato platos[5] = {
        {"Lomo Saltado", 50, 30, 60},
        {"Ceviche", 40, 35, 87.5},
        {"Aji de Gallina", 30, 10, 33.33},
        {"Causa Limeña", 20, 20, 100},
        {"Arroz con Pollo", 60, 45, 75}
    };
    qsort(platos, 0, 4);
    for (int i = 0; i < 5; i++)cout << platos[i].porcentajeReservas << " ";
    return 0;
}

