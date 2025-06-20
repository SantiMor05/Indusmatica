/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 17 de junio de 2025, 07:58 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int min(int a, int b) {
    if (a > b)return b;
    return a;
}

int calcularCentro(int *arr, int ini, int mid, int fin) {
    int suma = 0, maxIzq = 99999, maxDer = 99999;
    //izquierda
    for (int i = mid; i >= ini; i--) {
        suma += arr[i];
        if (suma < maxIzq)maxIzq = suma;
    }
    //derecha
    suma = 0;
    for (int i = mid + 1; i <= fin; i++) {
        suma += arr[i];
        if (suma < maxDer)maxDer = suma;
    }

    return maxDer + maxIzq;

}

int calcularMinAcumulacion(int *arr, int ini, int fin) {
    if (ini == fin)return arr[ini];

    int mid = (ini + fin) / 2;

    int izq = calcularMinAcumulacion(arr, ini, mid);
    int der = calcularMinAcumulacion(arr, mid + 1, fin);
    int centro = calcularCentro(arr, ini, mid, fin);

    return min(centro, min(izq, der));

}

int main(int argc, char** argv) {
//    int arr[] = {2, -3, 4, -5, -7};
//    int arr[] = {2, 5, -6, 2, 3, -1, -5, 6 };
    int arr[] = {-4 };
    int n = sizeof (arr) / sizeof (int);

    int acumulacionMin = calcularMinAcumulacion(arr, 0, n - 1);

    cout << "La minima acumulacion es: " << acumulacionMin;



    return 0;
}

