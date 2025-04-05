/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 4 de abril de 2025, 10:06 PM
 */

#include <iostream>
#include <cmath>
#define N 4

using namespace std;

/*
 * 
 */

void cargarBin(int cromo[][N], int num, int n, int base) {
    int res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cromo[i][j] = 0;
    }
    int i = 0, j = 0;
    while (num > 0) {
        res = num % base;
        if (i == N) {
            i = 0;
            j++;
        }
        num /= base;
        cromo[j][i] = res;
        i++;
    }
}

int main(int argc, char** argv) {
    int capacidad = 100, base = 2;
    int cromo[N][N];
    int pesos[][N]{
        {20, 20, 20, 20},
        {10, 30, 10, 30},
        {10, 10, 10, 10},
        {15, 15, 15, 15}
    };
    int valores[][N]{
        {10, 10, 10, 50},
        {80, 10, 10, 20},
        {20, 20, 20, 20},
        {50, 50, 50, 50}
    };
    int opciones = (int) pow(base, N * N);
    int valorMax = 0, combinacionMax;
    for (int i = 0; i < opciones; i++) {
        cargarBin(cromo, i, N, base);
        int capacidadAux = capacidad;
        int valorTotal = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (cromo[j][k] != 0) {
                    capacidadAux -= pesos[j][k];
                    valorTotal += valores[j][k];
                }
            }
        }
        if (capacidadAux >= 0) {
            if (valorTotal > valorMax) {
                valorMax = valorTotal;
                combinacionMax = i;
            }
        }
    }

    cargarBin(cromo, combinacionMax, N, base);
//    for (int j = 0; j < N; j++) {
//        for (int k = 0; k < N; k++) {
//            if (cromo[j][k] == 0) {
//                pesos[j][k] = 0;
//                valores[j][k] = 0;
//            }
//        }
//    }
    cout << "Solucion Max: " << endl << "Pesos:" << endl;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            cout << cromo[j][k] * pesos[j][k] << " ";
        }
        cout << endl;
    }
    cout << "Valores" << endl;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            cout << cromo[j][k] * valores[j][k] << " ";
        }
        cout << endl;
    }
    cout << "Valor Maximo: " << valorMax;

    return 0;
}

