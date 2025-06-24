/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.cpp
 * Author: 00123
 * 
 * Created on 23 de junio de 2025, 05:05 PM
 */

#include <string>

using namespace std;
#include "Palabra.h"

//Palabra::Palabra() {
//}
//
//Palabra::Palabra(const Palabra& orig) {
//}
//
//Palabra::~Palabra() {
//}

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

