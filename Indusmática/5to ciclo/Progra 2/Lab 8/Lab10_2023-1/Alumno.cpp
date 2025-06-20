/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: kenyi
 * 
 * Created on 19 de junio de 2025, 03:50 PM
 */

#include <cstring>
#include <iomanip>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
    total = 0;
}

Alumno::~Alumno() {
    if (nombre != nullptr)delete nombre;
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

void Alumno::SetNombre(const char* nomb) {
    if (nombre != nullptr)delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Alumno::GetNombre(char* nomb) const {
    if (nombre == nullptr)nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::leer(ifstream& arch) {
    char nombre[60];
    arch>>codigo;
    arch.get();
    arch.getline(nombre, 60, ',');
    SetNombre(nombre);
    arch>>escala;
    arch.get();
    arch>>creditos;
    arch.get();
}

void Alumno::imprime(ofstream& arch) {
    arch << codigo << " " << setw(60) << left << nombre << setw(16)
            << right << escala << setw(8) << creditos << setw(8)
            << total;
}

