/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: alulab14
 * 
 * Created on 7 de mayo de 2025, 10:48 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaGenerica.h"

using namespace std;

enum indices{DUP,SIG};
enum otros{CAB,COL,LONG};

void crealista(void*&lis,void*(*leer)(ifstream &),const char*nombArch){
    
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch; exit(1);
    }
    construir(lis,3);
    void**lista=(void**)lis;
    lista[LONG]=new int(0);

    void*dato;
    while(true){
        dato=leer(arch);
        if(arch.eof())break;
        insertafinal(dato,lis);
    }
    
}

void construir(void*&lis,int espacio){
    
    void**lista=new void*[espacio]{};    
    lis=lista;
}

void insertafinal(void*dato,void*lis){
    
    void**lista=(void**)lis;
    void**nuevo=new void*[2]{};
    void**dupla=new void*[2]{};
    dupla[0]=dato;
    nuevo[DUP]=dupla;
            
    if(not lista[CAB]) lista[CAB]=nuevo;
    if(lista[COL]) {
        void**cola=(void**)lista[COL];
        cola[SIG]=nuevo;
    }
    lista[COL]=nuevo;
    int*longitud=(int*)lista[LONG];
    (*longitud)++;
}

void muestralista(void*lis,void(*imprimir)(const void*,ofstream&),
        const char*nombArch){
    
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch; exit(1);
    }
    void**lista=(void**)lis;
    void**p=(void**)lista[CAB];
    while(p){
        imprimir(p[DUP],arch);
        p=(void**)p[SIG];
    }
}

void cargalista(void*lis,int(*comparar)(const  void*,const void*),
        void*(*leerReg)(ifstream &),
        const char*nombArch){
    
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch; exit(1);
    }
//    2 4
    int pos;
    void*registro;
    while(true){
        registro=leerReg(arch);
        if(arch.eof())break;
        buscar(lis,registro,comparar);
    }
}

void buscar(void*lis,void*reg,int(*comparar)(const  void*,const void*)){
    
    void**lista=(void**)lis;
    void**registro=(void**)reg;
    void*buscado=registro[0];
    void*nuevo=registro[1];
    
    void**nodo=(void**)lista[CAB];
    void**dupla;
    
    while(nodo){
        dupla=(void**)nodo[0];
        if(comparar(buscado,dupla[0])==0){
            agregarReg(dupla[1],nuevo);
            break;
        }
        nodo=(void**)nodo[SIG];
    }
    delete registro;
}

void agregarReg(void*&arr,void*nuevo){
    
    if(not arr)construir(arr,20);
    void**arreglo=(void**)arr;
    int i=0;
    while(arreglo[i])i++;
    arreglo[i]=nuevo;
}


