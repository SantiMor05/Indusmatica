/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: 00123
 * 
 * Created on 18 de junio de 2025, 07:47 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Arbol.h"
#include "Nodo.h"
#include "Generico.h"
#include "Marca.h"
using namespace std;

Arbol::Arbol() {
    
    raiz=nullptr;
}

//Arbol::Arbol(const Arbol& orig) {
//}

void Arbol::leer(ifstream& arch) {

    int tipo;
    arch>>tipo;
    if(arch.eof())return;
    arch.get();
    
    Medicamento *med;
    switch(tipo){
        case 0:
            med=new Generico;
            break;
        case 1:
            med=new Marca;
            break;
    }
    med->leer(arch);
    insertarRecur(raiz,med);        
//    cuidado aca con el inicializar DEBOOO
//    med=nullptr;
}

void Arbol::imprimir(ofstream& arch) {

    arch.precision(2);
    arch<<fixed;
    imprimeRecur(raiz,arch);
}

void Arbol::imprimeRecur(Nodo* p, ofstream& arch) {

    if(not p)return;
    
    imprimeRecur(p->izq,arch);
    arch<<*(p->med);
    imprimeRecur(p->der,arch);
}

    


void Arbol::insertarRecur(Nodo* &p, Medicamento* med) {

    if(not p){
        p=new Nodo;
        p->med=med;
        return;
    }
    
    if(med->GetCodigo()>p->med->GetCodigo())
        insertarRecur(p->der,med);
    else insertarRecur(p->izq,med);
}



Arbol::~Arbol() {
    
    eliminaRecur(raiz);
}

void Arbol::eliminaRecur(Nodo* p) {

    if(not p)return;
    
    eliminaRecur(p->izq);
    eliminaRecur(p->der);
    delete p;
}


void Arbol::actualiza(ifstream& arch) {

    int codigo;
    while(true){
        arch>>codigo;
        if(arch.eof())break;
        analizarRecur(raiz,codigo);
    }
}

void Arbol::analizarRecur( Nodo*p,int codigo) {

    
    if(p->med->GetCodigo()==codigo){
        if(p->med->esDeMarca()){
            double precio=p->med->GetPrecio();
            p->med->SetPrecio(1.2*precio);
            return;
        }
        else return;
    }
    
    if(p->med->GetCodigo()<codigo)
            analizarRecur(p->der,codigo);
    else analizarRecur(p->izq,codigo);
}

