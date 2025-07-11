/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 10 de julio de 2025, 05:24 PM
 */

#include <iostream>
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "Pila.h"
#include "Cola.h"
#include "funcionesAB.h"

using namespace std;

/*
 * 
 */

NodoArbol * buscarNodo(NodoArbol *raiz, Elemento elemento) {
    NodoArbol *p = raiz;
    while (p) {
        if (p->elemento.numero < elemento.numero)
            p = p->derecha;
        else if (p->elemento.numero > elemento.numero)
            p = p->izquierda;
        else if (p->elemento.numero == elemento.numero)
            return p;
    }
    return nullptr;
}


void recorrerDiagonalArriba(ArbolBinarioBusqueda arbol) {
    Cola colaIzquierda;
    Pila pilaImprimir;
    construir(colaIzquierda);
    construir(pilaImprimir);
    NodoArbol *p = arbol.arbolBinario.raiz;

    while (true) {
        while (p) {
            apilar(pilaImprimir, p->elemento);
            if (p->izquierda)encolar(colaIzquierda, p->izquierda->elemento);
            p = p->derecha;
        }
        if(esColaVacia(colaIzquierda))break;
        p = buscarNodo(arbol.arbolBinario.raiz, desencolar(colaIzquierda));
    }
    imprimir(pilaImprimir);
}
void recorrerDiagonalAbajo(ArbolBinarioBusqueda arbol) {
    Cola colaIzquierda, colaImprimir;
    construir(colaIzquierda);
    construir(colaImprimir);
    NodoArbol *p = arbol.arbolBinario.raiz;

    while (true) {
        while (p) {
            encolar(colaImprimir, p->elemento);
            if (p->izquierda)encolar(colaIzquierda, p->izquierda->elemento);
            p = p->derecha;
        }
        if(esColaVacia(colaIzquierda))break;
        p = buscarNodo(arbol.arbolBinario.raiz, desencolar(colaIzquierda));
    }
    imprimir(colaImprimir);
}


int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    Elemento elemento;
    elemento.numero = 100;
    elemento.tipo = 0;
    insertar(arbol, elemento);
    elemento.numero = 50;
    elemento.tipo = 0;
    insertar(arbol, elemento);
    elemento.numero = 150;
    elemento.tipo = 0;
    insertar(arbol, elemento);
    elemento.numero = 25;
    elemento.tipo = 0;
    insertar(arbol, elemento);
    elemento.numero = 75;
    elemento.tipo = 0;
    insertar(arbol, elemento);
    elemento.numero = 125;
    elemento.tipo = 1;
    insertar(arbol, elemento);
    elemento.numero = 175;
    elemento.tipo = 0;
    insertar(arbol, elemento);
    elemento.numero = 40;
    elemento.tipo = 0;
    insertar(arbol, elemento);
    elemento.numero = 200;
    elemento.tipo = 0;
    insertar(arbol, elemento);
    recorrerDiagonalAbajo(arbol);
    recorrerDiagonalArriba(arbol);
    //    enOrden(arbol);
    return 0;
}

