/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 8 de julio de 2025, 22:35
 */

#include <iostream>
#include <codecvt>
#include "funcionesAB.h"
#include "ArbolB.h"
#include <cmath>

using namespace std;

/*
 * 
 */


void llenar(ArbolBinario &arbol){
    
    ArbolBinario arbol1, arbol2, arbol3, arbol4;
    
    Elemento elemento;
    
    elemento.numero = 0;
    plantarArbolBinario(arbol1, nullptr, elemento, nullptr);
    
    elemento.numero = 1;
    plantarArbolBinario(arbol2, nullptr, elemento, arbol1.raiz);
    
    elemento.numero = 1;
    plantarArbolBinario(arbol1, arbol2.raiz, elemento, nullptr); // 3 guardado en arbol1
    
    elemento.numero = 1;
    plantarArbolBinario(arbol2, nullptr, elemento, nullptr);
    
    elemento.numero = 0;
    plantarArbolBinario(arbol3, arbol2.raiz, elemento, nullptr);
    
    elemento.numero = 1;
    plantarArbolBinario(arbol4, nullptr, elemento, nullptr);
    
    elemento.numero = 0;
    plantarArbolBinario(arbol2, arbol4, elemento, arbol3);
    
    elemento.numero = 1;
    plantarArbolBinario(arbol3, arbol1, elemento, arbol2);
    
    elemento.numero = 0;
    plantarArbolBinario(arbol1, nullptr, elemento, nullptr);
    
    
    elemento.numero = -1;
    plantarArbolBinario(arbol, arbol3, elemento, arbol1);
    
    recorrerEnOrden(arbol);
    cout << endl;
    
}

int calcularSuma(int *numeros, int n){
    int suma = 0;
    for(int i = 0; i < n; i++)
        suma += numeros[i] *pow(2,n - i - 1);
    
    return suma;
}

bool veridicarNumeroRecusivo(NodoArbol *raiz,int numero, int *numeros, int n){
    
    bool caso1, caso2;
    if(raiz == nullptr)return false;

    
    if(raiz->elemento.numero != -1){
        numeros[n] = raiz->elemento.numero;
        n++;
    }
    
    int suma = calcularSuma(numeros, n);
    
    if(suma == numero)
        return true;
    
    caso1 =  veridicarNumeroRecusivo(raiz->derecha, numero, numeros, n);
    caso2 = veridicarNumeroRecusivo(raiz->izquierda, numero, numeros,n);
    
    
    return caso1 or caso2;
}

bool verificarNumero(ArbolBinario &arbol, int numero){
    int numeros[20]{};
    return veridicarNumeroRecusivo(arbol.raiz, numero, numeros, 0);
    
}

void imprimir(int *numeros,int n){
    
    for(int i = 0; i < n; i++)
        cout << numeros[i];
    
    cout << " ";
    
}

void imprimirNumeroRecursivo(NodoArbol *raiz, int *numeros, int n){
    
    if(raiz == nullptr)return;

    int suma;
    if(raiz->elemento.numero != -1){
        numeros[n] = raiz->elemento.numero;
        n++;
        suma = calcularSuma(numeros, n);
        imprimir(numeros, n);
        cout << ": " << suma << endl;
    }
    imprimirNumeroRecursivo(raiz->izquierda, numeros, n);
    imprimirNumeroRecursivo(raiz->derecha, numeros, n);
}

void imprimirNumeros(ArbolBinario &arbol){
    
    
    int numeros[20]{};
    
    imprimirNumeroRecursivo(arbol.raiz, numeros, 0);
}



int main(int argc, char** argv) {
    
    ArbolBinario arbol;
    construir(arbol);
    
    llenar(arbol);
    
    bool se_encuentra = verificarNumero(arbol, 7);
    
    cout << se_encuentra << endl;
    
    imprimirNumeros(arbol);

    return 0;
}

