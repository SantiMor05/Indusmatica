/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 10 de julio de 2025, 06:39 PM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"
#include "funcionesCola.h"
#include "Cola.h"
#include "funcionesLista.h"
using namespace std;

/*
 * 
 */

NodoArbol *buscarNodo(NodoArbol* raiz, Elemento elemento) {
    if (raiz) {
        if (raiz->elemento.numero < elemento.numero)
            return buscarNodo(raiz->derecha, elemento);
        else if (raiz->elemento.numero > elemento.numero)
            return buscarNodo(raiz->izquierda, elemento);
        else if (raiz->elemento.numero == elemento.numero)
            return raiz;
    }
    return nullptr;
}

void recorrerAmplitud(ArbolBinarioBusqueda arbol) {
    NodoArbol *p = arbol.arbolBinario.raiz;
    Cola cola;
    construir(cola);
    encolar(cola, arbol.arbolBinario.raiz->elemento);
    while (!esColaVacia(cola)) {
        Elemento elemento = desencolar(cola);
        cout << elemento.numero;
        p = buscarNodo(arbol.arbolBinario.raiz, elemento);
        if (p->izquierda) encolar(cola, p->izquierda->elemento);
        if (p->derecha)encolar(cola, p->derecha->elemento);
    }
}

void insertarAmplitud(ArbolBinarioBusqueda &arbol, Elemento elemento) {
    if (esArbolVacio(arbol.arbolBinario)){
        plantarArbolBinario(arbol.arbolBinario.raiz, nullptr, elemento, nullptr);
        return;
    }
    NodoArbol *p = arbol.arbolBinario.raiz;
    Cola cola;
    construir(cola);
    encolar(cola, arbol.arbolBinario.raiz->elemento);
    while (!esColaVacia(cola)) {
        Elemento ele = desencolar(cola);
        p = buscarNodo(arbol.arbolBinario.raiz, ele);
        if (p->derecha)encolar(cola, p->derecha->elemento);
        else {
            plantarArbolBinario(p->derecha, nullptr, elemento, nullptr);
            destruir(cola.lista);
            return;
        }
        if (p->izquierda) encolar(cola, p->izquierda->elemento);
        else {
            plantarArbolBinario(p->izquierda, nullptr, elemento, nullptr);
            destruir(cola.lista);
            return;
        }
    }
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    Elemento elemento;
    elemento.numero = 4;
    insertarAmplitud(arbol, elemento);
    elemento.numero = 6;
    insertarAmplitud(arbol, elemento);
    elemento.numero = 2;
    insertarAmplitud(arbol, elemento);
    elemento.numero = 7;
    insertarAmplitud(arbol, elemento);
    elemento.numero = 5;
    insertarAmplitud(arbol, elemento);
    elemento.numero = 3;
    insertarAmplitud(arbol, elemento);
    elemento.numero = 1;
    insertarAmplitud(arbol, elemento);
    elemento.numero = 8;
    insertarAmplitud(arbol, elemento);

    recorrerAmplitud(arbol);
//    enOrden(arbol);
    return 0;
}

