/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bebida.cpp
 * Author: santi
 * 
 * Created on 18 de junio de 2025, 10:51
 */

#include "Bebida.h"
#include <cstring>

Bebida::Bebida() {
    inicializa();
}

Bebida::Bebida(const Bebida& orig) {
    inicializa();
    *this = orig;
}

Bebida::~Bebida() {
    if(tamano != nullptr) delete tamano;
}

void Bebida::SetTamano(char* tam) {
    if(tamano != nullptr) delete tamano;
    tamano = new char[strlen(tam) + 1];
    strcpy(tamano, tam);
}

void Bebida::GetTamano(char *buffer) const {
    if(tamano == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, tamano);
}

void Bebida::inicializa(){
    tamano = nullptr;
}

void Bebida::operator =(const Bebida& orig){
    
    Producto::operator =(orig);
    char buffer[200];
    orig.GetNombre(buffer);
    SetNombre(buffer);
    
}

void Bebida::leerDatos(ifstream &arch){
    
    char tam[20];
    
    Producto::leerDatos(arch);
    arch.get();
    arch.getline(tam, 20);
    SetTamano(tam);
}

void Bebida::imprimirDatos(ofstream &arch){
    Producto::imprimirDatos(arch);
    arch << "Tamano: " << tamano << endl;
}