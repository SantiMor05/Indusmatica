/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 1 de junio de 2025, 02:07 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int unico(int arr[], int izq, int der) {
    if (izq == der)return arr[izq];

    int mid = (izq + der) / 2;

    if (mid % 2 == 1) {
        mid--; // bajamos mid para que sea par
    }

    if (arr[mid] == arr [mid + 1]) {
        return unico(arr, mid + 2, der);
    } else
        return unico(arr, izq, mid);
}

int main(int argc, char** argv) {
    int arr[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    int n = 11;
    cout << "Elemento Unico: " << unico(arr, 0, n - 1);
    return 0;
}

