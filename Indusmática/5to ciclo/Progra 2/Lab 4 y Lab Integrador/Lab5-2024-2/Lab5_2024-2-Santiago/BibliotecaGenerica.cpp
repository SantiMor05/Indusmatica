/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: santi
 * 
 * Created on 5 de mayo de 2025, 19:01
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "BibliotecaGenerica.h"

using namespace std;

void construir (void *&lista){
    lista = nullptr;
}

bool eslistavacia(void *lista){
    if(lista == nullptr)
        return true;
    return false;
}

void crealista(void *&lista, void* (*lee)(ifstream &), const char*nombArch){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    construir(lista);
    
    void **tripletaLista, *aux;
    int cont = 0;
    while(true){
        aux = lee(arch);
        if(aux == nullptr)
            return;
        insertarfinal(lista, aux);
        cont++;
    }
    
}

void insertarfinal(void *&lista, void *aux){
    void **regLista = (void **)lista;
    void **auxNodo;
    void **nodo = new void *[2]{};
    void **dupla = new void*[2];
    void **arreglo = new void*[20]{};
    int *cant;
    
    dupla[0] = aux;
    dupla[1] = arreglo;
    
    nodo[0] = dupla; //Nodo[1] ya apunta a null
    if(eslistavacia(lista)){
        regLista = new void*[3]{};
        regLista[0] = regLista[1] = nodo;
        cant = new int{1};
        regLista[2] = cant;
        lista = regLista;
    }  
    else{
        auxNodo = (void **)regLista[1]; //Estraemos la cola
        auxNodo[1] = nodo;
        regLista[1] = nodo;
        cant = (int *)regLista[2];
        (*cant)++;
    }
}


void cargalista(void *lista, int (*cmp)(const void *, const void *), 
        void *(*lee)(ifstream &), const char *nombArch){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo" << endl;
        exit(1);
    }
    void *numero, *dupla, **datosNumero;
    while(true){
        numero = lee(arch);
        if(numero == nullptr)break;
        buscarActualizarDupla(numero, lista, cmp);
        //delete numero;
    }  
}

void buscarActualizarDupla(void *numero, void *lista, 
        int (*cmp)(const void *, const void *)){
    
    void **detalleNumero = (void **)numero;
    void **regLista = (void **)lista;
    
    int *cant = (int *)regLista[2];
    
    void **nodo = (void **)regLista[0];
    void **dupla;
    
    for(int i = 0; i < *cant; i++){
        dupla = (void **)nodo[0];
        if(cmp(detalleNumero[0], dupla[0]) == 0){
            insertarArreglo(nodo[0], detalleNumero[1]);
            break;
        }
        nodo = (void **)nodo[1];
    }
}

void insertarArreglo(void *dupla, void *dato){
    
    void **regDupla = (void **) dupla;
    void **arreglo = (void **)regDupla[1];
    int i = 0;
    for(; arreglo[i]; i++);
    
    arreglo[i] = dato;
    
}

void muestralista(void *lista, void (*imprime)(const void *, ofstream&), 
        const char *nombArch){
    
    ofstream arch(nombArch, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    void **regLista = (void **)lista, **nodo;
    int *n;
    
    if(!eslistavacia(lista)){
        
        n = (int *)regLista[2];
        nodo = (void **)regLista[0];
        for(int i = 0; i < *n; i++){
            imprime(nodo[0],arch);
            arch << endl;
            nodo = (void **)nodo[1];
        }
    }
    
}