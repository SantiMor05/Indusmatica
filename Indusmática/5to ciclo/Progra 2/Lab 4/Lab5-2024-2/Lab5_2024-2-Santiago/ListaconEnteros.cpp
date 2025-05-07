/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaconEnteros.cpp
 * Author: santi
 * 
 * Created on 5 de mayo de 2025, 19:23
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"

using namespace std;

void *leenumeros(ifstream &arch){
    
    int *entero, d;
    arch >> d;
    if(arch.eof())return nullptr;
    entero = new int{d};
    
    return entero;
    
}

void *leeregnumeros(ifstream &arch){
    
    int d, *clave, *dato;
    
    arch >> d;
    if(arch.eof())return nullptr;
    clave = new int{d};
    dato = new int;
    arch >> *dato;
    
    void **dupla = new void*[2];
    
    dupla[0] = clave;
    dupla[1] = dato;
    return dupla;
}

int compruebanumeros(const void *num1, const void *num2){
    
    int *n1 = (int*)num1;
    int *n2 = (int*)num2;
    
    return *n1 == *n2;
    
}

void imprimenumeros(const void *dupla, ofstream &arch){
    
    void **regDupla = (void **)dupla, 
            **arreglo =(void **)regDupla[1];
    int *numero = (int *)regDupla[0];
    
    arch << *numero << endl;
    for(int i = 0; arreglo[i];i++){
        numero = (int *)arreglo[i];
        if(i != 0)
            arch << setw(3);
        arch << *numero;
    }
    
    arch << endl;
    
}