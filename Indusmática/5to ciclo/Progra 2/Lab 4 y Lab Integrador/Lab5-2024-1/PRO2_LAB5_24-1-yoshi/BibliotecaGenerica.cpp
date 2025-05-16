/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: Usuario
 * 
 * Created on 8 de mayo de 2025, 10:05
 */

#include <iostream>
#include <fstream>
#include <cstddef>
using namespace std;
#include "BibliotecaGenerica.h"
enum LISTA {CAB,COL};
enum NODO {DAT,SIG};

void crearLista(void *&pedidos1, void*(*leer)(ifstream &arch),const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    pedidos1 = nullptr;
    construirLista(pedidos1);
    void* registro;
    while(true){
        registro = leer(arch);
        if (arch.eof()) break;
        insertarFinal(registro,pedidos1);
    }
}

void construirLista(void* &ped){
    void** pedidos = (void**)ped;
    if (ped==nullptr) pedidos = new void*[2];
    pedidos[CAB] = nullptr;
    pedidos[COL] = nullptr;
    ped = pedidos;
}

void insertarFinal(void *registro,void *lis){
    void** lista = (void**)lis, **nuevoNodo = new void*[2]{},
            **cola = (void**)lista[COL];
    nuevoNodo[DAT] = registro;
    nuevoNodo[SIG] = nullptr;
    if (esListaVacia(lista))
        lista[CAB] = nuevoNodo;
    else cola[SIG] = nuevoNodo;
    lista[COL] = nuevoNodo;
}

bool esListaVacia(void** lista){
    if (lista[CAB]==nullptr) return true;
    return false;
}

void imprimeLista(void *&lis, void(*imprime)(ofstream &arch, void*registro),const char* nomArch){
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    void** lista = (void**)lis, *registro, **cabeza;
    while(!esListaVacia(lista)){
        cabeza = (void**)lista[CAB];
        registro = quitaLista(lista,cabeza);
        imprime(arch,registro);
    }
}

void* quitaLista(void** &lista, void **cabeza){
    void* registro;
    registro = cabeza[DAT];
    lista[CAB] = cabeza[SIG];
    cabeza[SIG] = nullptr;
    return registro;
}

void combinaLista(void *pedidos1, void *pedidos2, void* &pedidosFinal, int(*compara)(const void*a, const void*b)){
    pedidosFinal = nullptr;
    construirLista(pedidosFinal);
    void** lista1 = (void**)pedidos1, **lista2 = (void**)pedidos2,
            **rec1 = (void**)lista1[CAB], **rec2 = (void**)lista2[CAB];
    while(rec1!=nullptr and rec2!=nullptr){
        if (compara(rec1[DAT],rec2[DAT])<0){
            insertarFinal(rec1[DAT],pedidosFinal);
            rec1 = (void**)rec1[SIG];
        }else{
            insertarFinal(rec2[DAT],pedidosFinal);
            if (compara(rec1[DAT],rec2[DAT])==0) rec1 = (void**)rec1[SIG];
            rec2 = (void**)rec2[SIG];
        }
    }
    void** recorridoFinal;
    if (rec1!=nullptr) recorridoFinal = rec1;
    else recorridoFinal = rec2;
    while(recorridoFinal!=nullptr){
        insertarFinal(recorridoFinal[DAT],pedidosFinal);
        recorridoFinal = (void**)recorridoFinal[SIG];
    }
}