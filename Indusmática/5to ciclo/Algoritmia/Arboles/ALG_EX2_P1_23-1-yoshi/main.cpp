/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 4 de julio de 2025, 23:01
 */

#include <cstdlib>
#include <iostream>
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "Cola.h"
#include "funcionesCola.h"

using namespace std;

/*
 * 
 */

NodoArbol* buscarRecursion(NodoArbol* raiz,Elemento temp){
    if (raiz){
        if (raiz->elemento.numero == temp.numero)
            return raiz;
        else{
            if (raiz->elemento.numero < temp.numero)
                return buscarRecursion(raiz->derecha,temp);
            else return buscarRecursion(raiz->izquierda,temp);
        }
    }else{
        return nullptr;
    }
}

void imprimirEnPreOrden(const ArbolBinario &arbol){
    Pila pila; construir(pila);
    NodoArbol* recorrido = arbol.raiz;
    apilar(pila,recorrido->elemento);
    Elemento temp;
    while(!esPilaVacia(pila)){
        temp = desapilar(pila);
        recorrido = buscarRecursion(arbol.raiz,temp);
        cout << temp.numero << "  ";
        if (recorrido->derecha) apilar(pila,recorrido->derecha->elemento);
        if (recorrido->izquierda) apilar(pila,recorrido->izquierda->elemento);
    }
}

void imprimirEnPostOrden(const ArbolBinario &arbol){
    Pila pila, pilaImp;
    construir(pila);
    construir(pilaImp);
    NodoArbol* recorrido = arbol.raiz;
    apilar(pila,recorrido->elemento);
    Elemento temp;
    while(!esPilaVacia(pila)){
        temp = desapilar(pila);
        apilar(pilaImp,temp);
        recorrido = buscarRecursion(arbol.raiz,temp);
        if (recorrido->derecha) apilar(pila,recorrido->derecha->elemento);
        if (recorrido->izquierda) apilar(pila,recorrido->izquierda->elemento);
    }
    imprimir(pilaImp);
}

NodoArbol* MayorArbol(NodoArbol* raiz){
    if (raiz->derecha){
        return MayorArbol(raiz->derecha);
    }else{
        return raiz;
    }
}

void insertarEnArbolEspecial(ArbolBinarioBusqueda &arbol, Elemento &temp){
    if (buscar(arbol,temp)){
        NodoArbol* mayor = MayorArbol(arbol.arbolBinario.raiz);
        temp.numero += mayor->elemento.numero;
    }
    insertar(arbol,temp);
}

void diagonalRD(ArbolBinario arbol){
    Cola cola, colaImp;
    construir(cola);
    construir(colaImp);
    NodoArbol* recorrido = arbol.raiz;
    encolar(cola,recorrido->elemento);
    Elemento temp;
    while(!esColaVacia(cola)){
        temp = desencolar(cola);
        recorrido = buscarRecursion(arbol.raiz,temp);
        while(recorrido){
            encolar(colaImp,recorrido->elemento);
            if (recorrido->izquierda) encolar(cola,recorrido->izquierda->elemento);
            recorrido = recorrido->derecha;
        }
    }
    imprimir(colaImp);
}

void diagonalRU(ArbolBinario arbol){
    Pila pilaImp; construir(pilaImp);
    Pila pila; construir(pila);
    NodoArbol* recorrido = arbol.raiz;
    apilar(pila,recorrido->elemento);
    Elemento temp;
    while(!esPilaVacia(pila)){
        temp = desapilar(pila);
        recorrido = buscarRecursion(arbol.raiz,temp);
        while(recorrido){
            apilar(pilaImp,recorrido->elemento);
            if (recorrido->derecha) apilar(pila,recorrido->derecha->elemento);
            recorrido = recorrido->izquierda;
        }
        while(!esPilaVacia(pilaImp)){
            temp = desapilar(pilaImp);
            cout<<temp.numero<<"  ";
        }
    }
}

void diagnoalLU(ArbolBinario arbol){
    Cola cola; construir(cola);
    Pila pilaImp; construir(pilaImp);
    NodoArbol* recorrido = arbol.raiz;
    encolar(cola,recorrido->elemento);
    Elemento temp;
    while(!esColaVacia(cola)){
        temp = desencolar(cola);
        recorrido = buscarRecursion(arbol.raiz,temp);
        while(recorrido){
            apilar(pilaImp,recorrido->elemento);
            if (recorrido->izquierda) encolar(cola,recorrido->izquierda->elemento);
            recorrido = recorrido->derecha;
        }
    }
    while(!esPilaVacia(pilaImp)){
            temp = desapilar(pilaImp);
            cout<<temp.numero << "  ";
        }
}

void diagonalLD(ArbolBinario arbol){
    Cola cola; construir(cola);
    Cola colaImp; construir(colaImp);
    NodoArbol* recorrido  = arbol.raiz;
    encolar(cola,recorrido->elemento);
    Elemento temp;
    while(!esColaVacia(cola)){
        temp = desencolar(cola);
        recorrido = buscarRecursion(arbol.raiz,temp);
        while(recorrido){
            encolar(colaImp,recorrido->elemento);
            if (recorrido->derecha) encolar(cola,recorrido->derecha->elemento);
            recorrido = recorrido->izquierda;
        }
    }
    imprimir(colaImp);
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    Elemento temp;
    
    temp.numero = 2;
    insertarEnArbolEspecial(arbol,temp);
    
    temp.numero = 5;
    insertarEnArbolEspecial(arbol,temp);
    
    temp.numero = 2;
    insertarEnArbolEspecial(arbol,temp);
    
    temp.numero = 1;
    insertarEnArbolEspecial(arbol,temp);
    
    temp.numero = 5;
    insertarEnArbolEspecial(arbol,temp);
    
    temp.numero = 6;
    insertarEnArbolEspecial(arbol,temp);
    
    temp.numero = 3;
    insertarEnArbolEspecial(arbol,temp);
   
    temp.numero = 4;
    insertarEnArbolEspecial(arbol,temp);
    
    cout<<esEquilibrado(arbol.arbolBinario)<<endl;
    imprimirEnPreOrden(arbol.arbolBinario);
    cout<<endl;
    imprimirEnPostOrden(arbol.arbolBinario);
    cout<<endl;
    diagonalRD(arbol.arbolBinario);
    cout<<endl;
    diagonalRU(arbol.arbolBinario);
    cout<<endl;
    diagnoalLU(arbol.arbolBinario);
    cout<<endl;
    diagonalLD(arbol.arbolBinario);
    return 0;
}

