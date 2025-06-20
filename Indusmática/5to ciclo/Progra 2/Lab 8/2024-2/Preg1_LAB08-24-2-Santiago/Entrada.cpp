/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrada.cpp
 * Author: santi
 * 
 * Created on 18 de junio de 2025, 10:56
 */

#include "Entrada.h"

Entrada::Entrada() {
}

Entrada::Entrada(const Entrada& orig) {
    *this = orig;
}

Entrada::~Entrada() {
}

void Entrada::SetPicante(bool picante) {
    this->picante = picante;
}

bool Entrada::IsPicante() const {
    return picante;
}

void Entrada::operator =(const Entrada& orig){
    Producto::operator =(orig);
    picante = orig.picante;
}

void Entrada::leerDatos(ifstream &arch){
    char pica[20];
    
    Producto::leerDatos(arch);
    arch.get();
    arch.getline(pica, 20);
    if(pica[0] == 'p')
        picante = true;
    else picante = false;
}

void Entrada::imprimirDatos(ofstream &arch){
    Producto::imprimirDatos(arch);
    if(picante == 0)
        arch << "Sin picante" << endl;
    else
        arch << "Picante" << endl;
}