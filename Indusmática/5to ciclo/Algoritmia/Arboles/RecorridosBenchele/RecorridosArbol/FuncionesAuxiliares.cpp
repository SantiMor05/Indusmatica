/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: Lenovo
 * 
 * Created on 1 de julio de 2025, 09:37 PM
 */

#include <iostream>
#include <iomanip>
#include <ratio>
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Elemento.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "FuncionesAuxiliares.h"
using namespace std;

///////////////////////////////PREORDEN

NodoArbol *buscarNodoPreOrden(NodoArbol *pArbol, int numero){
    if(pArbol == nullptr)return nullptr;
    
    while (pArbol) {
        if(pArbol->elemento.numero == numero)return pArbol;
        if(pArbol->elemento.numero < numero){
            pArbol = pArbol->derecha;
        }
        else{
            pArbol = pArbol->izquierda;
        }
    }
    return pArbol;
}

void recorridoEnPreOrden(ArbolBinarioBusqueda arbol){    
    if(esArbolVacio(arbol.arbolBinario))return;
    
    Pila pila;
    construir(pila);
    
    NodoArbol * pRec = arbol.arbolBinario.raiz;
    
    apilar(pila, pRec->elemento);
    
    Elemento temp;
    
    while (!esPilaVacia(pila)) {
        temp = desapilar(pila);
        pRec = buscarNodoPreOrden(arbol.arbolBinario.raiz, temp.numero);
        
        if(pRec->derecha)apilar(pila, pRec->derecha->elemento);
        if(pRec->izquierda)apilar(pila, pRec->izquierda->elemento);
        
        cout << temp.numero << endl;
    }

}

void recorridoPreOrden(){ //RID 
    //10 8 7 9 13 12 14
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    Elemento temp;
    
    temp.numero = 10;
    insertar(arbol, temp);
    temp.numero = 8;
    insertar(arbol, temp);
    temp.numero = 13;
    insertar(arbol, temp);
    temp.numero = 12;
    insertar(arbol, temp);
    temp.numero = 14;
    insertar(arbol, temp);
    temp.numero = 7;
    insertar(arbol, temp);
    temp.numero = 9;
    insertar(arbol, temp);
    
    
    recorridoEnPreOrden(arbol);
    
    cout << endl;
    //recorrerPreOrden(arbol.arbolBinario);
}

///////////////////////////////////////////////////////////
///////////////////////////////INORDEN

NodoArbol *buscarNodoOrden(NodoArbol *pArbol, int numero){
    if(pArbol == nullptr)return pArbol;
    
    while (pArbol) {
        if(pArbol->elemento.numero == numero)return pArbol;
        if(pArbol->elemento.numero < numero){
            pArbol = pArbol->derecha;
        }
        else{
            pArbol = pArbol->izquierda;
        }
    }
    return pArbol;

}


void recorridoEnOrden(ArbolBinarioBusqueda arbol){
    if(esArbolVacio(arbol.arbolBinario))return;
    
    Pila pila;
    construir(pila);
    
    NodoArbol *pRec = arbol.arbolBinario.raiz;
    
    
    Elemento temp;
    
    while (!esPilaVacia(pila) || pRec) {
        while (pRec) {
            apilar(pila, pRec->elemento);
            pRec = pRec->izquierda;
        }
        
        temp = desapilar(pila);
        cout << temp.numero << " ";
        pRec = buscarNodoOrden(arbol.arbolBinario.raiz, temp.numero);
        pRec = pRec->derecha;
        
    }

}
void recorridoEnOrden(){ //IRD
    //7 8 9 10 12 13 14
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    Elemento temp;
    
    temp.numero = 10;
    insertar(arbol, temp);
    temp.numero = 8;
    insertar(arbol, temp);
    temp.numero = 13;
    insertar(arbol, temp);
    temp.numero = 12;
    insertar(arbol, temp);
    temp.numero = 14;
    insertar(arbol, temp);
    temp.numero = 7;
    insertar(arbol, temp);
    temp.numero = 9;
    insertar(arbol, temp);
    
    
    recorridoEnOrden(arbol);
    
    cout << endl;
    //recorrerEnOrden(arbol.arbolBinario);
}

/////////////////////////////////////////////////
///////////////////////////////POSTORDEN


NodoArbol *buscarNodoPostOrden(NodoArbol *pArbol, int numero){
    if(pArbol == nullptr)return nullptr;
    
    while (pArbol) {
        if(pArbol->elemento.numero == numero)return pArbol;
        if(pArbol->elemento.numero < numero){
            pArbol = pArbol->derecha;
        }
        else{
            pArbol = pArbol->izquierda;
        }
    }
    return pArbol;
}
void recorridoEnPostOrden(ArbolBinarioBusqueda arbol){
    if(esArbolVacio(arbol.arbolBinario))return;
    
    Pila pila1, pila2;
    //pila1 -> Trabajo
    //pila2 -> Guardar datos
    
    NodoArbol * pRec = arbol.arbolBinario.raiz;
    construir(pila1);
    construir(pila2);
    
    Elemento temp;
    apilar(pila1, pRec->elemento); 
    
    while (!esPilaVacia(pila1)) {
        temp = desapilar(pila1);
        pRec = buscarNodoPostOrden(arbol.arbolBinario.raiz, temp.numero);
        
        if(pRec->izquierda)apilar(pila1, pRec->izquierda->elemento);
        if(pRec->derecha)apilar(pila1, pRec->derecha->elemento);
        
        apilar(pila2, temp);
    }
    
    //Impresion
    while (!esPilaVacia(pila2)) {
        temp = desapilar(pila2);
        cout << temp.numero << " ";
    }    
}
void recorridoPostOrden(){ //IDR
    //7 9 8 12 14 13 10
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    Elemento temp;
    
    temp.numero = 10;
    insertar(arbol, temp);
    temp.numero = 8;
    insertar(arbol, temp);
    temp.numero = 13;
    insertar(arbol, temp);
    temp.numero = 12;
    insertar(arbol, temp);
    temp.numero = 14;
    insertar(arbol, temp);
    temp.numero = 7;
    insertar(arbol, temp);
    temp.numero = 9;
    insertar(arbol, temp);
    
    
    recorridoEnPostOrden(arbol);
    
    cout << endl;
    //recorrerPostOrden(arbol.arbolBinario);
}