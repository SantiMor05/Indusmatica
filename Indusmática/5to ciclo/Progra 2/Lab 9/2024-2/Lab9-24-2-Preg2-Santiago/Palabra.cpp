/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.cpp
 * Author: santi
 * 
 * Created on 24 de junio de 2025, 22:36
 */

#include "Palabra.h"

Palabra::Palabra() {
}

Palabra::Palabra(const Palabra& orig) {
    *this = orig;
}

Palabra::~Palabra() {
}

void Palabra::SetPolaridad(int polaridad) {
    this->polaridad = polaridad;
}

int Palabra::GetPolaridad() const {
    return polaridad;
}

void Palabra::SetTexto(string texto) {
    this->texto = texto;
}

string Palabra::GetTexto() const {
    return texto;
}

void Palabra::operator =(const Palabra& orig){
    
    texto = orig.texto;
    polaridad = orig.polaridad;
    
}


void Palabra::imprimir(ofstream &arch){
    
    arch << texto;
    
}