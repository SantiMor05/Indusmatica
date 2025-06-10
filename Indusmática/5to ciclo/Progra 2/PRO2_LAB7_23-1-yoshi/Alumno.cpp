/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: YOSHI
 * 
 * Created on 10 de junio de 2025, 15:54
 */

#include <cstring>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    construir();
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
}

void Alumno::construir(){
    nombre = nullptr;
    codigo = 0;
}

void Alumno::setTotal(double total) {
    this->total = total;
}

double Alumno::getTotal() const {
    return total;
}

void Alumno::setEscala(int escala) {
    this->escala = escala;
}

int Alumno::getEscala() const {
    return escala;
}

void Alumno::setNombre(const char* cad) {
    if (nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1]{};
    strcpy(nombre,cad);
}

void Alumno::getNombre(char* cad) const {
    if (nombre==nullptr) cad[0] = 0;
    else strcpy(cad,nombre);
}

void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::getCodigo() const {
    return codigo;
}