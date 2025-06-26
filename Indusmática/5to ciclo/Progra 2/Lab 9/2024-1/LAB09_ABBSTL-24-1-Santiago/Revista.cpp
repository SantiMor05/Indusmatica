/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.cpp
 * Author: santi
 * 
 * Created on 25 de junio de 2025, 22:26
 */

#include "Revista.h"
#include <iomanip>

Revista::Revista() {
}

Revista::Revista(const Revista& orig) {
}

Revista::~Revista() {
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

void Revista::lee(ifstream &arch){
    char car;
    Libro::lee(arch);
    arch.get();
    
    arch >> ISSN >> car >> anho >> car >> numero;
}

void Revista::imprime(ofstream &arch){
    
    Libro::imprime(arch);
    arch << "ISSN: " << setw(10) << ISSN << setw(8) << "Año: " << anho << endl; 
    
}