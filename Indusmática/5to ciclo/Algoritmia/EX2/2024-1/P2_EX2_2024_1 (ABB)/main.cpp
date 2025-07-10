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
 * Created on 6 de julio de 2025, 05:58 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "Elemento.h"
#include "PesosEmociones.h"
#include "funcionesAB.h"
#include "funcionesCola.h"
#include "Cola.h"
#include "Pila.h"
#include "funcionesPila.h"


using namespace std;

#define N 3

int Alegria[3]={180,200};
int Tristeza[3]={140,230,80};
int Temor[3]={240,100};
int Furia[3]={280};
int Desagrado[3]={250};
int Ansiedad[3]={260,120};
int Envidia[3]={160,240};
int Verguenza[3]={120,80};
int Aburrimiento[3]={150,230,90};



void insertarIterativo(NodoArbol *&raiz,Elemento dato){
    NodoArbol *rec;
    
    if(raiz == nullptr){
        raiz = new NodoArbol;
        raiz->elemento = dato;
        raiz->derecha = nullptr;
        raiz->izquierda = nullptr;

        return;
    }
    
    NodoArbol *actual = raiz;
    
    while(actual!= nullptr){
        rec = actual;
        
        if(dato.numero < actual->elemento.numero){
            //Nos vamos a la izquierda
            actual = actual->izquierda;
        }else{
            //Nos vamos a la derecha
            actual = actual->derecha;
        }
    }
    
    NodoArbol *nuevo = new NodoArbol;
    nuevo->elemento = dato;
    nuevo->derecha = nullptr;
    nuevo->izquierda = nullptr;
    
    if(rec->elemento.numero > nuevo->elemento.numero){
        rec->izquierda = nuevo;
    }else{
        rec->derecha = nuevo;
    }
    
    
    
    
}

void insertarValor(ArbolBinario &arbol,Elemento dato){
    insertarIterativo(arbol.raiz,dato);
}


void copiarValores(int *arr1, int *arr2){
    for (int i = 0; i < 3; i++) {
        arr1[i] = arr2[i];
    }

}

NodoArbol *buscarNodo(NodoArbol *raiz, Elemento temp){
    while(raiz){
        if(raiz->elemento.numero == temp.numero) return raiz;
        if(raiz->elemento.numero > temp.numero){
            raiz = raiz->izquierda;
        }else{
            raiz = raiz->derecha;
        }
    }
    return nullptr;
}

bool cumple(NodoArbol *rec,struct PesosEmociones Combinaciones){
    for (int i = 0; i < 3; i++) {
        if(rec->elemento.numero == Combinaciones.pesos[i]) return true;
    }
    return false;
}

void hallarCombinaciones(ArbolBinario arbol,struct PesosEmociones Combinaciones[][N]){
    int numeroComb = 0;
    int j = 0;
    int nivel = 0;
    int soluciones;
    int cant;
    bool cumplio;
    Cola aux, solucion;
    construir(aux);
    construir(solucion);
    
    
    Elemento temp;
    temp = arbol.raiz->elemento;
    
    encolar(aux,temp);
    NodoArbol *rec, *rec2;
    
    while(!esColaVacia(aux)){      
        soluciones = 0;
        cant = aux.lista.longitud;
        cumplio = false;
        for (int i = 0; i < cant; i++) {
            //Realizamos la verificacion
            struct Pila ver;
            construir(ver);
            
            temp = desencolar(aux);
            rec = buscarNodo(arbol.raiz,temp);
            //Verificamos si cumple las condiciones
            apilar(ver,temp);
            j = 0;
            bool inicio = true;
            int cont = 0;
            while(!esPilaVacia(ver) and j !=3){
                temp = desapilar(ver);
                rec2 = buscarNodo(arbol.raiz,temp);
                if(cumple(rec2,Combinaciones[numeroComb][j])){
                    //Apilamos izquierda y derecha
                    if(cont == 0 and not inicio) break;
                    if(rec2->izquierda) apilar(ver,rec2->izquierda->elemento);
                    if(rec2->derecha) apilar(ver,rec2->derecha->elemento);
                    cumplio = true;
                    j++;
                }else{
                    cumplio = false;
                    cont--;
                }
                
            }
            if(j == 3) numeroComb++;
            if(cumplio)soluciones++;
            if(numeroComb == 3) break;
            if(rec->izquierda) encolar(aux,rec->izquierda->elemento);
            if(rec->derecha) encolar(aux,rec->derecha->elemento);
        }
        cout<<"Nivel "<<nivel+1<<" - "<<soluciones<<" combinaciones"<<endl;
        nivel++;
        if(numeroComb == 3) break;   
    }
   
    
}



int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    
    construir(arbol);
    
    Elemento aux;
    aux.numero = 180;
    
    insertarValor(arbol.arbolBinario,aux);
//    insertarIterativo(arbol.arbolBinario.raiz,aux);
    
    aux.numero = 120;
    
    insertarValor(arbol.arbolBinario,aux);
//    insertarIterativo(arbol.arbolBinario.raiz,aux);

    
    aux.numero = 250;
    insertarValor(arbol.arbolBinario,aux);

//    insertarIterativo(arbol.arbolBinario.raiz,aux);

    
    //Rama izquierda
    
    aux.numero = 150;
    insertarValor(arbol.arbolBinario,aux);

//    insertarIterativo(arbol.arbolBinario.raiz,aux);

    aux.numero = 100;
    
    insertarIterativo(arbol.arbolBinario.raiz,aux);
 
    aux.numero = 80;
    
    insertarIterativo(arbol.arbolBinario.raiz,aux);
 
    aux.numero = 90;
    insertarIterativo(arbol.arbolBinario.raiz,aux);
 
    aux.numero = 140;
    insertarIterativo(arbol.arbolBinario.raiz,aux);

    
    aux.numero = 160;
    insertarIterativo(arbol.arbolBinario.raiz,aux);
    
    //Rama derecha
    aux.numero = 230;
    insertarIterativo(arbol.arbolBinario.raiz,aux);
    
    aux.numero = 280;
    insertarIterativo(arbol.arbolBinario.raiz,aux);

    aux.numero = 200;
    insertarIterativo(arbol.arbolBinario.raiz,aux);

    aux.numero = 240;
    insertarIterativo(arbol.arbolBinario.raiz,aux);

    aux.numero = 260;
    insertarIterativo(arbol.arbolBinario.raiz,aux);
    
    struct PesosEmociones ansiedad;
    copiarValores(ansiedad.pesos,Ansiedad);
    struct PesosEmociones aburrimiento;
    copiarValores(aburrimiento.pesos,Aburrimiento);
    struct PesosEmociones tristeza;
    copiarValores(tristeza.pesos,Tristeza);
    struct PesosEmociones desagrado;
    copiarValores(desagrado.pesos,Desagrado);
    struct PesosEmociones temor;
    copiarValores(temor.pesos,Temor);
    struct PesosEmociones verguneza;
    copiarValores(verguneza.pesos,Verguenza);
    
    
    struct PesosEmociones Combinaciones[3][3] {{ansiedad,aburrimiento,tristeza},
                                {desagrado,tristeza,temor},
                                {temor,verguneza,aburrimiento}};
    
    
//    recorrerEnOrden(arbol.arbolBinario);
    
    hallarCombinaciones(arbol.arbolBinario,Combinaciones);
    
    
    
    
    return 0;
}

