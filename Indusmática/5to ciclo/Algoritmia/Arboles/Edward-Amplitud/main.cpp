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

NodoArbol* buscarEle(NodoArbol*p,Elemento&ele){
    
    if(not p){
        cout<<"no hay"<<endl;
        return nullptr;
    }
    
    if(ele.numero==p->elemento.numero)
        return p;
    
    
    
    if(ele.numero>p->elemento.numero)
        return buscarEle(p->derecha,ele);
    
    else 
        return buscarEle(p->izquierda,ele);
    
}

void amplitud(ArbolBinarioBusqueda& arbol){
    
    Cola cola;
    construir(cola);
    
    NodoArbol*p=arbol.arbolBinario.raiz;
    
    Elemento ele;
    ele=p->elemento;
    
    encolar(cola,ele);
    while(!esColaVacia(cola)){
        ele=desencolar(cola);
        p=buscarEle(arbol.arbolBinario.raiz,ele);
        if(p->izquierda)
            encolar(cola,p->izquierda->elemento);
        if(p->derecha)
            encolar(cola,p->derecha->elemento);
        cout<<p->elemento.numero<<" ";        
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
