/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaConEnteros.cpp
 * Author: Usuario
 * 
 * Created on 7 de mayo de 2025, 14:07
 */

#include <fstream>
using namespace std;
#include "ListaConEnteros.h"

void* leerNumeros(ifstream &arch){
    void** registro;
    int*numero, num;
    arch>>num;
    if (arch.eof()) return nullptr;
    numero = new int;
    *numero = num;
    registro = new void*[2];
    registro[0] = numero;
    registro[1] = nullptr;
    return registro;
}

void imprimeNumeros(ofstream &arch, void* dato){
    void**dupla = (void**)dato;
    int* numero = (int*)dupla[0], *num;
    void**arreglo = (void**)dupla[1];
    arch<<*numero<<endl;
    if (arreglo!=nullptr){
        for (int i = 0; arreglo[i]; i++) {
            num = (int*)arreglo[i];
            arch<<"   "<<*num;
        }
        arch<<endl;
    }
}

bool compruebaNum(const void* a, const void* b){
    int* numA = (int*)a, *numB = (int*)b;
    if (*numA==*numB) return true;
    return false;
}

void *leerRegNum(ifstream &arch){
    void** registro;
    int *indice, *numero, num;
    arch>>num;
    if (arch.eof()) return nullptr;
    indice = new int;
    *indice = num;
    numero = new int;
    arch>>*numero;
    registro = new void*[2];
    registro[0] = indice;
    registro[1] = numero;
    return registro;
}