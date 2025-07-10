/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Asce
 * Curso: TP
 * Created on 9 de julio de 2025, 10:36 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "Elemento.h"
#include "Pila.h"
#include "funcionesPila.h"

/*
 * 
 */

void pasaPila(struct Pila &orig, struct Pila &clon) {
    if (esPilaVacia(orig)) return;
    struct Elemento aux;
    aux = desapilar(orig);
    pasaPila(orig, clon);
    apilar(clon, aux);
}

int main(int argc, char** argv) {
    struct Pila orig, clon;
    construir(orig);
    construir(clon);
    struct Elemento elem;
    elem.tipo = 0;
    for (int i = 0; i < 10; i++) {
        elem.numero = i;
        apilar(orig, elem);   
    }
    cout<<"Pila original inicio:"<<endl;
    imprimir(orig);
    cout<<endl<<"Pila clon inicio:"<<endl;
    imprimir(clon);
    pasaPila(orig, clon);
    cout<<endl<<"Pila original final: "<<endl;
    imprimir(orig);
    cout<<endl<<"Pila clon final: "<<endl;
    imprimir(clon);
    return 0;
}

