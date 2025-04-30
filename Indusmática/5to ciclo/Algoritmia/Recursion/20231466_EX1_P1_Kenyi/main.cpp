/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 29 de abril de 2025, 11:19 PM
 */

#include <iostream>
using namespace std;
#define N 7
#define M 7

bool filaEnviaATodosDevuelveMax(int servidor[N][M], int fila, int &max) {
    for (int j = 0; j < M; j++) {
        if (max < servidor[fila][j])max = servidor[fila][j];
        if (j != fila && servidor[fila][j] == 0)
            return false;
    }
    return true;
}

bool columnaNoRecibeNada(int servidor[N][M], int col) {
    for (int i = 0; i < N; i++) {
        if (i != col && servidor[i][col] != 0)
            return false;
    }
    return true;
}

void buscarSkyNerd(int servidor[N][M]) {
    int candidato = 0;

    // Paso 1: Encontrar candidato en O(n)
    for (int i = 1; i < N; i++) {
        if (servidor[candidato][i] == 0 || servidor[i][candidato] != 0) {
            candidato = i;
        }
    }

    // Paso 2: Verificación en O(n)
    int max = 0;
    if (filaEnviaATodosDevuelveMax(servidor, candidato, max)
            && columnaNoRecibeNada(servidor, candidato)) {
        cout << "SKYNERD ha sido detectado en el servidor: " << candidato + 1 << endl;
        cout << "Máximo de paquetes enviados por SkyNerd: " << max << endl ;
    } else {
        cout << "SKYNERD no está en la red" << endl;
    }
}

int main() {
    int servidor[N][M] = {
        {0, 0, 0, 0, 0, 0, 0},
        {10, 0, 20, 30, 0, 20, 40},
        {0, 0, 0, 0, 0, 100, 0},
        {0, 0, 0, 0, 0, 80, 0},
        {50, 10, 5, 10, 0, 100, 4},
        {100, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    buscarSkyNerd(servidor);
    return 0;
}


