/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: santi
 * 
 * Created on 18 de junio de 2025, 10:47
 */

#include "Producto.h"
#include <cstring>

Producto::Producto() {
    inicializa();
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

void Producto::operator =(const Producto& orig){
    precio = orig.GetPrecio();
    char buffer[200];
    orig.GetNombre(buffer);
    SetNombre(buffer);
}

void Producto::leerDatos(ifstream &arch){
    char nomb[100];
    
    arch.getline(nomb, 100, ',');
    if(arch.eof())return;
    SetNombre(nomb);
    arch >> precio;
}

void Producto::imprimirDatos(ofstream &arch){
    char nomb[100];
    GetNombre(nomb);
    arch << "Nombre: " << nomb << endl;
    arch << "Precio: " << precio << endl;
}