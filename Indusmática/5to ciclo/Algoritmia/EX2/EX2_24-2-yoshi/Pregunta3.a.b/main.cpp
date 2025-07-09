/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 8 de julio de 2025, 19:17
 */

#include <cstdlib>
#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
using namespace std;
#include "Cola.h"
#include "Pila.h"
#include "funcionesAB.h"
#include "funcionesPila.h"
#include "funcionesCola.h"

/*
 * 
 */

NodoArbol* buscarIterativo(const ArbolBinarioBusqueda &arbol,Elemento temp){
    NodoArbol* recorrido =  arbol.arbolBinario.raiz;
    if (recorrido==nullptr) return recorrido;
    while (recorrido!=nullptr){
        if (recorrido->elemento.flag == temp.flag and recorrido->elemento.numero == temp.numero)
            return recorrido;
        else{
            if (recorrido->elemento.numero > temp.numero){
                recorrido = recorrido->izquierda;
            }else
                recorrido = recorrido->derecha;
        }
    }
    return recorrido;
}

void recorridoRD(const ArbolBinarioBusqueda &arbol){
    Cola cola;
    construir(cola);
    NodoArbol* recorrido = arbol.arbolBinario.raiz;
    encolar(cola,recorrido->elemento);
    Elemento temp;
    while(!esColaVacia(cola)){
        temp = desencolar(cola);
        recorrido = buscarIterativo(arbol,temp);
        while(recorrido!=nullptr){
            cout<<recorrido->elemento.flag<<"-"<<recorrido->elemento.numero<<"  ";
            if (recorrido->izquierda)
                encolar(cola,recorrido->izquierda->elemento);
            recorrido = recorrido->derecha;
        }
    }
}

void recorridoUL(const ArbolBinarioBusqueda &arbol){
    Pila pilaImp;
    Cola cola;
    construir(cola); construir(pilaImp);
    NodoArbol* recorrido = arbol.arbolBinario.raiz;
    encolar(cola,recorrido->elemento);
    Elemento temp;
    while(!esColaVacia(cola)){
        temp = desencolar(cola);
        apilar(pilaImp,temp);
        recorrido = buscarIterativo(arbol,temp);
        while(recorrido!=nullptr){
            if (recorrido->derecha)
                apilar(pilaImp,recorrido->derecha->elemento);
            if (recorrido->izquierda)
                encolar(cola,recorrido->izquierda->elemento);
            recorrido = recorrido->derecha;
        }
    }
    while(!esPilaVacia(pilaImp)){
        temp = desapilar(pilaImp);
        cout<<temp.flag<<"-"<<temp.numero<<"  ";
    }
}

void insertaIterativo(ArbolBinarioBusqueda &arbol, Elemento temp){
    NodoArbol* nuevoNodo = new NodoArbol;
    nuevoNodo->derecha = nullptr;
    nuevoNodo->izquierda = nullptr;
    nuevoNodo->elemento = temp;
    if (arbol.arbolBinario.raiz == nullptr){
        arbol.arbolBinario.raiz = nuevoNodo;
        return;
    }
    NodoArbol* recorrido = arbol.arbolBinario.raiz;
    while(true){
        if (recorrido->elemento.numero > temp.numero){
            if (recorrido->izquierda == nullptr){
                recorrido->izquierda = nuevoNodo;
                return;
            }else{
                recorrido = recorrido->izquierda;
            }
        }else{
            if (recorrido->derecha == nullptr){
                recorrido->derecha = nuevoNodo;
                return;
            }else{
                recorrido = recorrido->derecha;
            }
        }
    }
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    Elemento temp;
    temp.flag = 0;
    temp.numero = 100;
    insertaIterativo(arbol,temp);
    temp.numero = 50;
    insertaIterativo(arbol,temp);
    temp.numero = 25;
    insertaIterativo(arbol,temp);
    temp.numero = 40;
    insertaIterativo(arbol,temp);
    temp.numero = 75;
    insertaIterativo(arbol,temp);
    temp.numero = 150;
    insertaIterativo(arbol,temp);
    temp.numero = 175;
    insertaIterativo(arbol,temp);
    temp.numero = 200;
    insertaIterativo(arbol,temp);
    temp.numero = 125;
    temp.flag = 1;
    insertaIterativo(arbol,temp);
    
    recorridoRD(arbol);
    cout<<endl;
    recorridoUL(arbol);
    
    return 0;
}

