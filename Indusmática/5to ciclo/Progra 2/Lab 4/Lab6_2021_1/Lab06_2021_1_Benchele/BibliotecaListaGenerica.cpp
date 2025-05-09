/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.cpp
 * Author: Lenovo
 * 
 * Created on 8 de mayo de 2025, 10:44 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesComunes.h"
#include "BibliotecaListaGenerica.h"
using namespace std;

enum CONDUCTOR{LIC, NOM};

enum FALTAS{LICF, PLA, FEC, INFRA};

enum LISTA{CAB, COL};

enum NODO{DAT, SIG};

//Funciones lista

void construirLista(void *&lista){
    void **dupla = new void*[2]{};
    lista = dupla;
}
bool esListaVacia(void *lst){
    void **lista = (void **)lst;
    return lista[CAB] == nullptr;
}

void *quitaPrimerNodo(void *lst){ //No se usa xd
    void **lista = (void **)lst;
    void **nodo = (void **)lista[CAB];
    lista[CAB] = nodo[SIG];
    void *dato = nodo[DAT];
    delete nodo;
    return dato;
}

void *obtenerCola(void *lst){
    void **lista = (void **)lst;
    void **rec = (void **)lista[CAB];
    void **ant = nullptr;
    while(rec){
        ant = rec;
        rec = (void **)rec[SIG];
    }
    return ant;
}
void creaLista(void *&lista, void *(*leer)(ifstream &arch), int (*comparar)(const void*, const void*), 
               const char*nombArch){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);
    
    void *reg;
    construirLista(lista);
    
    while (true) {
        reg = leer(arch);
        if(arch.eof())break;
        insertarOrdenado(reg, lista, comparar);
    }
}

void insertarOrdenado(void *reg, void *lst, int (*comparar)(const void*, const void*)){
    void **lista = (void **)lst;
    void **rec = (void **)lista[CAB], **ant = nullptr, **nuevoNodo;
    
    nuevoNodo = new void*[2]{};
    nuevoNodo[DAT] = reg;
    
    while(rec){
        if(comparar(rec[DAT], reg) > 0)break;
        ant = rec;
        rec = (void **)rec[SIG];
    }
    nuevoNodo[SIG] = rec;
    if(ant == nullptr)lista[CAB] = nuevoNodo;
    else ant[SIG] = nuevoNodo;
}

void imprimeLista(void *lst, void (*imprimir)(ofstream &, void *, void*), const char*nombArch){
    ofstream arch(nombArch, ios::out);
    verificar_Apertura_O(arch, nombArch);
    
    void **lista = (void **)lst;
    void **rec = (void **)lista[CAB], **ant = new void*[2]{};
    
    arch<<"Lista: "<<endl;
    while (rec) {
        imprimir(arch, ant[DAT], rec[DAT]);
        ant = rec;
        rec = (void **)rec[SIG]; 
    }
}

void uneLista(void *&lst1, void *lst2){
    void **lista1 = (void **)lst1,
         **lista2 = (void **)lst2;
    void **cola1, **cola2;
 
    cola1 = (void **)obtenerCola(lst1);
    cola2 = (void **)obtenerCola(lst2);
    cola1[SIG] = lista2[CAB];
    cola1 = cola2;
}

