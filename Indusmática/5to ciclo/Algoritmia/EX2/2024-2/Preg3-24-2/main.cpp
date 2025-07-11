/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 9 de julio de 2025, 0:21
 */

#include <iostream>
#include "ArbolBB.h"
#include "Cola.h"
#include "funcionesABB.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "Pila.h"

using namespace std;

/*
 * 
 */

void llenar(ArbolBinarioBusqueda &arbol){
    
    Elemento elemento;
    
    elemento.flag = 0;
    elemento.id = 100;
    insertar(arbol, elemento);
    
    elemento.flag = 0;
    elemento.id = 50;
    insertar(arbol, elemento);
    
    elemento.flag = 0;
    elemento.id = 25;
    insertar(arbol, elemento);
    
    elemento.flag = 0;
    elemento.id = 75;
    insertar(arbol, elemento);
    
    elemento.flag = 0;
    elemento.id = 40;
    insertar(arbol, elemento);
    
    elemento.flag = 0;
    elemento.id = 150;
    insertar(arbol, elemento);
    
    elemento.flag = 0;
    elemento.id = 125;
    insertar(arbol, elemento);
    
    elemento.flag = 0;
    elemento.id = 175;
    insertar(arbol, elemento);
    
    elemento.flag = 0;
    elemento.id = 200;
    insertar(arbol, elemento);
    
    enOrden(arbol);
    
}


NodoArbol* buscarIterativo(NodoArbol *rec, Elemento elemento){
    
    while(rec){
        if(elemento.id < rec->elemento.id)
            rec = rec->izquierda;
        else if(elemento.id > rec->elemento.id)
            rec = rec->derecha;
        else
            return rec;
    }
    return nullptr;
}

void recorridoDiagonal(ArbolBinarioBusqueda &arbol){
    
    Cola cola1, cola2;
    Elemento elemento;
    NodoArbol *nodo = arbol.arbolBinario.raiz;
    
    construir(cola1);
    construir(cola2);
    elemento = nodo->elemento;
    encolar(cola2, elemento);
    
    while(!esColaVacia(cola2)){
        elemento = desencolar(cola2);
        nodo = buscarIterativo(arbol.arbolBinario.raiz, elemento);
        while(nodo){
            encolar(cola1, nodo->elemento);
            if(nodo->izquierda)
                encolar(cola2, nodo->izquierda->elemento);
            nodo = nodo->derecha;
        }
        //En la cola1 estan todos los elementos a imprimir
        //Esto se podría hacer afuera del while sin ningun problema
        while(!esColaVacia(cola1)){
            elemento = desencolar(cola1);
            cout << elemento.flag << "-" << elemento.id << "  ";
        }
    }
    cout << endl;    
}


void recorridoDiagonalInvertido(ArbolBinarioBusqueda &arbol){
    
    Cola cola;
    Pila pila;
    Elemento elemento;
    NodoArbol *nodo = arbol.arbolBinario.raiz;
    
    construir(cola);
    construir(pila);
    elemento = nodo->elemento;
    encolar(cola,elemento);
    
    while(!esColaVacia(cola)){
        elemento = desencolar(cola);
        nodo = buscarIterativo(arbol.arbolBinario.raiz, elemento);
        while(nodo){
            apilar(pila, nodo->elemento);
            if(nodo->izquierda)
                encolar(cola, nodo->izquierda->elemento);
            nodo = nodo->derecha;
        }
        //En la cola1 estan todos los elementos a imprimir
        
    }
    
    while(!esPilaVacia(pila)){
            elemento = desapilar(pila);
            cout << elemento.flag << "-" << elemento.id << "  ";
        }
    cout << endl;    
    
}


int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    llenar(arbol);
    cout << endl;
    recorridoDiagonal(arbol);
    recorridoDiagonalInvertido(arbol);

    return 0;
}

