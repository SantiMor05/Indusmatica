/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaConEnteros.cpp
 * Author: Lenovo
 * 
 * Created on 6 de mayo de 2025, 09:01 PM 11:49 pm
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesComunes.h"
#include "ListaConEnteros.h"
using namespace std;

enum DUPLA{DAT, ARR};

void *leeNumeros(ifstream &arch){
    int *num, auxNum;
    arch>>auxNum;
    if(arch.eof())return nullptr;
    
    num = new int;
    *num = auxNum;
    //cout<<*num<<endl;
    return num;
}

void* leeRegNumeros(ifstream &arch){
    void **reg;
    int *clave, cl, *num;
    arch>>cl;
    if(arch.eof())return nullptr;
    clave = new int;
    *clave = cl;
    num = new int;
    arch>>*num;
    
    //DUPLA{DAT, ARR};
    reg = new void*[2]{};
    reg[0] = clave; //DAT
    reg[1] = num; //ARR 
    return reg;
}

int compruebaNumero(const void*a, const void*b){
    int *ai = (int *)a, 
        *bi = (int *)b;
    //cout<<*ai<<" "<<*bi<<endl;
    return *ai - *bi;
}

void imprimeNumeros(ofstream &arch, void *dat){
    //DUPLA{DAT, ARR};
    void **dato = (void **)dat;
    int *num = (int *)dato[DAT];
    void **arreglo = (void **)dato[ARR];
    arch<<*num<<endl;
    
    for (int i = 0; arreglo[i]; i++) {
        imprimirUno(arch, arreglo[i], i);
    }
    arch<<endl;
}

void imprimirUno(ofstream &arch, void *entero, int i){
    int *num; 
    num = (int *)entero;
    if(i == 0){
        arch<<setw(4)<<" ";
    }
    arch<<*num<<" ";
}
