/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de mayo de 2025, 23:23
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "funcionesCola.h"
#include "Elemento.h"
#include "Cola.h"

using namespace std;

/*
 * 
 */

void ordenar(Cola &cola, int n, int opcion){
    
      Elemento elemento, max;
    if(n == 1) return;
      max.horaLlegada = max.nuevaHora = 0;
    elemento = desencolar(cola);
    if(opcion == 1){
        if(max.horaLlegada < elemento.horaLlegada)
            max = elemento;
    } 
    else{
        if(max.nuevaHora < elemento.nuevaHora)
            max = elemento;
    }
    for(int i = 1; i < n; i++){
        elemento = desencolar(cola);
        if(opcion == 1){
            if(max.horaLlegada < elemento.horaLlegada){
            encolar(cola,max);
            max = elemento;
            }
            else
                encolar(cola,elemento); 
        }
        else{
            if(max.nuevaHora < elemento.nuevaHora){
            encolar(cola,max);
            max = elemento;
            }
            else
                encolar(cola,elemento);
        }
           
    }  
    
    ordenar(cola, n - 1,opcion);
    encolar(cola, max);
    
}

void ordenarCola(Cola &cola, int opcion){
    
    int n = cola.lista.longitud;
    
    ordenar(cola, n, opcion);
    
}


void actualizar(Cola &cola, Elemento sustituto){
    int n = cola.lista.longitud;
    Elemento elemento;
    for(int i = 0; i < n; i++){
        elemento = desencolar(cola);
        if(elemento.numero == sustituto.numero)
            elemento = sustituto;
        
        encolar(cola,elemento);
    }
    
}


int main(int argc, char** argv) {
    
    Cola cola;
    Elemento elemento;
    
    construir(cola);
    
    elemento.numero = 2101;
    elemento.horaLlegada = 55;
    elemento.nuevaHora = 55;
    encolar(cola, elemento);
    
    elemento.numero = 1102;
    elemento.horaLlegada = 145;
    elemento.nuevaHora = 145;
    encolar(cola, elemento);
    
    elemento.numero = 4111;
    elemento.horaLlegada = 30;
    elemento.nuevaHora = 30;
    encolar(cola, elemento);
    
    elemento.numero = 2105;
    elemento.horaLlegada = 122;
    elemento.nuevaHora = 122;
    encolar(cola, elemento);
    
    elemento.numero = 3108;
    elemento.horaLlegada = 525;
    elemento.nuevaHora = 525;
    encolar(cola, elemento);
    
    cout << "ANTES" << endl;
    imprimeCola(cola);
    ordenarCola(cola,1);
    cout << endl << "HORA DE LLEGADA: " << endl;
    imprimeCola(cola);

    
    elemento.numero = 2101;
    elemento.horaLlegada = 55;
    elemento.nuevaHora = 15;
    actualizar(cola, elemento);
    
    elemento.numero = 2105;
    elemento.horaLlegada = 122;
    elemento.nuevaHora = 210;
    actualizar(cola, elemento);
    
    ordenarCola(cola,2);
    cout << endl << "NUEVA HORA DE LLEGADA: " << endl;
    imprimeCola(cola);
    
    return 0;
}

