/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kalef Mandujano
 *
 * Descripción del código
 * 
 * Created on 8 de julio de 2025, 10:48 AM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"

using namespace std;

NodoArbol *buscarNodo(NodoArbol *raiz,Elemento aux){
    NodoArbol *rec = raiz;
    while(true){
        if(rec->elemento.numero == aux.numero) return rec;
        if(aux.numero < rec->elemento.numero){
            rec = rec->izquierda;
        }else{
            rec = rec->derecha;
        }
    }
}

void diagonal_inv(ArbolBinario arbol){
    NodoArbol *rec = arbol.raiz;
    Cola aux;
    Pila impresion;
    construir(aux); //Encola las izquierdas
    construir(impresion); //Muestra la solucion
    encolar(aux,rec->elemento);
    Elemento temp;
    while(!esColaVacia(aux)){
        temp = desencolar(aux);
        rec = buscarNodo(arbol.raiz,temp);
        while(rec){
            if(rec->izquierda){
                encolar(aux,rec->izquierda->elemento);
            }
            apilar(impresion,rec->elemento);
            rec = rec->derecha;
        }
        
    }
    //Imprimimos la solución
    cout<<"Diagonal inversa"<<endl;
    imprimir(impresion);
    cout<<endl;
}

void diagonal(ArbolBinario arbol){
    NodoArbol *rec = arbol.raiz;
    Cola aux, impresion;
    construir(aux); //Encola las izquierdas
    construir(impresion); //Muestra la solucion
    encolar(aux,rec->elemento);
    Elemento temp;
    while(!esColaVacia(aux)){
        temp = desencolar(aux);
        rec = buscarNodo(arbol.raiz,temp);
        while(rec){
            if(rec->izquierda){
                encolar(aux,rec->izquierda->elemento);
            }
            encolar(impresion,rec->elemento);
            rec = rec->derecha;
        }
        
    }
    //Imprimimos la solución
    cout<<"Diagonal original"<<endl;
    imprimir(impresion);
    cout<<endl;
    
}



void insertarIterativo(ArbolBinario &arbol,Elemento aux){ 
    
    if(arbol.raiz == nullptr){
        arbol.raiz = new NodoArbol;
        arbol.raiz->elemento = aux;
        arbol.raiz->izquierda = nullptr;
        arbol.raiz->derecha = nullptr;
        return;
    }
    
    NodoArbol *rec = arbol.raiz;
    NodoArbol *actual;
    while(rec){
        actual = rec;
        if(aux.numero < rec->elemento.numero){
            rec = rec->izquierda;
        }else{
            rec = rec->derecha;
        }      
    }
    NodoArbol *nuevo = new NodoArbol;
    nuevo->elemento = aux;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    if(aux.numero < actual->elemento.numero){
        actual->izquierda = nuevo;
       
    }else{
        actual->derecha = nuevo;
       
    }
    
}


int main(int argc, char** argv) {

    ArbolBinarioBusqueda arbol;
    
    construir(arbol);

    Elemento aux;
    aux.numero = 100;
    aux.valor = 0;
    
    insertarIterativo(arbol.arbolBinario,aux);
    
    aux.numero = 150;
    aux.valor = 0;
    
    insertarIterativo(arbol.arbolBinario,aux);
    
    aux.numero = 50;
    aux.valor = 0;
    
    insertarIterativo(arbol.arbolBinario,aux);
    
    
    aux.numero = 175;
    aux.valor = 0;
    
    insertarIterativo(arbol.arbolBinario,aux);
    
    aux.numero = 200;
    aux.valor = 0;
    
    insertarIterativo(arbol.arbolBinario,aux);
    
    aux.numero = 125;
    aux.valor = 1;
    
    insertarIterativo(arbol.arbolBinario,aux);
    
    aux.numero = 75;
    aux.valor = 0;
    
    insertarIterativo(arbol.arbolBinario,aux);
    
    aux.numero = 25;
    aux.valor = 0;
    
    insertarIterativo(arbol.arbolBinario,aux);
    
    aux.numero = 40;
    aux.valor = 0;
    
    insertarIterativo(arbol.arbolBinario,aux);
    
//    recorrerEnOrden(arbol.arbolBinario);
    
    diagonal(arbol.arbolBinario);
    diagonal_inv(arbol.arbolBinario);
    
    return 0;
}

