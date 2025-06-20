/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 17 de junio de 2025, 08:14 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int max(int a, int b) {
    if (a > b)return a;
    return b;
}

int obternerCentro(int *arr, int ini, int mid, int fin) {
    int cont = 0;
    int aux = 0;
    for (int i = mid; i > ini; i--) {
        if (arr[i] > arr[i - 1])cont++;
        else break;
    }

    for (int i = mid; i < fin; i++) {
        if (arr[i] < arr[i + 1])cont++;
        else break;
    }

    return cont+1;
}

int calculaIntervaloMax(int *arr, int ini, int fin) {
    if (ini == fin)return 1;

    int mid = (ini + fin) / 2;

    int izq = calculaIntervaloMax(arr, ini, mid);
    int der = calculaIntervaloMax(arr, mid + 1, fin);
    int centro = obternerCentro(arr, ini, mid, fin);


    return max(centro, max(izq, der));
}

int main(int argc, char** argv) {
//    int arr[] = {10, 20, 15, 10, 12, 10, 13, 18};
    int arr[] = {7, 2, 9, 10, 16, 10, 13, 8, 2, 10};
    int n = sizeof (arr) / sizeof (int);

    int intervaloMax = calculaIntervaloMax(arr, 0, n - 1);

    cout << "Intervalo Max: " << intervaloMax;
    return 0;
}

