/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bebida.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 19:59
 */

#include "Bebida.h"
#include <cstring>
#include <iomanip>

Bebida::Bebida() {
    inicializa();
}

//Bebida::Bebida(const Bebida& orig) {
//}

Bebida::~Bebida() {
    if(tamano != nullptr)
        delete tamano;
}

void Bebida::SetTamano(char* tam) {
    if(tamano != nullptr)delete tamano;
    tamano = new char[strlen(tam) + 1];
    strcpy(tamano, tam);
}

void Bebida::GetTamano(char *buffer) const {
    if(tamano == nullptr)buffer[0] = 0;
    else
        strcpy(buffer, tamano);
}

void Bebida::inicializa(){
    tamano = nullptr;
}

void Bebida::leerBebida(ifstream &arch){
    
    char tam[20];
    leerProducto(arch);
    arch.get();
    arch.getline(tam, 20);
    SetTamano(tam);
}

void Bebida::imprimirDatos(ofstream &arch){
    imprimirProducto(arch);
    if(tamano != nullptr)
        arch << setw(15) << tamano;
    
    arch << endl;
}
void operator << (ofstream &arch, Bebida &bebida){
    bebida.imprimirDatos(arch);
}