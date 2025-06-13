/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Lenovo
 * 
 * Created on 12 de junio de 2025, 05:20 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Producto.h"
using namespace std;

Producto::Producto() {
    nombre = nullptr;
}


Producto::~Producto() {
    if(nombre != nullptr)delete nombre;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(const char* nomb) {
    if(nombre != nullptr)delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Producto::GetNombre(char* nomb) const {
    if(nombre == nullptr)nomb[0] = 0;
    else strcpy(nomb, nombre);
}
void Producto::inicaliza(){
    nombre = nullptr;
}
void Producto::operator =(const class Producto &orig){
    char aux[60];
    orig.GetNombre(aux);
    SetNombre(aux);
    
    precio = orig.precio;
}

/*
 142,E,   Quesadillas,5.5,
 142,E,   Bruschetta,4,
 */
void Producto::leerDatos(ifstream &arch){
    char aux[60];
    arch.getline(aux, 60, ',');
    SetNombre(aux);
    arch>>precio;
    arch.get();
}

//Imprimir
void Producto::imprimir(ofstream &arch){
    arch<<left<<setw(60)<<nombre<<right<<setw(12)<<precio<<setw(4)<<" ";
}
