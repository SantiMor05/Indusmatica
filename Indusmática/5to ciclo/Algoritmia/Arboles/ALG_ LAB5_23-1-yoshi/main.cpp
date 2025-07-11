/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 4 de julio de 2025, 17:32
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "ArbolB.h"
#include "funcionesAB.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesABB.h"

using namespace std;

/*
 * 
 */

void buscar(NodoArbol* raiz,Elemento temp, NodoArbol* &recorrido,int &nivel, int niv){
    if (raiz){
        if (raiz->elemento.id == temp.id and raiz->elemento.numero==temp.numero){
            recorrido = raiz;
            nivel = niv;
            return;
        }else{
            buscar(raiz->derecha,temp,recorrido,nivel,niv+1);
            buscar(raiz->izquierda,temp,recorrido,nivel,niv+1);
        }
    }
}

void EncontrarSkyNerd(const ArbolBinario &arbol){
    Cola cola; construir(cola);
    NodoArbol* recorrido = arbol.raiz;
    encolar(cola,recorrido->elemento);
    Elemento temp;
    int nivel = 1;
    while(!esColaVacia(cola)){
        temp = desencolar(cola);
        buscar(arbol.raiz,temp,recorrido,nivel,1);
        if (recorrido->elemento.numero == 200){
            if (recorrido->derecha){
                if (recorrido->derecha->elemento.id == 'S' and recorrido->derecha->elemento.numero == 200){
                    cout<<"Encontré a SkyNerd en el nivel "<<nivel+1;
                    return;
                }
            }
            if (recorrido->izquierda){
                if (recorrido->izquierda->elemento.id == 'S' and recorrido->izquierda->elemento.numero == 200){
                    cout<<"Encontré a SkyNerd en el nivel "<<nivel+1;
                    return;
                }
            }
        }else{
            if (recorrido->derecha) encolar(cola,recorrido->derecha->elemento);
            if (recorrido->izquierda) encolar(cola,recorrido->izquierda->elemento);
        }
    }
    cout<<"NO encontré a SkyNerd";
}


int main(int argc, char** argv) {
    ArbolBinario arbol, arbol2, arbol3, arbol4, arbol5, arbol6, arbol7, arbol8, arbol9;
    Elemento temp;
    NodoArbol* izq, *der;
    
    construir(arbol);
    construir(arbol); construir(arbol2);
    construir(arbol3); construir(arbol4);
    construir(arbol5); construir(arbol6);
    construir(arbol7); construir(arbol8);
    construir(arbol9); 
    
    temp.id = 'S';
    temp.numero = 50;
    izq = new NodoArbol;
    izq->elemento.id = 'E';
    izq->elemento.numero = 50;
    izq->derecha = nullptr;
    izq->izquierda = nullptr;
    plantarArbolBinario(arbol6,izq,temp,nullptr);
    
    temp.id = 'Z';
    temp.numero = 200;
    izq = new NodoArbol;
    izq->elemento.id = 'E';
    izq->elemento.numero = 100;
    izq->derecha = nullptr;
    izq->izquierda = nullptr;
    plantarArbolBinario(arbol5,izq,temp,nullptr);
    
    temp.id = 'S';
    temp.numero = 50;
    plantarArbolBinario(arbol4,nullptr,temp,nullptr);
    
    temp.id = 'E';
    temp.numero = 100;
    plantarArbolBinario(arbol3,arbol6,temp,arbol5);
    
    temp.id = 'Z';
    temp.numero = 50;
    plantarArbolBinario(arbol2,arbol3,temp,arbol4);
    
    temp.id = 'S';
    temp.numero = 200;
    izq = new NodoArbol;
    izq->elemento.id = 'S';
    izq->elemento.numero = 100;
    izq->derecha = nullptr;
    izq->izquierda = nullptr;
    der = new NodoArbol;
    der->derecha = nullptr;
    der->izquierda = nullptr;
    der->elemento.id = 'E';
    der->elemento.numero = 200;
    plantarArbolBinario(arbol9,izq,temp,der);
    
    temp.id = 'S';
    temp.numero = 150;
    plantarArbolBinario(arbol8,nullptr,temp,nullptr);
    
    temp.id = 'E';
    temp.numero = 200;
    plantarArbolBinario(arbol7,arbol9,temp,arbol8);
    
    temp.id = 'Z';
    temp.numero = 100;
    plantarArbolBinario(arbol,arbol2,temp,arbol7);
    
    EncontrarSkyNerd(arbol);
    cout<<endl;
    recorrerEnOrden(arbol);
    
    return 0;
}

