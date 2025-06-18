/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Escala.cpp
 * Author: Lenovo
 * 
 * Created on 18 de junio de 2025, 03:03 PM
 */

#include <fstream>
#include "Escala.h"
using namespace std;

Escala::Escala() {
}

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

void Escala::asigna(int cod, double prec){
    codigo = cod;
    precio = prec;
}