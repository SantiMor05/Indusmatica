/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 20 de junio de 2025, 09:07 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#define N 7
#define M 8

/*
 * 
 */

int hallarPotencia(int* arr, int ini, int fin) {
    if (ini == fin) {
        return arr[ini];
    }
    int med = (ini + fin) / 2;
    if (arr[med] >= arr[med - 1] and arr[med] >= arr[med + 1]) {
        return arr[med];
    }
    if (arr[med] < arr[med - 1]) {
        hallarPotencia(arr, ini, med - 1);
    } else hallarPotencia(arr, med + 1, fin);

}

int buscarPotenciaMax(int* arr, int ini, int fin) {
    if (ini == fin) {
        return ini;
    }
    int med = (ini + fin) / 2;

    if (arr[med] < arr[med - 1]) {
        buscarPotenciaMax(arr, ini, med - 1);
    } else buscarPotenciaMax(arr, med + 1, fin);
}

int main(int argc, char** argv) {
    int matriz[M][N] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0},
        {0, 1, 2, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
    };

    int potencia, potmax = 0, fila;
    for (int i = 0; i < M; i++) {
        potencia = hallarPotencia(matriz[i], 0, N - 1);
        if (potmax < potencia) {
            potmax = potencia;
            fila = i;
        }
    }

    int col = buscarPotenciaMax(matriz[fila], 0, N - 1);

    cout << "La potencia mas alta es " << potmax << " en la fila " << fila;
    cout << " y en la columna " << col << endl;

    return 0;
}

