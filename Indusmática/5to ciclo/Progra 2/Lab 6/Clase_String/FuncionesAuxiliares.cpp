/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: santi
 * 
 * Created on 1 de junio de 2025, 12:40
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Cadena.h"
#include "FuncionesAuxiliares.h"

using namespace std;

#define INCREMENTOS 5

void leerDatos(Cadena *&ptr) {
    
    int n = 0, cap = 0, cont;
    ptr = nullptr;

    ifstream arch("clientes2.csv", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo" << endl;
        exit(1);
    }

    while (true) {
        if(cap == n)
            incrementarEspacios(ptr, n, cap);
        cont = 0;
        while (true) {
            if(cont != 0)
                ptr[n -1].append("/");
            arch >> ptr[n - 1];
            if(arch.eof())return;
            if(arch.get() == '\n')break;
            cont++;
        }
        n++;
    }
}


void incrementarEspacios(Cadena *&ptr, int &n, int &cap){
    
    cap += INCREMENTOS;
    
    if(ptr == nullptr){
        ptr = new Cadena[cap]{};
        n = 1;
    }
    else{
        Cadena *aux = new Cadena[cap]{};
        for(int i = 0; i < n; i++)
            aux[i] = ptr[i];
        
        delete []ptr;
        ptr = aux;
    }
}

void imprimirDatos(const Cadena *ptr){
    char buffer[500];
    for(int i = 0; ptr[i].getLongitud();i++){
        ptr[i].getCadena(buffer);
        cout << buffer << endl;
    }
}

int compara(const void *a, const void *b){
    Cadena *cad1 = (Cadena *)a;
    Cadena *cad2 = (Cadena *)b;
    
    return cad1->compare(*cad2);
}

int contar(Cadena *ptr){
    int i = 0;
    for(; ptr[i].getLongitud();i++);
    return i;
}