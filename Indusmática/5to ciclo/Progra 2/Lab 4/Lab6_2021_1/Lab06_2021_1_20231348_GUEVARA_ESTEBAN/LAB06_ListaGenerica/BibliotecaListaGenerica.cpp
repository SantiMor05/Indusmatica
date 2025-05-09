/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.cpp
 * Author: esteban
 * 
 * Created on 8 de mayo de 2025, 16:40
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaListaGenerica.h"

enum lista{CABEZA,COLA};
enum nodo{DATO,SIG};
void creaLista(void* &lista,void* (*lee)(ifstream&),int (*cmp)(const void*,const void*),
        const char* nombreArch){
    ifstream archLee(nombreArch,ios::in);
    if (not archLee.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }

    
    void* reg;
    
    inicializaLista(lista);
    
    while (true) {
        reg= lee(archLee);
        
        
        if(archLee.eof()) break;
        insertarLista(reg,lista,cmp);
    }

    
}

void inicializaLista(void*&lst){
    void** lista= (void**) lst;
    
    lista= new void*[2]{};
    lista[CABEZA]= nullptr;
    lista[COLA]= nullptr;
    
    lst= lista;
}

void insertarLista(void *reg,void* lst,int (*cmp)(const void*,const void*)){
    
    void** lista=(void**) lst, **nuevoNodo,**nodoAnterior=nullptr,**nodoActual;
    
    //creamos primero el nodo a inserar
    nuevoNodo= new void*[2]{};
    nuevoNodo[DATO]= reg;

    
    nodoActual= (void**)lista[CABEZA];
    
    
    while (nodoActual) {
        if(cmp(nodoActual[DATO],reg)>0) break;
        //nodo anerior avanza
        nodoAnterior= nodoActual; 
        //avanza nodo actual
        nodoActual= (void**) nodoActual[SIG];
    }
    nuevoNodo[SIG]= nodoActual;

    if(nodoActual==nullptr) lista[COLA]= nuevoNodo;
    if(nodoAnterior==nullptr) lista[CABEZA]= nuevoNodo;
    else nodoAnterior[SIG]= nuevoNodo;
    
  
}

bool listavacia(void* lst){
    void** lista=(void**)lst;
    
    if(lista[CABEZA]) return true;
    else return false;
}

void uneLista(void *&lst1,void* lst2){
    void** lista1= (void**) lst1,**lista2=(void**)lst2;
    void** ultimoNodo1=(void**)lista1[COLA];
    
    ultimoNodo1[SIG]= lista2[CABEZA];
    lista1[COLA]= lista2[COLA];
    
    delete lista2;
    
    
    
}

void imprimeLista(void* lista1,void (*imprime)(void*,void*,ofstream &),
        const char* nombreArch){
    
    ofstream archReport(nombreArch,ios::out);
    if (not archReport.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    void** lista=(void**) lista1,**nodo,**nodoAnt=new void*[2]{};
    
    nodo= (void**) lista[CABEZA];
    
    while (nodo) {
        // como en la primera iteracion nodoAnt esta incializado si se puede
        // hae nodoAnt[DATO];
        imprime(nodoAnt[DATO],nodo[DATO],archReport);
        nodoAnt= nodo;
        nodo= (void**)nodo[SIG];
    }

    
} 
