/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 9 de julio de 2025, 08:12 PM
 */

#include <iostream>
#include "ArbolBB.h"
#include "Cola.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "Pila.h"
using namespace std;

/*
 * 
 */

void eliminarHijosUnicosP(ArbolBinarioBusqueda &arbol) {
    Pila pila;
    construir(pila);
    NodoArbol *p = arbol.arbolBinario.raiz;
    int ultimo = -1;
    while (true) {
        while (p) {
            apilar(pila, p);
            p = p->izquierda;
        }
        if (esPilaVacia(pila))break;
        p = desapilar2(pila); // cima;
        if (p->derecha and p->izquierda) {
            p = p->derecha;
        } else {
            p->derecha = nullptr;
            p->izquierda = nullptr;
            p = nullptr;
        }
    }
}


void eliminarHijosUnicosPV2(ArbolBinarioBusqueda &arbol) {
    Pila pila;
    construir(pila);
    NodoArbol *p = arbol.arbolBinario.raiz;
    int ultimo = -1;
    while (true) {
        while (p) {
            apilar(pila, p);
            p = p->izquierda;
        }
        p = pila.lista.cabeza->nodoA;
        if (p->derecha and ultimo != p->derecha->elemento.numero) {
            p = p->derecha;
        } else {
            if (!p->derecha or !p->izquierda) {
                p->derecha = nullptr;
                p->izquierda = nullptr;
            }
            ultimo = desapilar(pila).numero;
            p = nullptr;
        }
        if (esPilaVacia(pila))break;
    }
}

void eliminarHijosUnicos(ArbolBinarioBusqueda &arbol) {
    Cola cola;
    construir(cola);
    NodoArbol *p = arbol.arbolBinario.raiz;
    int ultimo = -1;
    while (true) {
        while (p) {
            encolar(cola, p);
            p = p->izquierda;
        }
        p = desencolar2(cola); // cima;
        if (p->derecha and p->izquierda) {
            p = p->derecha;
        } else {
            p->derecha = nullptr;
            p->izquierda = nullptr;
            p = nullptr;
        }
        if (esColaVacia(cola))break;
    }
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol, arbol2;
    construir(arbol);
    construir(arbol2);
    Elemento elemento;
    elemento.numero = 100;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    elemento.numero = 50;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    elemento.numero = 150;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    elemento.numero = 25;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    elemento.numero = 75;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    elemento.numero = 125;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    elemento.numero = 175;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    elemento.numero = 30;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    elemento.numero = 28;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    elemento.numero = 200;
    insertar(arbol, elemento);
    insertar(arbol2, elemento);
    cout << "Metodo de Colas" << endl;
    cout << "Antes: ";
    recorrerEnOrden(arbol.arbolBinario);
    cout << endl;
    eliminarHijosUnicos(arbol);
    cout << "Despues: ";
    recorrerEnOrden(arbol.arbolBinario);
    cout << endl << "----------------------------------------"
            << endl << "Metodo de Pilas" << endl;
    cout << "Antes: ";
    recorrerEnOrden(arbol2.arbolBinario);
    cout << endl;
//    eliminarHijosUnicosP(arbol2);
    eliminarHijosUnicosPV2(arbol2);
    cout << "Despues: ";
    recorrerEnOrden(arbol2.arbolBinario);
    return 0;
}

