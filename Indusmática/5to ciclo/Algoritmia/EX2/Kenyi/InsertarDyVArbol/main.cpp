/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 10 de julio de 2025, 04:38 PM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"

using namespace std;

/*
 * 
 */

void insertarDV(ArbolBinarioBusqueda &arbol, int *arr, int ini, int fin) {
    if (ini > fin)return;
    Elemento ele;
    int mid = (ini + fin) / 2;
    ele.numero = arr[mid];
    insertar(arbol, ele);
    insertarDV(arbol, arr, ini, mid - 1);
    insertarDV(arbol, arr, mid + 1, fin);
}

void insertarBanlanceado(ArbolBinarioBusqueda &arbol, int *arr, int n) {
    insertarDV(arbol, arr, 0, n - 1);
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    Elemento elemento;
    construir(arbol);

    int arr[] = {11, 21, 31, 41, 51, 61, 71};
    int n = sizeof (arr) / sizeof (arr[0]);

    insertarBanlanceado(arbol, arr, n);

    enOrden(arbol);
    return 0;
}

