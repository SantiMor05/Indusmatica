/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: YOSHI
 * 
 * Created on 12 de junio de 2025, 08:17
 */


#include <cstring>
using namespace std;
#include "Producto.h"

Producto::Producto() {
    nombre = nullptr;
}

Producto::~Producto() {
    if (nombre!=nullptr) delete nombre;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(const char* cad) {
    if (nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1]{};
    strcpy(nombre,cad);
}

void Producto::GetNombre(char* cad) const {
    if (nombre==nullptr) cad[0] = 0;
    else strcpy(cad,nombre);
}

