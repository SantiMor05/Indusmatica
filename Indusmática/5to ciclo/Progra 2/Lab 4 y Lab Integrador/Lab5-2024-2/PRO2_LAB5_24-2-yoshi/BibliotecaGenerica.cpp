/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: Usuario
 * 
 * Created on 7 de mayo de 2025, 13:50
 */
#include <iostream>
#include <fstream>
#include <cstddef>
using namespace std;
#include "BibliotecaGenerica.h"
enum LISTA {CAB,NUM,COL};
enum NODO {DAT,SIG};

void crearLista(void* &lista, void*(*leer)(ifstream &arch),const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    void* registro;
    lista = nullptr;
    construir(lista);
    while(true){
        registro = leer(arch);
        if (arch.eof()) break;
        insertarAlFinal(lista,registro);
    }
}

void construir(void* &lis){
    void** lista = (void**)lis;
    if (lista==nullptr) lista = new void*[3];
    lista[CAB] = nullptr;
    lista[COL] = nullptr;
    int* numDat = new int;
    *numDat = 0;
    lista[NUM] = numDat;
    lis = lista;
}

void insertarAlFinal(void *lis, void*registro){
    void** lista = (void**)lis, **cola;
    void** nuevoNodo = new void*[2];
    nuevoNodo[0] = registro;
    nuevoNodo[1] = nullptr;
    if (esListaVacia(lis))
        lista[CAB] = nuevoNodo;
    else{
        cola = (void**)lista[COL];
        cola[SIG] = nuevoNodo;
    }
    lista[COL] = nuevoNodo;
}

bool esListaVacia(void* lis){
    void**lista = (void**)lis;
    if (lista[CAB]==nullptr) return true;
    return false;
}

void muestraLista(void* lis, void(*imprime)(ofstream &arch, void*dato),const char* nomArch){
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    void** lista = (void**)lis;
    void** recorrido = (void**)lista[CAB];
    while(recorrido!=nullptr){
        imprime(arch,recorrido[DAT]);
        recorrido = (void**)recorrido[SIG];
    }
}

void cargarLista(void *lista, bool (*compara)(const void* a, const void* b),
        void*(*leer)(ifstream &arch),const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    void* registro, *ubicacion;
    while(true){
        registro = leer(arch);
        if (arch.eof()) break;
        ubicacion = buscar_pos(lista,registro,compara);
        if (ubicacion!=nullptr){
            ubicar_en_pos(ubicacion,registro);
            borrar_dato_inncesario(registro);
        }
    }
}

void borrar_dato_inncesario(void *&registro){
    void** dupla = (void**)registro;
    void** dato = (void**)dupla[0];
    delete dato;
}

void ubicar_en_pos(void *&ubicacion, void*registro){
    void**datos = (void**)registro;
    void**dupla = (void**)ubicacion;
    void**arreglo = (void**)dupla[1];
    if (arreglo==nullptr) arreglo = new void*[20]{};
    int numDat=0;
    while(arreglo[numDat]) numDat++;
    arreglo[numDat] = datos[1];
    dupla[1] = arreglo;
    ubicacion = dupla;
}

void*buscar_pos(void *lis, void *registro, bool (*compara)(const void* a, const void* b)){
    void** lista = (void**)lis;
    void**dato = (void**)registro;
    void**recorrido = (void**)lista[CAB], **dupla;
    while(recorrido!=nullptr){
        dupla = (void**)recorrido[DAT];
        if(compara(dupla[0],dato[0])) return recorrido[DAT];
        recorrido = (void**)recorrido[SIG];
    }
    return nullptr;
}