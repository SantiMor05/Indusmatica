/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 20 de junio de 2025, 17:32
 */

#include <iostream>

using namespace std;
#define N 7

/*
 * 
 */
void mergeFull(int arr1[], int arr2[], int arr3[], int ini, int medio, int fin) {
    int aux1[N]{}, aux2[N]{}, aux3[N]{};
    int p, q, m;
    for (p = ini, q = medio + 1, m = ini; p <= medio and q <= fin; m++) {
        if (arr1[p] < arr1[q]) {
            aux1[m] = arr1[p];
            aux2[m] = arr2[p];
            aux3[m] = arr3[p];
            p++;
        } else {
            aux1[m] = arr1[q];
            aux2[m] = arr2[q];
            aux3[m] = arr3[q];
            q++;
        }
    }
    while (p <= medio) {
        aux1[m] = arr1[p];
        aux2[m] = arr2[p];
        aux3[m] = arr3[p];
        m++;
        p++;
    }
    while (q <= fin) {
        aux1[m] = arr1[q];
        aux2[m] = arr2[q];
        aux3[m] = arr3[q];
        m++;
        q++;
    }
    for (int i = ini; i <= fin; i++) {
        arr1[i] = aux1[i];
        arr2[i] = aux2[i];
        arr3[i] = aux3[i];
    }

}

void mergeSort(int id[], int impacto[], int riesgo[], int ini, int fin) {
    if (ini == fin) return;
    int medio = (ini + fin) / 2;
    mergeSort(id, impacto, riesgo, ini, medio);
    mergeSort(id, impacto, riesgo, medio + 1, fin);
    mergeFull(id, impacto, riesgo, ini, medio, fin);
}

void ordenar(int id[], int impacto[], int riesgo[],  int n) {
    mergeSort(riesgo, impacto, id, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << id[i] << '-' << impacto[i] << '-' << riesgo[i] << "  ";
    cout << "   Por nivel de Riesgo " << endl;
    mergeSort(impacto, id, riesgo, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << id[i] << '-' << impacto[i] << '-' << riesgo[i] << "  ";
   cout << "   Por impacto " << endl;
    mergeSort(id, impacto, riesgo, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << id[i] << '-' << impacto[i] << '-' << riesgo[i] << "  ";
    cout << "   Por id de Riesgo " << endl;

}

int main(int argc, char** argv) {
    int id[]{4, 1, 5, 7, 6, 3, 2};
    int impacto[]{1, 2, 3, 2, 3, 2, 1};
    int riesgo[]{3, 4, 9, 2, 6, 6, 2};
    int n = sizeof(id)/sizeof(id[0]);
    ordenar(id, impacto, riesgo,  n);
    return 0;
}

