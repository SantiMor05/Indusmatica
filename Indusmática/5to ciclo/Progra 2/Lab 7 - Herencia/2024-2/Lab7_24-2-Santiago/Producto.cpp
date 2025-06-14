/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 19:23
 */

#include "Producto.h"
#include <cstring>
#include <iomanip>

Producto::Producto() {
    nombre = nullptr;
}

//Producto::Producto(const Producto& orig) {
//}

Producto::~Producto() {
    if(nombre != nullptr)
        delete nombre;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Producto::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, nombre);
}

void Producto::inicializa(){
    nombre = nullptr;
}

void Producto::leerProducto(ifstream &arch){
    
    char nomb[60];
    arch.getline(nomb, 60, ',');
    if(arch.eof())return;
    SetNombre(nomb);
    arch >> precio;
    
}

void Producto::imprimirProducto(ofstream &arch)const{
    arch << setw(5) << " " << left << setw(40) << nombre << right << setw(8) 
            << precio;
}