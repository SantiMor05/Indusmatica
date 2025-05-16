/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: kenyi
 * 
 * Created on 8 de mayo de 2025, 11:48 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibliotecaGenerica.h"

void crelista(void *&lista, void *(*lee)(ifstream&),
        const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << nombArch;
        exit(1);
    }
    construir(lista);
    void *dato;
    while (true) {
        dato = lee(arch);
        if (dato == nullptr)break;
        insertarlista(lista, dato);
    }
}

void insertarlista(void *&lista, void *dato) {
    void **reg = (void**) lista;
    void **nodo = new void*[2] {
    }, **cola;
    void **dupla = new void*[2];
    void **arreglo = new void*[20] {
    };
    int *cant;

    dupla[0] = dato;
    dupla[1] = arreglo;

    nodo[0] = dupla;
    if (eslistavacia(lista)) {
        reg[0] = nodo;
        reg[1] = nodo;
        cant = (int*) reg[2];
        (*cant)++;
    } else {
        cola = (void**) reg[1];
        cola[1] = nodo;
        reg[1] = nodo;
        cant = (int*) reg[2];
        (*cant)++;
    }
}

bool eslistavacia(void *lista) {
    void **reg = (void**) lista;
    if (lista == nullptr)return true;
    if (reg[0] == nullptr)return true;
    return false;
}

void construir(void *&lista) {
    void **reg = new void*[3] {
    };
    int *cant = new int{0};
    reg[2] = cant;
    lista = reg;
}

void cargalista(void *lista, int (*cmp)(const void*, const void*),
        void *(*lee)(ifstream&), const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << nombArch;
        exit(1);
    }
    void *dato;
    while (true) {
        dato = lee(arch);
        if (dato == nullptr)break;
        buscargAgregar(dato, lista, cmp);
    }
}

void buscargAgregar(void *dato, void *lista, int (*cmp)(const void*,
        const void*)) {
    void **aux = (void**) dato;
    void **reg = (void**) lista;
    void **nodo = (void**) reg[0];
    void **dupla;
    int *cant = (int*) reg[2];
    for (int i = 0; i<*cant; i++) {
        dupla = (void**)nodo[0];
        if (cmp(dupla[0], aux[0]) == 0) {
            ponerDatoEnArreglo(dupla, aux[1]);
            break;
        }
        nodo = (void**) nodo[1];
    }
}

void ponerDatoEnArreglo(void **&dupla, void *dato) {
    void **arr = (void**) dupla[1];
    int i = 0;
    while (arr[i])i++;
    arr[i] = dato;
}

void muestralista(const void *lista, void (*imprime)(const void*,
        ofstream&), const char*nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    void **reg=(void **)lista,**nodo=(void**)reg[0];
    int *cant=(int *)reg[2];
    
    for(int i=0;i<*cant;i++){
        
        imprime(nodo[0],arch);
        arch<<endl;
        nodo=(void**)nodo[1];
    }
}