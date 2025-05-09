/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.cpp
 * Author: 00123
 * 
 * Created on 8 de mayo de 2025, 04:54 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaListaGenerica.h"

using namespace std;

enum indices{CAB,COL};
enum ayuda{DAT,SIG};

void creaLista(void*&lis,void*(*leer)(ifstream &),
        int(*comparar)(const void*,const void*),const char*nombArch){
    
//    35912665,O2Z-308,22/07/2019,156
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch; exit(1);
    }
    lis=new void*[2]{};
    void*dato;
    while(true){
        dato=leer(arch);
        if(arch.eof())break;
        insertaLista(dato,lis,comparar);
    }
}

void insertaLista(void*dato,void*lis,
        int(*comparar)(const void*,const void*)){
    
    void**lista=(void**)lis;
    void**ant,*esValido=lista;
    obtenerAnt(dato,lista,comparar,ant,esValido);
    void**nuevo;
    if(esValido){
        if(ant){
            nuevo=crearNodo(dato,ant[SIG]);
            ant[SIG]=nuevo;
        } 
        else{
            nuevo=crearNodo(dato,lista[CAB]);
            lista[CAB]=nuevo;
        } 
        if(not nuevo[SIG]) lista[COL]=nuevo;
    }
}

void obtenerAnt(void*dato,void**lista,
        int(*comparar)(const void*,const void*),
        void**&ant,void*&esValido){
    
    void**p=(void**)lista[CAB];
    ant=nullptr;
    while(p){
        if(comparar(dato,p[DAT])<0)break;
        else if(comparar(dato,p[DAT])==0){
            esValido=nullptr;
            break;
        }
        ant=p;
        p=(void**)p[SIG];
    }
}

void**crearNodo(void*dato,void*conti){
    
    void**nuevo=new void*[2]{};
    nuevo[DAT]=dato;
    nuevo[SIG]=conti;
    return nuevo;
}
    
void imprimeLista(void*lis,void(*imprimir)(const void*,ofstream&),
        const char*nombArch){
    
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch; exit(1);
    }
    void**lista=(void**)lis;
    void**p=(void**)lista[CAB];
    while(p){
        imprimir(p[DAT],arch);
        p=(void**)p[SIG];
    }
}

void uneLista(void*lis1,void*lis2){
    
    void**lista1=(void**)lis1;
    void**lista2=(void**)lis2;
    
    void**cola1=(void**)lista1[COL];
    cola1[SIG]=lista2[CAB];
    lista1[COL]=lista2[COL];    
}