/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Oracion.cpp
 * Author: kenyi
 * 
 * Created on 23 de junio de 2025, 07:58 PM
 */

#include "Oracion.h"

Oracion::Oracion() {
    cantidad_palabras = 0;
    polaridad_total = 0;
}

void Oracion::SetCantidad_palabras(int cantidad_palabras) {
    this->cantidad_palabras = cantidad_palabras;
}

int Oracion::GetCantidad_palabras() const {
    return cantidad_palabras;
}

void Oracion::SetPolaridad_total(int polaridad_total) {
    this->polaridad_total = polaridad_total;
}

int Oracion::GetPolaridad_total() const {
    return polaridad_total;
}

void Oracion::agregar(Palabra palabra) {
    palabras.push_back(palabra);
}

void Oracion::imprimir(ofstream& arch) {
    for (Palabra p : palabras) {
        arch << p.GetTexto() << " ";
    }
}
