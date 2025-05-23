/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 22 de mayo de 2025, 18:39
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "Elemento.h"
#include "Cola.h"
#include "Pila.h"
#include "funcionesLista.h"

using namespace std;

/*
 * 
 */

void reordenar(Cola &cola){
    
    Pila pila;
    construir(pila);
    Elemento elemento, aux;
    
    while(!esColaVacia(cola)){
        elemento = desencolar(cola);
        if(elemento.tipo == 2) //Nos quedamos con ese en el buffer
            break;
        apilar(pila, elemento);
    }
    
    //Volvemos desapilamos y encolamos de nuevo
    while(!esPilaVacia(pila)){
        aux = desapilar(pila);
        encolar(cola,aux);
    }
    bool encontrado = false, entro = false;
    //desencolamos y encolamos hasta encontrar el tipo 1
    while(true){
        aux = desencolar(cola);
        if(aux.tipo == 1){
            entro = true;
            encontrado = true;
            apilar(pila, aux);
        }
        else{
            if(!entro)
                encolar(cola,aux);
            encontrado = false;
        }
        if(encontrado == false and entro == true)break;
    }
    
    int n = cola.lista.longitud;
    encolar(cola, elemento);
    encolar(cola, aux);
    
    for(int i = 0; i <n; i++){
        elemento = desencolar(cola);
        encolar(cola,elemento);
    }
    imprimir(cola);
    while(!esPilaVacia(pila)){
        elemento = desapilar(pila);
        encolar(cola,elemento);
        elemento = desencolar(cola);
        encolar(cola,elemento);
    }
    
        
}

int main(int argc, char** argv) {
    
    Cola cola;
    Elemento elemento;
    construir(cola);
    
    elemento.orden = 1;
    elemento.tipo = 1;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);
    
    elemento.orden = 2;
    elemento.tipo = 1;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);
    
    elemento.orden = 3;
    elemento.tipo = 1;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);
    
    elemento.orden = 4;
    elemento.tipo = 1;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);
    
    elemento.orden = 5;
    elemento.tipo = 1;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);
    
    elemento.orden = 6;
    elemento.tipo = 2;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);
    
    elemento.orden = 7;
    elemento.tipo = 2;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);
    
    elemento.orden = 8;
    elemento.tipo = 2;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);
    
    elemento.orden = 9;
    elemento.tipo = 2;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);
    
    elemento.orden = 10;
    elemento.tipo = 2;   //1:Sistema 2: Trabajador
    encolar(cola,elemento);

    imprimir(cola);
    
    reordenar(cola);
    
    imprimir(cola);
    
    return 0;
}

