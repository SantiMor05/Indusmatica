/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.cpp
 * Author: santi
 * 
 * Created on 11 de junio de 2025, 23:20
 */

#include "Escala.h"

Escala::Escala() {
}
//
//Escala::Escala(const Escala& orig) {
//}

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

void Escala::leerDatos(ifstream &arch){
    arch >> precio;
}