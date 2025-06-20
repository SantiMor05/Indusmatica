/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 17 de junio de 2025, 08:36 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int encontrarValorMax(int *arr, int ini, int fin) {
    if (ini == fin)return arr[ini];

    int mid = (ini + fin) / 2;

    if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
        return arr[mid];

    if (arr[mid] >= arr[ini])
        return encontrarValorMax(arr, mid + 1, fin);
    else
        return encontrarValorMax(arr, ini, mid - 1);
}

int main(int argc, char** argv) {
//    int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int n = sizeof (arr) / sizeof (int);

    int valorMax = encontrarValorMax(arr, 0, n - 1);

    cout << "El valora maximo es: " << valorMax;
    return 0;
}

