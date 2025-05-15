/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.cpp
 * Author: santi
 * 
 * Created on 13 de mayo de 2025, 23:32
 */

#include <iostream>
#include <iomanip>
#include "BibliotecaListaGenerica.h"

using namespace std;

enum RegLista{CAB,COLA};
enum Nodo{DAT,SIG};

void construyeLista(void *&lista){
    
    lista = nullptr;
    
}
void creaLista(void *&lista, void *(*lee)(ifstream &arch), int cmp(const void *dato1,
        const void *dato2), const char *nombArch){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    construyeLista(lista);
    
    void *dato;
    while(true){
        dato = lee(arch);
        if(dato == nullptr)
            break;
        insertaLista(lista, dato, cmp);
    }
}

bool listavacia(void *lista){
    
    if(lista == nullptr)
        return true;
    void **regLista = (void **)lista;
    if(regLista[CAB] == nullptr)
        return true;
    return false;
}
void insertaLista(void *&lista, void *dato, int cmp(const void *dato1,
        const void *dato2)){
    
    void **regNodo, **nodo, **ant = nullptr, **nuevoNodo;
    nuevoNodo = new void *[2]{};
    nuevoNodo[DAT] = dato;
    int comparacion;
    if(listavacia(lista)){
        nodo = new void*[2]{};
        nodo[CAB] = nodo[COLA] = nuevoNodo;
        lista = nodo;
    }
    else{
        regNodo = (void **)lista;
        nodo = (void **)regNodo[CAB];
        while(nodo != nullptr){
            comparacion = cmp(dato, nodo[DAT]);
            if( comparacion < 0) break;
//            else if(comparacion == 0){
//                delete nuevoNodo; //Borramos el espacio porque no lo necesitamos
//                delete dato;
//                
//            }
            ant = nodo;
            nodo =(void **)nodo[SIG];
        }
        if(ant == nullptr){
            nuevoNodo[SIG] = regNodo[CAB];
            regNodo[CAB] = nuevoNodo;
        }
        else{
            nuevoNodo[SIG] = ant[SIG];
            ant[SIG] = nuevoNodo;
            if(nodo == nullptr)
                regNodo[COLA] = nuevoNodo;
        }
    }
}

void uneLista(void *lista1, void *lista2){
    
    void **regLista = (void **)lista1;
    void **regLista2 = (void **)lista2;
    
    if(listavacia(lista1))
        lista1 = lista2;
    else if(!listavacia(lista2)){
        void **nodo = (void **)regLista[COLA];
        nodo[SIG] = regLista2[CAB];
        regLista[COLA] = regLista2[COLA];
    }
}

void imprimeLista(void *lista, void (*imprime)(const void *dato, ofstream &arch),
        const char *nombArch){
    
    ofstream arch(nombArch, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    
    if(!listavacia(lista)){
        void **regLista = (void **)lista;
        void **nodo = (void **)regLista[CAB];
        while(nodo != nullptr){
            imprime(nodo[DAT], arch);
            nodo = (void **)nodo[SIG];
        }
    }
    
}