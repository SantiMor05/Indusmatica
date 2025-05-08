/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaconEnteros.cpp
 * Author: alulab14
 * 
 * Created on 7 de mayo de 2025, 10:49 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"

using namespace std;

enum indices{DUPLA,SIG};

void* leenumeros(ifstream &arch){
    
    int num;
    arch>>num;
    if(arch.eof())return nullptr;
    return new int(num);
}

void*leeregnumeros(ifstream &arch){
    
    int buscado,nuevo;
    arch>>buscado;
    if(arch.eof())return nullptr;
    arch>>nuevo;
    void**registro=new void*[2]{};
    registro[0]=new int(buscado);
    registro[1]=new int(nuevo);
    return registro;
}

int compruebanumero(const void*a,const void*b){
    
    int*ai=(int*)a,*bi=(int*)b;
    return (*ai)-(*bi);
}

void imprimenumeros(const void*dup,ofstream &arch){
    
    void**dupla=(void**)dup;
    int*num=(int*)dupla[0];
    
    arch<<*num<<endl;
    void**arreglo=(void**)dupla[1];
    if(arreglo){
        int*valor;
        for (int i = 0; arreglo[i]; i++) {
            valor=(int*)arreglo[i];
            arch<<*valor<<"  ";
        }
        arch<<endl<<endl;
    }
}
