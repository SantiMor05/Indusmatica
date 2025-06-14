/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: santi
 * 
 * Created on 11 de junio de 2025, 23:15
 */

#include "Alumno.h"
#include <cstring>
#include <iomanip>

Alumno::Alumno() {
    inicializa();
}

//Alumno::Alumno(const Alumno& orig) {
//}

Alumno::~Alumno() {
    if(nombre != nullptr)
        delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Alumno::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::inicializa(){
    nombre = nullptr;
    total = 0;
    escala = 0;
}

void Alumno::leerDatos(ifstream &arch){
    
    char buffer[100];
    
    arch >> codigo;
    arch.get();
    arch.getline(buffer, 100, ',');
    SetNombre(buffer);
}

void Alumno::imprime(ofstream &arch){
    arch << codigo << setw(5) << " " << left << setw(50) << nombre << right <<
            setw(6) << escala;
}