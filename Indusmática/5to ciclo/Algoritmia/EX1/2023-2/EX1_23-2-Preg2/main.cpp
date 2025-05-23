/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 22 de mayo de 2025, 13:04
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <functional>
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
#include "Cola.h"
#include "Pila.h"

using namespace std;

/*
 * 
 */

void ordenar(Pila &pila1, Pila aux) {
    Elemento elemento;
    Elemento menor; 
    int cont = 0, n =pila1.lista.longitud;
    for (int i = 0; i < n; i++) {
        menor = desapilar(pila1);
        for (int j = i + 1; j < n; j++) {
            elemento = desapilar(pila1);
            if (elemento.numero % 100 > menor.numero % 100) {
                apilar(aux, menor);
                //Guardamos el menor
                menor = elemento;
            } else
                apilar(aux, elemento);
        }
        //Apilamos el menor
        apilar(pila1, menor);
        while (!esPilaVacia(aux)) {
            elemento = desapilar(aux);
            apilar(pila1, elemento);
        }
    }

}

void reiniciaCola(Cola &cola, Pila &pila1,Pila &pila2, int n){
    
    Elemento elemento;
    
      while (!esPilaVacia(pila2)) {
        elemento = desapilar(pila2);
        apilar(pila1, elemento);
    }
    
    ordenar(pila1, pila2);
    
    //AZUL
    int num = n - pila1.lista.longitud;
    for(int i = 0; i < num; i++){
        elemento = desencolar(cola);
        encolar(cola,elemento);
    }
    num = pila1.lista.longitud;
    for(int i = 0; i < num; i++){
        elemento = desencolar(cola);
        apilar(pila2, elemento);
    }
    
    //VERDE
    while(!esPilaVacia(pila1)){
        elemento = desapilar(pila1);
        encolar(cola,elemento);
    }
    
    //Naranja
    num = n - pila2.lista.longitud;
    for(int i = 0; i < num; i++){
        elemento = desencolar(cola);
        encolar(cola,elemento);
    }
}


void imprime(Cola cola,Pila pila1,Pila pila2){
    
    
    cout << "Cola: ";
    imprimir(cola);
    cout << "Pila 1: ";
    imprimir(pila1);
    cout << "Pila 2: ";
    imprimir(pila2);
    cout << endl << endl;
}


void reclasifica_pilas(Pila &pila1, Pila &pila2){
    
    Cola aux;
    construir(aux);
    Elemento elemento;
    
    while(!esPilaVacia(pila2)){
        elemento = desapilar(pila2);
        encolar(aux, elemento);
    }
    
    while (!esColaVacia(aux)) {
        elemento = desencolar(aux);
        if (elemento.numero >= 200) {
            apilar(pila2, elemento);
        } else
            apilar(pila1, elemento);
    }
}


int main(int argc, char** argv) {

    Cola cola;
    Pila pila1, pila2;
    Elemento elemento;
    int n = 8;
    construir(cola);
    construir(pila1);
    construir(pila2);

    elemento.numero = 203;
    encolar(cola, elemento);

    elemento.numero = 204;
    encolar(cola, elemento);

    elemento.numero = 101;
    encolar(cola, elemento);

    elemento.numero = 102;
    encolar(cola, elemento);

    elemento.numero = 105;
    encolar(cola, elemento);

    elemento.numero = 206;
    encolar(cola, elemento);

    elemento.numero = 107;
    encolar(cola, elemento);

    elemento.numero = 208;
    encolar(cola, elemento);

    elemento.numero = 109;
    encolar(cola, elemento);

    elemento.numero = 210;
    encolar(cola, elemento);

    elemento.numero = 211;
    encolar(cola, elemento);

    elemento.numero = 112;
    encolar(cola, elemento);

    elemento.numero = 113;
    encolar(cola, elemento);


    while (true) {
        elemento = desencolar(cola);
        if (elemento.numero >= 200) {
            apilar(pila2, elemento);
        } else
            apilar(pila1, elemento);
        if (pila1.lista.longitud == 3 or pila2.lista.longitud == 3)
            break;
    }
    cout << "INICIAL" << endl;
    imprime(cola,pila1,pila2);

    
    cout << "REINICIA COLA" << endl;
    reiniciaCola(cola, pila1,pila2, 8);
    imprime(cola,pila1,pila2);
    
    reclasifica_pilas(pila1, pila2);
    cout << "RECLASIFICA PILAS" << endl;
    imprime(cola,pila1,pila2);
    
    return 0;
}

