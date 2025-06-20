/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 1 de junio de 2025, 07:02 PM
 */

#include <iostream>
#include <vector>
using namespace std;

// Paso 1: Buscar el inicio de la radiación

int buscarInicioRadiacion(int arr[], int izq, int der) {
    if (izq > der)return -1;
    int mid = (izq + der) / 2;

    if (arr[mid] > 0 and (arr[mid - 1] <= 0)) return mid;

    if (arr[mid] <= 0) {
        return buscarInicioRadiacion(arr, mid + 1, der);
    } else {
        return buscarInicioRadiacion(arr, izq, mid - 1);
    }
}

// Paso 2: Buscar el pico máximo (montaña)

int buscarPicoRadiacion(int arr[], int izq, int der) {
    if (izq == der)return arr[izq];

    int mid = (izq + der) / 2;

    if (arr[mid] < arr[mid + 1]) {
        return buscarPicoRadiacion(arr, mid + 1, der);
    } else
        return buscarPicoRadiacion(arr, izq, mid);
}

int main() {
    int arr[] = {-1, 0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
    int n = 19;

    int inicio = buscarInicioRadiacion(arr, 0, n - 1);
    if (inicio == -1) {
        cout << "No se detectó radiación.\n";
        return 0;
    }

    int pico = buscarPicoRadiacion(arr, inicio, n - 1);

    cout << "La radiación empieza a " << inicio << " km." << endl;
    cout << "Potencia máxima: " << pico << " megatones." << endl;

    return 0;
}

