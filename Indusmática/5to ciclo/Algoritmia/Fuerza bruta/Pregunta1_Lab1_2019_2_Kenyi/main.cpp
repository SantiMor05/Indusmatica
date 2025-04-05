/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 4 de abril de 2025, 05:19 PM
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */

void cargarBin(int *cromo, int num, int n) {
    int res, i = 0;
    for (int j = 0; j < n; j++)cromo[j] = 0;
    while (num > 0) {
        res = num % 2;
        num /= 2;
        cromo[i] = res;
        i++;
    }
}

bool validarPre(int activo, int *predecesores, int n, int *cromo) {

    for (int i = 0; i < n; i++) {
        bool cumple = false;
        if (!predecesores[i])return true;
        if (cromo[predecesores[i] - 1] == 1)cumple = true;
        if (cumple == false)return false;
    }
    return false;
}

int main(int argc, char** argv) {
    int N = 8, presupuesto = 250, maxGanancia = 0, combMax;
    int costo[N] = {80, 20, 100, 100, 50, 10, 50, 50};
    int cromo[N];
    int ganancia[N] = {150, 80, 300, 150, 80, 50, 120, 150};
    int predecesores[][8] = {
        {},
        {},
        {1, 2},
        {},
        {},
        {2},
        {6},
        {6}
    };
    int opciones = (int) pow(2, N);
    int contador = 0;
    for (int i = 0; i < opciones; i++) {
        cargarBin(cromo, i, N);
        //        //                for(int j=0;j<N;j++)cout<<cromo[j]<<" ";
        //        //                cout<<endl;
        int presupuestoAux = presupuesto;
        int gananciaTotal = 0;
        bool valida = true;
        for (int j = 0; j < N; j++) {
            if (cromo[j] != 0) {
                if (validarPre(cromo[j], predecesores[j], N, cromo)) {
                    presupuestoAux -= costo[j];
                    gananciaTotal += ganancia[j];
                } else valida = false;
            }
        }
        if (presupuestoAux >= 0 and valida) {
            contador++;
            if (maxGanancia <= gananciaTotal) {
                maxGanancia = gananciaTotal;
                combMax = i;
            }
            cargarBin(cromo, i, N);
            cout << "Solucion " << contador << ": ";
            for (int j = 0; j < N; j++)cout << cromo[j] << " ";
            cout << gananciaTotal << endl;
        }
    }

    //    ordenar
    cout << "Mejor Solucion: ";
            cargarBin(cromo, combMax, N);
    for (int j = 0; j < N; j++)cout << cromo[j] << " ";
    cout << maxGanancia << endl;
    return 0;

}

