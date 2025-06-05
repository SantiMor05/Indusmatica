/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ProductoEntregado.cpp
 * Author: Lenovo
 * 
 * Created on 3 de junio de 2025, 08:10 PM
 */

#include <cstring>

#include "ProductoEntregado.h"
using namespace std;

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
}


ProductoEntregado::~ProductoEntregado() {
    if(codigo != nullptr)delete codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(const char* cod) {
    if(codigo != nullptr)delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void ProductoEntregado::GetCodigo(char *cod) const {
    if(codigo == nullptr)cod[0] = 0;
    else strcpy(cod, codigo);
}

void ProductoEntregado::operator=(const class ProductoEntregado &orig){
    char aux[60];
    orig.GetCodigo(aux);
    SetCodigo(aux);
    precio = orig.precio;
}
