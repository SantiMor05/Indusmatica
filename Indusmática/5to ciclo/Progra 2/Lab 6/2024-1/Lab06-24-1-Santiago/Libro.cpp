/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: santi
 * 
 * Created on 4 de junio de 2025, 19:55
 */

#include "Libro.h"
#include <cstring>

Libro::Libro() {
    inicializa();
}

Libro::Libro(const Libro& orig) {
    inicializa();
    *this = orig;
}

Libro::~Libro() {
    if(codigo != nullptr)delete codigo;
    if(nombre != nullptr)delete nombre;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Libro::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else 
        strcpy(buffer, nombre);
}

void Libro::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Libro::GetCodigo(char *buffer) const {
    if(codigo == nullptr) buffer[0] = 0;
    else 
        strcpy(buffer, codigo);
}

void Libro::inicializa(){
    
    codigo = nullptr;
    nombre = nullptr;
    colocado = false;
}

void Libro::operator = (const Libro &lib){
    
    char buffer[500];
    lib.GetCodigo(buffer);
    SetCodigo(buffer);
    
    lib.GetNombre(buffer);
    SetNombre(buffer);
    
    ancho = lib.GetAncho();
    alto = lib.GetAlto();
    colocado = lib.IsColocado();
}


void operator >> (ifstream &arch, Libro &libro){
    
    char buffer[500] , car;
    int ancho, alto;
    
    arch.getline(buffer, 500, ',');
    if(arch.eof())return;
    libro.SetCodigo(buffer);
    arch.getline(buffer, 500, ',');
    libro.SetNombre();
    
    arch >> ancho >> car >> alto;
    arch.get();//Leemos el salto de linea
    libro.SetAlto(alto);
    libro.SetAncho(ancho);
}