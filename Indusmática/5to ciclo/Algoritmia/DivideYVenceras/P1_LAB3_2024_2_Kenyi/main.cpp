/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 20 de junio de 2025, 05:55 PM
 */

#include <iostream>
#include <climits>
#include <wchar.h>

using namespace std;

/*
 * 
 */

void merge(int *arr, int ini, int mid, int fin) {
    int l1, l2, p = 0, q = 0;

    l1 = mid - ini + 1;
    l2 = fin - mid;

    int A[l1 + 1];
    int B[l2 + 1];

    for (int i = ini; i <= mid; i++) A[i - ini] = arr[i];
    A[l1] = INT_MAX;

    for (int i = mid + 1; i <= fin; i++) B[i - mid - 1] = arr[i];
    B[l1] = INT_MAX;

    //mezclar
    for (int i = ini; i <= fin; i++) {
        if (A[p] < B[q]) {
            arr[i] = A[p];
            p++;
        } else {
            arr[i] = B[q];
            q++;
        }
    }
}

void mergeSort(int *arr, int ini, int fin) {
    if (ini == fin)return;

    int mid = (ini + fin) / 2;

    mergeSort(arr, ini, mid);
    mergeSort(arr, mid + 1, fin);
    merge(arr, ini, mid, fin);

}

int buscarImpar(int *arr, int ini, int fin) {
    if (ini == fin)return arr[ini];

    int mid = (ini + fin) / 2;

    if (mid % 2 == 1) {
        mid--; // bajamos mid para que sea par
    }

    if (arr[mid] == arr [mid + 1]) {
        return buscarImpar(arr, mid + 2, fin);
    } else
        return buscarImpar(arr, ini, mid);

}

int main(int argc, char** argv) {
    int arr[] = {1, 6, 3, 4, 5, 6, 3, 7, 5, 4, 3, 1, 7};
    int n = sizeof (arr) / sizeof (int);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    int impar = buscarImpar(arr, 0, n - 1);

    cout << "El emplado " << impar << " ingreso y no volvio a salir" << endl;
    return 0;
}

