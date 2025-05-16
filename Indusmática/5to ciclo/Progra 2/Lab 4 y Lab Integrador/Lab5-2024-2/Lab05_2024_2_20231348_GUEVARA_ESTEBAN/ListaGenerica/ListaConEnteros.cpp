/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.cpp
 * Author: esteban
 * 
 * Created on 7 de mayo de 2025, 20:53
 */
#include <fstream>
using namespace std;
#include "ListaConEnteros.h"
//
//enum dupla{NUMERO,ARREGLO};
//enum regnumero{INDICE,ELEMENTO};
void * leenumeros(ifstream &archLeer){
    int *ptNumero= new int;
    void** dupla;
    archLeer>>*ptNumero;
    if(archLeer.eof()) return nullptr;
    
    
    return ptNumero;
    
}
//
//2 4
//2 2
//4 1

void* leeregnumeros(ifstream &archLee){
    void** dupla;
    
    int *ptIndice= new int,*ptElemento= new int;
    archLee>>*ptIndice;
    if(archLee.eof()) return nullptr;
    archLee>>*ptElemento;
    
    dupla= new void*[2]{};
    dupla[0]= ptIndice;
    dupla[1]= ptElemento;
    
    return dupla;
    
}

int compruebanumero(const void* datLista,const void* indice){
    
    void **datoLista=(void**) datLista;
    int *ptNumeroLista= (int*)datoLista[0],*ptNumeroIndice=(int*)indice;
//            *ptNumeroReg=(int*)datoReg[NUMERO];
    
    return *ptNumeroLista-*ptNumeroIndice;
    
    
}

void imprimenumeros(void* reg,ofstream& archReport){
    void** registro=(void**)reg, **arreglo;
    
    int* ptNumero=(int*) registro[0],*numeros;
    arreglo=(void**)registro[1];
    
    archReport<<*ptNumero<<endl;
    for (int i = 0; arreglo[i] ; i++) {
        numeros=(int*)arreglo[i];
        archReport<<*numeros<<" ";
    }
    archReport<<endl;

    
    
    
}