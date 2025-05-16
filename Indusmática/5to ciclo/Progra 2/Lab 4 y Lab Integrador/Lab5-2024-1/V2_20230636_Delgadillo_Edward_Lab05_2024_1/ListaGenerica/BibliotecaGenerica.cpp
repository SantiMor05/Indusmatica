/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: 00123
 * 
 * Created on 8 de mayo de 2025, 08:55 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaGenerica.h"
using namespace std;

enum indices{DAT,SIG};
enum ayuda{CAB,COL};

void crealista(void*&peds,void*(*leer)(ifstream &),const char*nombArch){
    
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch; exit(1);
    }
    peds=new void*[2]{};
    void*dato;
    while(true){
        dato=leer(arch);
        if(arch.eof())break;
        insertarLista(dato,peds);
    }
}

bool listaVacia(void*peds){
    
    void**pedidos=(void**)peds;
    if(pedidos[CAB])return false;
    return true;
}
        
void insertarLista(void*dato,void*peds){
    
    void**pedidos=(void**)peds;
    void**nuevo=new void*[2]{};
    nuevo[DAT]=dato;
    if(listaVacia(peds)) pedidos[CAB]=nuevo;
    if(pedidos[COL]){
        void**cola=(void**)pedidos[COL];
        cola[SIG]=nuevo;
    }
    pedidos[COL]=nuevo;
}

void imprimelista(void*peds,void(*imprimir)(const void*,ofstream &),
        const char*nombArch){
    
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch; exit(1);
    }
    void**pedidos=(void**)peds;
    void**p=(void**)pedidos[CAB];
    while(p){
        imprimir(p[DAT],arch);
        p=(void**)p[SIG];
    }
}

void combinalista(void*peds1,void*peds2,void*&pedsFinal,
        int(*comparar)(const void*,const void*)){
    
    pedsFinal=new void*[2]{};
    void**pedidos1=(void**)peds1,**pedidos2=(void**)peds2;
    void**cola=(void**)pedidos1[COL],**cabeza=(void**)pedidos2[CAB];
    void**pedidosFinal=(void**)pedsFinal;
    
    if(comparar(cola[DAT],cabeza[DAT])<0){
        cola[SIG]=cabeza;
        cabeza=(void**)pedidos1[CAB];
        cola=(void**)pedidos2[COL];
        fusionRapida(cabeza,cola,pedidosFinal);
    }
    else{
        cola=(void**)pedidos2[COL];
        cabeza=(void**)pedidos1[CAB];
        if(comparar(cola[DAT],cabeza[DAT])<0){
            cola[SIG]=cabeza;
            cabeza=(void**)pedidos2[CAB];
            cola=(void**)pedidos1[COL];
            fusionRapida(cabeza,cola,pedidosFinal);
        }
        else{
            fusionGeneral(pedidos1,pedidos2,pedidosFinal,comparar);
        }
    }
}

void*quitaLista(void**lista){
    
    void**cabeza=(void**)lista[CAB];
    void*dato=cabeza[DAT];
    lista[CAB]=cabeza[SIG];
    return dato;
}


void fusionGeneral(void**lis1,void**lis2,void**lisFinal,
        int(*comparar)(const void*,const void*)){
    
    void**ini=nullptr,**p;
    
    while(lis1[CAB] and lis2[CAB]){
        void**nodo1=(void**)lis1[CAB],**nodo2=(void**)lis2[CAB];
        if(comparar(nodo1[DAT],nodo2[DAT])<0) avanzar(ini,p,nodo1,lis1[CAB]);
        
        else if(comparar(nodo2[DAT],nodo1[DAT])<0) avanzar(ini,p,nodo2,lis2[CAB]);
//        else avanzar(ini,p,nodo2,lis2[CAB]);
        else{
            avanzar(ini,p,nodo1,lis1[CAB]);
            quitaLista(lis2);
        }
    }
    if(lis1[CAB]){
        p[SIG]=lis1[CAB];
        p=(void**)lis1[COL];
    }
    else{
        p[SIG]=lis2[CAB];
        p=(void**)lis2[COL];
    }
    lisFinal[CAB]=ini;
    lisFinal[COL]=p;
}

void avanzar(void**&ini,void**&p,void**nodo1,void*&lis1Cab){
    
    if(not ini){
        ini=nodo1;
        p=nodo1;
    }
    else{
        p[SIG]=nodo1;
        p=nodo1;
    }
    lis1Cab=nodo1[SIG];
}



void fusionRapida(void**cabeza,void**cola,void**pedidosFinal){
    
    pedidosFinal[CAB]=cabeza;
    pedidosFinal[COL]=cola;
}


