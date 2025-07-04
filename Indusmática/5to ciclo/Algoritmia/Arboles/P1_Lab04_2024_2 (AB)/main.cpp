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
 * Created on 3 de julio de 2025, 05:39 PM
 */

#include <iostream>
#include <iomanip>
#include "ArbolB.h"
#include "Lista.h"
#include "funcionesAB.h"
#include "funcionesLista.h"

using namespace std;

void imprimeArbol(NodoArbol *raiz, Lista &aux){
    Elemento temp;
    Nodo *sale;
    if(raiz){
        temp = raiz->elemento;
        insertarAlFinal(aux,temp);
        imprimeArbol(raiz->izquierda,aux);
        imprimeArbol(raiz->derecha,aux);
        if(raiz->izquierda == nullptr and raiz->derecha == nullptr){
            //Imprimimos
            imprime(aux); 
        }    
        eliminaCola(aux);
    }
//    sale = obtenerUltimoNodo(aux);
//    delete sale;
}

int main(int argc, char** argv) {
    
    ArbolBinario arbol1, arbol2, arbol3, arbol4, arbol5, arbol6, arbol7,
            arbol8, arbol9, arbol10, arbol11, arbol12, arbol13, arbol14,
            arbol15, arbol16, arbol17, arbol18, arbol19, arbol20, arbolFinal;
    
    construir(arbol1);
    construir(arbol2);
    construir(arbol3);
    construir(arbol4);
    construir(arbol5);
    
    Elemento letra;
    //Rama izquierda
    letra.letra = 'N';
    plantarArbolBinario(arbol1,nullptr,letra,nullptr);
    letra.letra = 'E';
    plantarArbolBinario(arbol2,arbol1.raiz,letra,nullptr);
    
    
    //Rama izquierda medio
    letra.letra = 'O';
    plantarArbolBinario(arbol4,nullptr,letra,nullptr);
    letra.letra = 'A';
    plantarArbolBinario(arbol5,arbol4.raiz,letra,nullptr);
    letra.letra = 'B';
    plantarArbolBinario(arbol6,arbol5.raiz,letra,nullptr);
    letra.letra = 'L';
    plantarArbolBinario(arbol7,arbol6.raiz,letra,nullptr);
    
    letra.letra = 'I';
    plantarArbolBinario(arbol3,arbol2.raiz,letra,arbol7.raiz);
    
    //Rama derecha
    letra.letra = 'S';
    plantarArbolBinario(arbol8,nullptr,letra,nullptr);
    letra.letra = 'O';
    plantarArbolBinario(arbol9,nullptr,letra,arbol8.raiz);
    letra.letra = 'A';
    plantarArbolBinario(arbol10,nullptr,letra,nullptr);
    letra.letra = 'R';
    plantarArbolBinario(arbol11,arbol10.raiz,letra,arbol9.raiz);
    letra.letra = 'R';
    plantarArbolBinario(arbol12,nullptr,letra,arbol11.raiz);
    
    //Rama medio derecha
    letra.letra = 'S';
    plantarArbolBinario(arbol13,nullptr,letra,nullptr);
    letra.letra = 'O';
    plantarArbolBinario(arbol14,nullptr,letra,arbol13.raiz);
    letra.letra = 'A';
    plantarArbolBinario(arbol15,nullptr,letra,nullptr);
    letra.letra = 'N';
    plantarArbolBinario(arbol16,arbol15.raiz,letra,arbol14.raiz);
    letra.letra = 'E';
    plantarArbolBinario(arbol17,arbol16.raiz,letra,nullptr);
    
    
    letra.letra = 'U';
    plantarArbolBinario(arbol18,arbol17.raiz,letra,arbol12.raiz);
    
    letra.letra = 'B';
    plantarArbolBinario(arbolFinal,arbol3.raiz,letra,arbol18.raiz);
    
//    recorrerEnOrden(arbolFinal);
    
    Lista aux;
    construir(aux);
    
    imprimeArbol(arbolFinal.raiz,aux);
    
    
    
    return 0;
}

