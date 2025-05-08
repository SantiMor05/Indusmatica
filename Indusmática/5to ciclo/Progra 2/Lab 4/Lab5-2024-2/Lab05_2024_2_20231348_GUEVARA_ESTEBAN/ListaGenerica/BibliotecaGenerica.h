/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.h
 * Author: esteban
 *
 * Created on 7 de mayo de 2025, 20:48
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

#include <fstream>
using namespace std;
void crealista(void* &lista,void* (*leer)(ifstream &),
        const char* nombreArch);
void insertarLista(void* reg,void* &lista);
void cargalista(void* lista,int (*compruebanumero)(const void*,const void*),
        void * (*leeregnumeros)(ifstream &),const char* nombreArch);
void insertarArreglo(void *lista,
        int (*compruebanumero)(const void*,const void*),void* reg);
void insertarElemento(void* dupla,void *elemento);
void muestralista(void* lst,void (*imprime)(void*,ofstream &),
        const char* nombreArch);
#endif /* FUNCIONESAUX_H */
