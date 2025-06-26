/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.cpp
 * Author: santi
 * 
 * Created on 25 de junio de 2025, 22:23
 */

#include "Libro.h"
#include <iomanip>

Libro::Libro() {
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(string &nombre) {
    this->nombre = nombre;
}

string Libro::GetNombre() const {
    return nombre;
}

void Libro::lee(ifstream &arch){
    char car;
    getline(arch, nombre, ',');
    arch >> paginas >> car  >> peso;
    
}


void Libro::imprime(ofstream &arch){
    
    arch << "Titulo: " << nombre << endl;
    arch << "Peso: " << peso << endl;
    
}