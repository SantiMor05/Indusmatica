/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 16 de mayo de 2025, 11:42 PM
 */

#include <iostream>

using namespace std;
#define N 6
#include "Pila.h"
#include "funcionesPila.h"

/*
 * 
 */
bool Camino(int matriz[][N], int n, Pila pila, int destino) {
    Elemento ciudad, aux;
    ciudad.numero = 0;
    apilar(pila, ciudad);
    while (!esPilaVacia(pila)) {
        ciudad = desapilar(pila);
        if(ciudad.numero==destino-1)return true;
        for (int i = 0; i < N; i++) {
            if (matriz[ciudad.numero][i] == 1) {
                aux.numero = i;
                apilar(pila, aux);
            }
        }
    }
    return false;
}

int main(int argc, char** argv) {
    int matriz[][N] = {
        {0, 1, 0, 1, 0, 0}, //1
        {0, 0, 1, 0, 0, 0}, //2
        {0, 0, 0, 0, 1, 0}, //3
        {0, 0, 0, 0, 0, 1}, //4
        {0, 0, 0, 0, 0, 0}, //5
        {0, 0, 0, 0, 0, 0}//6
    };
    Pila pila;
    construir(pila);
    if(Camino(matriz, N, pila, 5)){
        cout<<"Si hay camino";
    }
    else cout<<"No hay camino";

    return 0;
}

