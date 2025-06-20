/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 1 de junio de 2025, 19:38
 */

#include <iostream>

using namespace std;
#define N 10
int cantInversiones = 0;
/*
 * 
 */
void mergeMod(int arr[], int ini, int medio, int fin){
    int aux[N];
    int p, q, m;
    for (p = ini, q = medio+1, m = ini; p <= medio && q <= fin; m++) {
        if (arr[p] < arr[q]){
            aux[m] = arr[p];
            p++;
        } else {
            cantInversiones += q-m;
            aux[m] = arr[q];
            q++;
        }
    }
}

void mergeSort(int arr[], int ini, int fin){
    if (ini == fin) return;
    int medio = (ini+fin)/2;
    mergeSort(arr, ini, medio);
    mergeSort(arr, medio+1, fin);
    mergeMod(arr, ini, medio, fin);
}

int main(int argc, char** argv) {
    int arr[]{5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    cout << "Numero de inversiones: " << cantInversiones;
    return 0;
}

