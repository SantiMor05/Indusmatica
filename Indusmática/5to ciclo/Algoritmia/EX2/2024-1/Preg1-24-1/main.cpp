/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 9 de julio de 2025, 18:22
 */

#include <iostream>
#include "Elemento.h"
#include "Pila.h"
#include "funcionesPila.h"

using namespace std;

/*
 * 
 */


void clonarPila(Pila &pila, Pila &pilaClon){
    
    if(esPilaVacia(pila))return;
    
    Elemento elemento;
    elemento = desapilar(pila);
    
    clonarPila(pila, pilaClon);
    
    apilar(pila,elemento);
    apilar(pilaClon, elemento);
    
}

int main(int argc, char** argv) {
    
    Pila pila, pilaClon;
    Elemento elemento;
    
    construir(pila);
    construir(pilaClon);
    
    for(int i = 0; i < 10; i++){
        elemento.numero = i;
        apilar(pila, elemento);
    }
    
    clonarPila(pila, pilaClon);

    imprimir(pila);
    imprimir(pilaClon);
    
    return 0;
}




