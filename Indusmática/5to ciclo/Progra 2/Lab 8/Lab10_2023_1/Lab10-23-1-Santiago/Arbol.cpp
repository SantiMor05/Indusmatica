/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 21:32
 */

#include "Arbol.h"
#include "Boleta.h"
#include "Nodo.h"

Arbol::Arbol() {
    raiz = nullptr;
}

//Arbol::Arbol(const Arbol& orig) {
//}

Arbol::~Arbol() {
}

void Arbol::cargaalumnos(ifstream &arch){
    
    char tipo;
    Boleta boleta;
    while(true){
        arch >> tipo;
        if(arch.eof())break;
        arch.get();
        boleta.asignaMemoria(tipo);
        boleta.lee(arch);
        insertaR(raiz, boleta);
    }
    boleta.inicializa();    
}


void Arbol::insertaR(Nodo *&arbol, Boleta &boleta){
    
    if(arbol == nullptr){
        arbol = new Nodo;
        arbol->dboleta = boleta;
    }
    else{
        if(arbol->dboleta < boleta)
            insertaR(arbol->izq, boleta);
        else
            insertaR(arbol->der, boleta);
    }
    
}

void Arbol::imprimeBoletas(ofstream &arch){
    
    imprimeR(raiz, arch);
    
}

void Arbol::imprimeR(Nodo *raiz, ofstream &arch){
    
    if(raiz == nullptr) return;
    
    imprimeR(raiz->izq, arch);
    raiz->dboleta.imprime(arch);
    imprimeR(raiz->der, arch);
}

void Arbol::leerEscalas(ifstream &arch){
    
    Escala escala;
    
    while(true){
        escala.lee(arch);
        if(arch.eof())break;
        lescala[escala.GetCodigo() - 1] = escala;
    }
    
}


void Arbol::recorreActualiza(Nodo *raiz){
    
    
    if(raiz == nullptr)return;
    int escala;
    recorreActualiza(raiz->izq);
    escala = raiz->dboleta.obtenEscala();
    raiz->dboleta.actualizatotal(lescala[escala - 1].GetPrecio());
    recorreActualiza(raiz->der);
    
}

void Arbol::actualizaArbol(){
    recorreActualiza(raiz);
}