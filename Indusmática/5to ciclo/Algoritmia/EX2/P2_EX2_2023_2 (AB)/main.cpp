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
 * Created on 7 de julio de 2025, 12:39 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "ArbolB.h"
#include "funcionesAB.h"
#include "funcionesLista.h"
#include "Lista.h"

#define VACIO ' '

bool cumple(Lista aux,char *palabras){
    Nodo *rec;
    int cont = 0;
    int cant = strlen(palabras);
    for (int i = 0; palabras[i]; i++) {
        
        rec = aux.cabeza;
        while(rec){
            if(rec->elemento.letra == palabras[i]){
//                rec->elemento.letra = VACIO;
                cont++;
                break;
            }
            rec = rec->siguiente;
        }
    }
    if(cont == cant) return true;
    return false;
    
    
}


void verificarRecursivo(NodoArbol *raiz,char *palabras,bool &band,Lista aux){
    Elemento temp;
    if(raiz){
        temp = raiz->elemento;
        insertarAlFinal(aux,temp);
        verificarRecursivo(raiz->izquierda,palabras,band,aux);
        verificarRecursivo(raiz->derecha,palabras,band,aux);
        if(raiz->izquierda == nullptr and raiz->derecha == nullptr and not band){
            //Verificamos los valores de la lista
            band = cumple(aux,palabras);
        }
        eliminaCola(aux);
    }
    
    
}



void hayPalabra(ArbolBinario arbolFinal,char *palabras,bool &band){
    Lista aux;
    construir(aux);
    verificarRecursivo(arbolFinal.raiz,palabras,band,aux);
}

int main(int argc, char** argv) {
    ArbolBinario arbol1,arbol2,arbol3,arbol4,
            arbol5,arbol6,arbol7,arbol8,arbol9,arbol10,
            arbol11,arbol12,arbol13,arbol15,arbolFinal;
    
    
    construir(arbol1);
    construir(arbol2);
    construir(arbol3);
    construir(arbol4);
    construir(arbol5);
    construir(arbol6);
    construir(arbol7);
    construir(arbol8);
    construir(arbol9);
    construir(arbol10);
    construir(arbol11);
    construir(arbol12);
    construir(arbol13);
    construir(arbol15);
    construir(arbolFinal);
    
    //Rama izquierda
    
    Elemento aux;
    aux.letra = 'E';
    
    plantarArbolBinario(arbol1,nullptr,aux,nullptr);
    
    aux.letra = 'T';
    plantarArbolBinario(arbol2,nullptr,aux,nullptr);
    
    aux.letra = 'G';
    plantarArbolBinario(arbol3,arbol2.raiz,aux,nullptr);
    
    aux.letra = 'R';
    plantarArbolBinario(arbol4,nullptr,aux,nullptr);
    
    aux.letra = 'E';
    plantarArbolBinario(arbol5,arbol4,aux,arbol3);
    
    aux.letra = 'D';
    plantarArbolBinario(arbol6,arbol1,aux,arbol5);
    
    //Rama derecha
    
    aux.letra = 'F';
    plantarArbolBinario(arbol7,nullptr,aux,nullptr);
    
    aux.letra = 'T';
    plantarArbolBinario(arbol8,nullptr,aux,nullptr);
    
    aux.letra = 'A';
    plantarArbolBinario(arbol9,arbol7,aux,arbol8);
    
    aux.letra = 'N';
    plantarArbolBinario(arbol10,arbol9.raiz,aux,nullptr);
    
    aux.letra = 'O';
    plantarArbolBinario(arbol11,nullptr,aux,nullptr);
    
    aux.letra = 'C';
    plantarArbolBinario(arbol12,arbol11.raiz,aux,nullptr);
    
    aux.letra = 'C';
    plantarArbolBinario(arbol13,arbol12.raiz,aux,nullptr);
    
    aux.letra = 'I';
    plantarArbolBinario(arbol15,arbol13,aux,arbol10);
    
    aux.letra = 'L';
    plantarArbolBinario(arbolFinal,arbol6,aux,arbol15);
    
    char *palabras[] ={"HIJO","FINAL","MUNDO","DEL","DIA","CICLO"};
    int n = 6;
    
    bool band = false;
    for (int i = 0; i < n; i++) {
        band = false; 
        hayPalabra(arbolFinal,palabras[i],band);
        if(band){
            cout<<palabras[i]<<" ";
        }
    }

    
    
    return 0;
}

