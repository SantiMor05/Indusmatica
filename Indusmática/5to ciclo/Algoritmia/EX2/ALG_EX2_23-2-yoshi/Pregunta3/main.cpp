/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 9 de julio de 2025, 23:50
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#define M 9
#define N 9
/*
 * 
 */

bool falsoArreglos(int matriz[][N],int* arr){
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i!=j){
                if (matriz[i][j] > 0){
                    if (arr[i] == arr[j])
                        return false;
                }
            }
        }
    }
    return true;
}

bool EtiquetadorMG(int matriz[][N], int *arr, int cant, int i, int m, int n){
    if (i >= m) return 0;
    for (int j = 1; j <= cant; j++) {
        arr[i] = j;
        EtiquetadorMG(matriz,arr,cant,i+1,m,n);
        if (falsoArreglos(matriz,arr))
            return true;
    }
    return false;
}

int main(int argc, char** argv) {
    int matriz[][N] =
    {{1, 2, 0, 6, 0, 0, 0, 0, 2}, 
    {7, 1, 5, 2, 0, 0, 0, 0, 7}, 
    {0, 3, 1, 2, 3, 8, 9, 7, 5}, 
    {2, 7, 5, 1, 2, 0, 0, 0, 0}, 
    {0, 0, 5, 3, 1, 4, 0, 0, 0}, 
    {0, 0, 9, 0, 6, 1, 2, 0, 0}, 
    {0, 0, 3, 0, 0, 7, 1, 4, 0}, 
    {0, 0, 4, 0, 0, 0, 9, 1, 9}, 
    {5, 3, 6, 0, 0, 0, 0, 4, 1}};
    
    int arr[N]{};
    
    if(EtiquetadorMG(matriz,arr,4,0,M,N)){
        for (int i = 0; i < N; i++) {
            cout << i+1 << "-" << arr[i] << " ";
        }
    }else{
        cout << "NO existe solución posible";
    }

    
    return 0;
}

