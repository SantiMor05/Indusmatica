/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 10 de julio de 2025, 01:44 AM
 */

#include <iostream>
#include "ArbolB.h"
#include "funcionesAB.h"
#include <cmath>
#include <iomanip>
using namespace std;

/*
 * 
 */

int convertirBin(int binario) {
    int n = 0, i = 0;
    double exponente;
    while (binario > 0) {
        exponente = pow(2, i);
        n += (binario % 10 * exponente);
        binario /= 10;
        i++;
    }
    return n;
}

bool encuentraR(NodoArbol *raiz, int num, int bin) {
    if (raiz) {
        int binario = bin * 10 + raiz->elemento.numero;
        if (convertirBin(binario) == num)return true;
        if (encuentraR(raiz->izquierda, num, binario))return true;
        else if (encuentraR(raiz->derecha, num, binario))return true;
    }
    return false;
}

bool encontrarValor(ArbolBinario arbol, int num) {
    if (encuentraR(arbol.raiz->derecha, num, 0)) return true;
    else if (encuentraR(arbol.raiz->izquierda, num, 0)) return true;
    return false;
};

void imprimirR(NodoArbol *raiz, int bin) {
    if (raiz) {
        int binario = bin * 10 + raiz->elemento.numero;
        cout << "Binario: " << setw(5) << binario << ":" << convertirBin(binario) << endl;
        imprimirR(raiz->izquierda, binario);
        imprimirR(raiz->derecha, binario);
    }
}

void imprimir(ArbolBinario &arbol) {
    imprimirR(arbol.raiz->derecha, 0);
    imprimirR(arbol.raiz->izquierda, 0);
}

int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);

    //armado primer nivel
    arbol.raiz = new NodoArbol;
    arbol.raiz->elemento.numero = 7; //root
    arbol.raiz->derecha = new NodoArbol;
    arbol.raiz->derecha->elemento.numero = 0;
    arbol.raiz->derecha->derecha = nullptr;
    arbol.raiz->derecha->izquierda = nullptr;
    arbol.raiz->izquierda = new NodoArbol;
    arbol.raiz->izquierda->elemento.numero = 1;

    //armado segundo nivel
    arbol.raiz->izquierda->izquierda = new NodoArbol;
    arbol.raiz->izquierda->izquierda->elemento.numero = 1;
    arbol.raiz->izquierda->derecha = new NodoArbol;
    arbol.raiz->izquierda->derecha->elemento.numero = 0;

    //armado tercer nivel
    arbol.raiz->izquierda->izquierda->izquierda = new NodoArbol;
    arbol.raiz->izquierda->izquierda->izquierda->elemento.numero = 1;
    arbol.raiz->izquierda->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->derecha->izquierda = new NodoArbol;
    arbol.raiz->izquierda->derecha->izquierda->elemento.numero = 1;
    arbol.raiz->izquierda->derecha->derecha = new NodoArbol;
    arbol.raiz->izquierda->derecha->derecha->elemento.numero = 0;

    //armado cuarto nivel
    arbol.raiz->izquierda->izquierda->izquierda->izquierda = nullptr;
    arbol.raiz->izquierda->izquierda->izquierda->derecha = new NodoArbol;
    arbol.raiz->izquierda->izquierda->izquierda->derecha->elemento.numero = 0;
    arbol.raiz->izquierda->derecha->derecha->izquierda = new NodoArbol;
    arbol.raiz->izquierda->derecha->derecha->izquierda->elemento.numero = 1;
    arbol.raiz->izquierda->derecha->derecha->derecha = nullptr;
    arbol.raiz->izquierda->derecha->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->derecha->izquierda->izquierda = nullptr;

    //null del quinto nivel
    arbol.raiz->izquierda->izquierda->izquierda->derecha->derecha = nullptr;
    arbol.raiz->izquierda->izquierda->izquierda->derecha->izquierda = nullptr;
    arbol.raiz->izquierda->derecha->derecha->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->derecha->derecha->izquierda->izquierda = nullptr;

    if (encontrarValor(arbol, 1))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 2))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 3))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 4))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 5))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 6))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 7))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 8))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 9))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 10))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 11))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 12))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 13))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;
    if (encontrarValor(arbol, 14))cout << "Encontro" << endl;
    else cout << "No encontro" << endl;

    imprimir(arbol);

    return 0;
}

