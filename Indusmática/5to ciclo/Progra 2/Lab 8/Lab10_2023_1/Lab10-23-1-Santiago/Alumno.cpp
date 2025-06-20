/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 18:17
 */

#include "Alumno.h"
#include <cstring>
#include <iomanip>

Alumno::Alumno() {
    inicializa();
}
//
//Alumno::Alumno(const Alumno& orig) {
//}

Alumno::~Alumno() {
    if(nombre != nullptr)delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char* nomb) {
    if(nombre == nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Alumno::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else strcpy(buffer, nombre);
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
    
}

void Alumno::lee(ifstream &arch){
    
    char nomb[60], car;
    arch >> codigo;
    arch.get();
    arch.getline(nomb, 60, ',');
    SetNombre(nomb);
    arch >> escala >> car >> creditos; 
}


void Alumno::imprime(ofstream &arch){
    
    arch << codigo <<  setw(6) << " " << left << setw(45) << nombre << right
            << setw(6) << escala << setw(10) << creditos;
    
}

void Alumno::actualizatotal(double monto){
    
    total = creditos * monto;
    
}