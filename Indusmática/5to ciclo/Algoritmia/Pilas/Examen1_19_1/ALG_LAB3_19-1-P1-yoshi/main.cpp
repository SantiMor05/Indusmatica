/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 15 de mayo de 2025, 12:30
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Elemento.h"
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
/*
 * 
 */
void cambiar(Elemento &a,Elemento &b){
    Elemento aux = a;
    a = b;
    b = aux;
}

int formar(Elemento elemento){
    return elemento.anho*10000 + elemento.dd + elemento.mes*100;
}

void ordenarPila(Pila &pila, Pila &pila2,int n){
    if (n==1) return;
    Elemento elemento, antiguo;
    int numAntiguo, numero;
    antiguo = desapilar(pila);
    for(int i=1; i<=n-1; i++){
        elemento = desapilar(pila);
        numAntiguo = formar(antiguo);
        numero = formar(elemento);
        if (numero > numAntiguo){
            cambiar(antiguo,elemento);
        }
        apilar(pila2,elemento);
    }
    apilar(pila,antiguo);
    while(!esPilaVacia(pila2)){
        elemento = desapilar(pila2);
        apilar(pila,elemento);
    }
    ordenarPila(pila,pila2,n-1);
}

int main(int argc, char** argv) {
    Elemento elemento;
    Pila pila, pila2;
    construir(pila);
    construir(pila2);
    
    elemento.anho = 2018;
    elemento.mes = 05;
    elemento.dd = 20;
    apilar(pila,elemento);
    
    elemento.anho = 2025;
    elemento.mes = 04;
    elemento.dd = 18;
    apilar(pila,elemento);
    
    elemento.anho = 2024;
    elemento.mes = 4;
    elemento.dd = 18;
    apilar(pila,elemento);
    
    elemento.anho = 2016;
    elemento.mes = 04;
    elemento.dd = 23;
    apilar(pila,elemento);
    
    elemento.anho = 2024;
    elemento.mes = 04;
    elemento.dd = 8;
    apilar(pila,elemento);
    
    ordenarPila(pila,pila2,pila.lista.longitud);
    
    imprimir(pila);
    return 0;
}

