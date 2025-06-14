/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductoEntregado.cpp
 * Author: santi
 * 
 * Created on 5 de junio de 2025, 14:39
 */

#include "ProductoEntregado.h"
#include <cstring>

ProductoEntregado::ProductoEntregado() {
    inicializa();
}

ProductoEntregado::ProductoEntregado(const ProductoEntregado& orig) {
    inicializa();
    *this = orig;
}

ProductoEntregado::~ProductoEntregado() {
    if(codigo != nullptr) delete codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(char* cod) {
    if(codigo != nullptr)delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void ProductoEntregado::GetCodigo(char *buffer) const {
    if(codigo == nullptr) buffer[0] = 0;
    else 
        strcpy(buffer, codigo);
}

void ProductoEntregado::inicializa(){
    codigo = nullptr;
}

void ProductoEntregado::operator =(const ProductoEntregado &prod){
    
    char buffer[500];
    precio = prod.GetPrecio();
    prod.GetCodigo(buffer);
    SetCodigo(buffer);
}