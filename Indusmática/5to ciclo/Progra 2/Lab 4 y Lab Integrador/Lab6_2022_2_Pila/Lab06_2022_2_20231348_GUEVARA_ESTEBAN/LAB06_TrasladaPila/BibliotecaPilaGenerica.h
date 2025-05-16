/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaPilaGenerica.h
 * Author: esteban
 *
 * Created on 15 de mayo de 2025, 15:26
 */

#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H

#include <fstream>
using namespace std;

void cargaarreglo(void*& arreglo,int (*cmp)(const void*,const void*),
        void* (*lee)(ifstream&),const char* nombreArch); 
void  incrementarEspacio(void** &arrDatos,int &numDat,int &cap);
void cargapila(void* &pilaini,void* arreglo); 
void construirPila(void* &pl);
void push(void* pila,void* reg);
void muevepila(void* pilaini,void*&pilafin); 
void Hanoi(int n,void* pilaini,void* pilaAux,void*pilafin);
void* pop(void* pl);

void imprimepila(void *pilafin,void (*imprime)(void*,ofstream&),
         const char* nombreArch);

#endif /* BIBLIOTECAPILAGENERICA_H */
