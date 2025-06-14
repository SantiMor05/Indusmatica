/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrada.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 19:28
 */

#include "Entrada.h"
#include <iomanip>

Entrada::Entrada() {
}

//Entrada::Entrada(const Entrada& orig) {
//}

Entrada::~Entrada() {
}

void Entrada::SetPicante(bool picante) {
    this->picante = picante;
}

bool Entrada::IsPicante() const {
    return picante;
}

void Entrada::leerEntrada(ifstream &arch){
    
    char es_picante[15];
    
    leerProducto(arch);
    arch.get();
    
    arch.getline(es_picante, 15);
    if(es_picante[0] == 's')
        SetPicante(false);
    else
        SetPicante(true);
}

void Entrada::imprimirDatos(ofstream &arch)const{
    imprimirProducto(arch);
    arch << setw(5) << " ";
    if(picante)
        arch << "Picante" << endl;
    else
        arch << "Sin picante" << endl;
}

void operator << (ofstream &arch, const Entrada &entrada){
    entrada.imprimirDatos(arch);
}