/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 10 de julio de 2025, 08:05 PM
 */

#include <iostream>
#include <cstring>

#include "ArbolB.h"
#include "funcionesAB.h"

using namespace std;

/*
 * 
 */

bool esPalabra(char *aux) {
    for (int i = 0; i < strlen(aux); i++) {
        if (aux[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool verificarLetra(char *aux, char c) {
    for (int i = 0; i < strlen(aux); i++) {
        if (aux[i] == c) {
            aux[i] = ' ';
            return true;
        }
    }
    return false;
}

bool evaluarR(NodoArbol *raiz, char *aux) {
    if (raiz) {
        if (verificarLetra(aux, raiz->elemento.c)) {
            if (esPalabra(aux))return true;
            else if (evaluarR(raiz->izquierda, aux)) return true;
            else if (evaluarR(raiz->derecha, aux)) return true;
        }
    }
    return false;
}

bool existePalabra(ArbolBinario arbol, const char*palabra) {
    char *aux = new char[strlen(palabra) + 1];
    strcpy(aux, palabra);
    return evaluarR(arbol.raiz, aux);

}

int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    Elemento elemento;
    elemento.c = 'L';
    plantarArbolBinario(arbol.raiz, nullptr, elemento, nullptr);
    elemento.c = 'D';
    plantarArbolBinario(arbol.raiz->izquierda, nullptr, elemento, nullptr);
    elemento.c = 'I';
    plantarArbolBinario(arbol.raiz->derecha, nullptr, elemento, nullptr);
    elemento.c = 'E';
    plantarArbolBinario(arbol.raiz->izquierda->izquierda, nullptr, elemento, nullptr);
    elemento.c = 'E';
    plantarArbolBinario(arbol.raiz->izquierda->derecha, nullptr, elemento, nullptr);
    elemento.c = 'R';
    plantarArbolBinario(arbol.raiz->izquierda->derecha->izquierda, nullptr, elemento, nullptr);
    elemento.c = 'G';
    plantarArbolBinario(arbol.raiz->izquierda->derecha->derecha, nullptr, elemento, nullptr);
    elemento.c = 'T';
    plantarArbolBinario(arbol.raiz->izquierda->derecha->derecha->izquierda, nullptr, elemento, nullptr);
    elemento.c = 'N';
    plantarArbolBinario(arbol.raiz->derecha->derecha, nullptr, elemento, nullptr);
    elemento.c = 'C';
    plantarArbolBinario(arbol.raiz->derecha->izquierda, nullptr, elemento, nullptr);
    elemento.c = 'C';
    plantarArbolBinario(arbol.raiz->derecha->izquierda->izquierda, nullptr, elemento, nullptr);
    elemento.c = 'O';
    plantarArbolBinario(arbol.raiz->derecha->izquierda->izquierda->izquierda, nullptr, elemento, nullptr);
    elemento.c = 'A';
    plantarArbolBinario(arbol.raiz->derecha->derecha->izquierda, nullptr, elemento, nullptr);
    elemento.c = 'F';
    plantarArbolBinario(arbol.raiz->derecha->derecha->izquierda->izquierda, nullptr, elemento, nullptr);
    elemento.c = 'T';
    plantarArbolBinario(arbol.raiz->derecha->derecha->izquierda->derecha, nullptr, elemento, nullptr);
    if (existePalabra(arbol, "HIJO"))cout << "HIJO ";
//    else cout << "No existe";
    if (existePalabra(arbol, "FINAL"))cout << "FINAL ";
//    else cout << "No existe";
    if (existePalabra(arbol, "MUNDO"))cout << "MUNDO ";
//    else cout << "No existe";
    if (existePalabra(arbol, "DEL"))cout << "DEL ";
//    else cout << "No existe";
    if (existePalabra(arbol, "DIA"))cout << "DIA ";
//    else cout << "No existe";
    if (existePalabra(arbol, "CICLO"))cout << "CICLO ";
//    else cout << "No existe";

    return 0;
}

