/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 21 de mayo de 2025, 05:47 PM
 */

#include <iostream>

using namespace std;
#include "Pila.h"
#include "funcionesPila.h"
#define N 14


/*
 * 
 */
//{1,7,2,7,3,4,3,2,1,7,2,1,7,3};
void izquierda(int *num, int *izq) {
    Pila pila;
    construir(pila);
    Elemento aux;
    for (int i = 0; i < N; i++) {
        int cont = 0;
        while (!esPilaVacia(pila)
                and num[cima(pila).numero] < num[i]) {
            cont += izq[cima(pila).numero] + 1;
            desapilar(pila);
        }
        izq[i] = cont;
        aux.numero = i;
        apilar(pila, aux);
    }
}

void derecha(int *num, int *der) {
    Pila pila;
    construir(pila);
    Elemento aux;
    for (int i = N - 1; i >= 0; i--) {
        int cont = 0;
        while (!esPilaVacia(pila) and
                num[cima(pila).numero] < num[i]) {
            cont += der[cima(pila).numero] + 1;
            desapilar(pila);
        }
        der[i] = cont;
        aux.numero = i;
        apilar(pila, aux);
    }
}

void buscarPilas(int *num, int &pos, int &cant) {
    int max = 0, suma;
    int der[N];
    int izq[N];
    izquierda(num, izq);
    derecha(num, der);
    for (int i = 0; i < N; i++) cout << izq[i] << " ";
    cout << endl;
    for (int i = 0; i < N; i++) cout << der[i] << " ";
    for (int i = 0; i < N; i++) {
        suma = der[i] + izq[i];
        if (suma > max) {
            max = suma;
            cant = max;
            pos = i;
        }
    }
}

int main(int argc, char** argv) {
    int num[] = {1,7,2,7,3,4,3,2,1,7,2,1,7,3};
    int pos, cant;
    buscarPilas(num, pos, cant);
    cout << endl << "La posicion es: " << pos << ", con la cantidad de " << cant;
    return 0;
}

