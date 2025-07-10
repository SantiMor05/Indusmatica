/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 10 de julio de 2025, 16:39
 */

#include <iostream>
using namespace std;
#include "Pila.h"
#include "funcionesLista.h"
#include "Elemento.h"
#include "funcionesPila.h"
/*
 * 
 */

void copiaPilaRecursivo(Pila &pila, Pila &pila2){
    if (esPilaVacia(pila)) return;
    Elemento temp = desapilar(pila);
    copiaPilaRecursivo(pila,pila2);
    apilar(pila,temp);
    apilar(pila2,temp);
}

int main(int argc, char** argv) {
    Pila pila, pila2;
    construir(pila);
    construir(pila2);
    Elemento temp;
    temp.numero = 2;
    apilar(pila,temp);
    temp.numero = 6;
    apilar(pila,temp);
    temp.numero = 8;
    apilar(pila,temp);
    temp.numero = 4;
    apilar(pila,temp);
    temp.numero = 10;
    apilar(pila,temp);
    
    copiaPilaRecursivo(pila,pila2);
    imprimir(pila);
    cout<<endl;
    imprimir(pila2);
    
    return 0;
}

