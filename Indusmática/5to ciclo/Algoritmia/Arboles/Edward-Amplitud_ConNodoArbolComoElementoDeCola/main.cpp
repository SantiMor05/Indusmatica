/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 27 de octubre de 2024, 16:56
 */

#include <iostream>
using namespace std;
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "Elemento.h"
#include "funcionesAB.h"
#include "funcionesCola.h"
#include "Cola.h"
/*
 *  ARBOLES BINARIOS 2024-2
 *  Clase ABB
 */


void amplitud(ArbolBinarioBusqueda& arbol){
    
    Cola cola;
    cola.lista.cabeza=nullptr;
    cola.lista.cola=nullptr;
    
    NodoArbol*elementoCola;
    
    elementoCola=arbol.arbolBinario.raiz;
    
    encolar(cola,elementoCola);
    while(cola.lista.cabeza){
        elementoCola=desencolar(cola);
        if(elementoCola->izquierda)
            encolar(cola,elementoCola->izquierda);
        if(elementoCola->derecha)
            encolar(cola,elementoCola->derecha);
        cout<<elementoCola->elemento.numero<<" ";        
    }
}

int main(int argc, char** argv) {

    ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    Elemento ele;
    
    ele.numero=7;
    insertar(arbol,ele);
    
    ele.numero=3;
    insertar(arbol,ele);
    
    ele.numero=12;
    insertar(arbol,ele);
    
    ele.numero=2;
    insertar(arbol,ele);
    
    ele.numero=4;
    insertar(arbol,ele);
    
    ele.numero=5;
    insertar(arbol,ele);
    
    ele.numero=10;
    insertar(arbol,ele);
    
    ele.numero=15;
    insertar(arbol,ele);
    
    ele.numero=19;
    insertar(arbol,ele);
    
//    enOrden(arbol);
    
    amplitud(arbol);
    
    
    
    return 0;
}
