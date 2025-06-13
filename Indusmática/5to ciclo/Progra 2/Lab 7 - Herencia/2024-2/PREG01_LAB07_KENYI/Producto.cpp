/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: kenyi
 * 
 * Created on 12 de junio de 2025, 04:15 PM
 */

#include <cstring>

#include "Producto.h"

Producto::Producto() {
    nombre=nullptr;
}

Producto::~Producto() {
    if(nombre!=nullptr)delete nombre;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(const char* nomb) {
    if (nombre != nullptr)delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Producto::GetNombre(char * nomb) const {
    if (nombre == nullptr)nomb[0] = 0;
    else strcpy(nomb, nombre);
}

