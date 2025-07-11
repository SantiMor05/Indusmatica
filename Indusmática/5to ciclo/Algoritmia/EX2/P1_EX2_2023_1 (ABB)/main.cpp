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
 * Created on 4 de julio de 2025, 08:24 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>

#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"

using namespace std;

int buscarMaximoR(NodoArbol *raiz){
    if(raiz == nullptr) return 0;
    while(raiz->derecha){
        raiz = raiz->derecha;
    }
    return raiz->elemento.numero;
}


int buscarMaximo(ArbolBinario arbol){
    return buscarMaximoR(arbol.raiz);
}

void insertarNodo(ArbolBinario arbol,NodoArbol *&raiz,Elemento aux){
    if(raiz == nullptr){
        raiz = new NodoArbol;
        raiz->elemento = aux;
        raiz->derecha = nullptr;
        raiz->izquierda = nullptr;
        return;
    }
    if(raiz->elemento.numero == aux.numero){
        //Añadimos el máximo hasta ese momento
        int max = buscarMaximo(arbol);
        aux.numero += max;
    }
    if(raiz->elemento.numero > aux.numero){
        //Insertamos a la derecha
        insertarNodo(arbol,raiz->izquierda,aux);
    }else{
        //Insertamos a la izquierda
        insertarNodo(arbol,raiz->derecha,aux);
    }
}

void insertarR(NodoArbol *antiguo,NodoArbol *sale){
    if(antiguo == nullptr){
        antiguo = sale;
    }
    if(antiguo){
        if(sale->elemento.numero < antiguo->elemento.numero){
            //Se inserta a la izquierda
            insertarR(antiguo->izquierda,sale);
        }else{
            //Se inserta a la derecha
            insertarR(antiguo->derecha,sale);
        }
    }
}

void equilibrar(NodoArbol *&raiz,char car){
    NodoArbol *antiguo, *nuevo, *sale;
    if(car == 'I'){
        antiguo = raiz;
        nuevo = raiz->derecha;
        sale = nuevo->izquierda;
        
        //Rotamos
        nuevo->izquierda = antiguo;
        antiguo->derecha = sale;
        
        
    }else{
        antiguo = raiz;
        nuevo = raiz->izquierda;
        sale = nuevo->derecha;
        
        //Rotamos
        nuevo->derecha = antiguo;
        antiguo->izquierda = sale;
        
        
    }
    raiz = nuevo;
}

void balancea_Arbol(ArbolBinario &arbol){
    int fE, hI, hD;
    
    cout<<fE<<endl;
    while(true){
        hI = alturaRecursivo(arbol.raiz->izquierda);
        hD = alturaRecursivo(arbol.raiz->derecha);
        fE = abs(hI - hD);
        if(fE<=1) break;
        //Verificamos por donde está la descompensacion
        if(hI < hD){
            //Descompensado por derecha
            equilibrar(arbol.raiz,'I');
        }else{
            //Descompensado por izquierda
            equilibrar(arbol.raiz,'D');
        }
        
    }
    
}



int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    Elemento aux;
    aux.numero = 2;
    insertarNodo(arbol.arbolBinario,arbol.arbolBinario.raiz,aux);
    
    aux.numero = 5;
    insertarNodo(arbol.arbolBinario,arbol.arbolBinario.raiz,aux);
    
    aux.numero = 2;
    insertarNodo(arbol.arbolBinario,arbol.arbolBinario.raiz,aux);
    
    aux.numero = 1;
    insertarNodo(arbol.arbolBinario,arbol.arbolBinario.raiz,aux);
    
    aux.numero = 5;
    insertarNodo(arbol.arbolBinario,arbol.arbolBinario.raiz,aux);
    
    aux.numero = 6;
    insertarNodo(arbol.arbolBinario,arbol.arbolBinario.raiz,aux);
    
    aux.numero = 3;
    insertarNodo(arbol.arbolBinario,arbol.arbolBinario.raiz,aux);
    
    aux.numero = 4;
    insertarNodo(arbol.arbolBinario,arbol.arbolBinario.raiz,aux);
    
//    recorrerEnOrden(arbol.arbolBinario);
    
    balancea_Arbol(arbol.arbolBinario);
    
    recorrerEnOrden(arbol.arbolBinario);

    
    
    return 0;
}

