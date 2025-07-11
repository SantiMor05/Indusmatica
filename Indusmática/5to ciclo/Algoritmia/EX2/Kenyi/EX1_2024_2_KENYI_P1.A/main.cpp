/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 10 de julio de 2025, 12:07 AM
 */

#include <iostream>

#include "Elemento.h"

using namespace std;

/*
 * 
 */

int encontrarLotaFinal(Elemento *arr, int ini, int fin, int cantidad) {
    if (ini == fin)return arr[ini].lote;
    int mid = (ini + fin) / 2;
    if (arr[mid].cantidad == cantidad and arr[mid].cantidad < arr[mid + 1].cantidad)
        return arr[mid].lote;

     if (arr[mid].cantidad <= cantidad) {
       return encontrarLotaFinal(arr, mid + 1, fin, cantidad);
    } else return encontrarLotaFinal(arr, ini, mid - 1, cantidad);
}

int encontrarLotaInicial(Elemento *arr, int ini, int fin, int cantidad) {
    if (ini == fin)return arr[ini].lote;
    
    int mid = (ini + fin) / 2;
   
    if (arr[mid].cantidad == cantidad and arr[mid].cantidad > arr[mid - 1].cantidad)
        return arr[mid].lote;

    if (arr[mid].cantidad >= cantidad) {
        return encontrarLotaInicial(arr, ini, mid - 1, cantidad);
    } else return encontrarLotaInicial(arr, mid + 1, fin, cantidad);
}

int main(int argc, char** argv) {
    Elemento elemento[9] = {
        {15872, 3},
        {15865, 4},
        {15866, 4},
        {14357, 6},
        {14365, 6},
        {14368, 6},
        {14370, 6},
        {19258, 8},
        {19260, 8}
    };
    int n = 9;
    int cantidad = 8; 
    cout << "Lote Inicial: " << encontrarLotaInicial(elemento, 0, n - 1, cantidad) << endl;
    cout << "Lote Final: " << encontrarLotaFinal(elemento, 0, n - 1, cantidad);
    return 0;
}

