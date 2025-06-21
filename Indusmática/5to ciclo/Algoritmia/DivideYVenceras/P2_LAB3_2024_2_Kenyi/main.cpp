/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 20 de junio de 2025, 06:32 PM
 */

#include <iostream>

using namespace std;
#define N 10

/*
 * 
 */
int max(int a, int b) {
    if (a > b)return a;
    return b;
}

int buscarNivel(int *arr, int ini, int fin) {
    if (ini == fin)return arr[ini];

    if (fin == ini + 1)
        return max(arr[ini], arr[fin]);

    int mid = (ini + fin) / 2;

    if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
        return arr[mid];

    if (arr[mid] < arr[mid + 1])
        return buscarNivel(arr, mid + 1, fin);
    else
        return buscarNivel(arr, ini, mid - 1);
}

void buscarCeroDer(int *arr, int ini, int fin, int &cont) {
    if (ini > fin)return;

    int mid = (ini + fin) / 2;

    if (arr[mid] == 0) {
        cont += fin - mid + 1;
        return buscarCeroDer(arr, ini, mid - 1, cont);
    } else return buscarCeroDer(arr, mid + 1, fin, cont);
}

void buscarCeroIzq(int *arr, int ini, int fin, int &cont) {
    if (ini > fin)return;

    int mid = (ini + fin) / 2;

    if (arr[mid] == 0) {
        cont += mid - ini + 1;
        return buscarCeroIzq(arr, mid + 1, fin, cont);
    } else return buscarCeroIzq(arr, ini, mid - 1, cont);
}

int main(int argc, char** argv) {
    int arr[N][N] = {
        {0, 0, 0, 3, 3, 7, 5, 5, 1, 1},
        {8, 8, 10, 9, 9, 5, 4, 4, 2, 0},
        {3, 5, 8, 9, 7, 6, 4, 2, 0, 0},
        {9, 7, 7, 4, 4, 4, 2, 0, 0, 0},
        {0, 2, 2, 3, 3, 4, 4, 5, 3, 3},
        {0, 0, 0, 0, 0, 0, 2, 3, 4, 5},
        {1, 2, 2, 3, 3, 4, 3, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 5, 5, 7},
        {6, 5, 5, 2, 2, 1, 0, 0, 0, 0},
        {3, 2, 2, 0, 0, 0, 0, 0, 0, 0}
    };
    int n = 10, max = 0, min = 99999999, muestrasMin[N]{};
    for (int i = 0; i < N; i++) {
        int nivel = buscarNivel(arr[i], 0, n - 1);
        int cont = 0;
        if (arr[i][0] != 0) buscarCeroDer(arr[i], 0, n - 1, cont);
        else buscarCeroIzq(arr[i], 0, n - 1, cont);
        if (min > cont) {
            min = cont;
        }
        muestrasMin[i] = n - cont;
        if (nivel > max)max = nivel;
    }
    cout << "El maximo de pureza es: " << max << endl;
    cout << "Muestras maximas: ";
    for (int i = 0; i < N; i++) if (muestrasMin[i] == N - min)cout << i + 1 << " ";
    cout << "con " << N - min << " estratos" << endl;
    return 0;
}

