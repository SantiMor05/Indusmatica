/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 23 de mayo de 2025, 12:03
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Elemento.h"
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
/*
 * 
 */

void ordenaColaRecursivo(Cola &cola, int n, int opcion){
    Elemento max, aux;
    if (esColaVacia(cola)) return;
        max = desencolar(cola);
        for (int i = 1; i < n; i++) {
            aux = desencolar(cola);
            if (opcion){
                if (max.horaF<aux.horaF){
                encolar(cola,max);
                max = aux;
                }else encolar(cola,aux);
            }else{
                if (max.horaI<aux.horaI){
                encolar(cola,max);
                max = aux;
                }else encolar(cola,aux);
            }
        }
    ordenaColaRecursivo(cola,n-1,opcion);
    encolar(cola,max);
}

int main(int argc, char** argv) {
    Cola cola;
    construir(cola);
    Elemento elemento;
    elemento.numero = 2101;
    elemento.horaI = 55;
    elemento.horaF = 15;
    encolar(cola,elemento);
    
    elemento.numero = 1102;
    elemento.horaI = 145;
    elemento.horaF = 145;
    encolar(cola,elemento);
    
    elemento.numero = 4111;
    elemento.horaI = 30;
    elemento.horaF = 30;
    encolar(cola,elemento);
    
    elemento.numero = 2105;
    elemento.horaI = 122;
    elemento.horaF = 210;
    encolar(cola,elemento);
    
    elemento.numero = 3108;
    elemento.horaI = 525;
    elemento.horaF = 525;
    encolar(cola,elemento);
    
    ordenaColaRecursivo(cola,cola.lista.longitud,0);
    cout<<"ITINERARIO DE LLEGADAS INICIAL: "<<endl;
    imprimir(cola);
    cout<<endl;
    
    ordenaColaRecursivo(cola,cola.lista.longitud,1);
    cout<<"ITINERARIO DE LLEGADAS ACTUALIZADO: "<<endl;
    imprimir(cola);
    
    
    return 0;
}

