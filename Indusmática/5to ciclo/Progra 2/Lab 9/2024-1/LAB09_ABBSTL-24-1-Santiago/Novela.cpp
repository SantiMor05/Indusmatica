/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.cpp
 * Author: santi
 * 
 * Created on 25 de junio de 2025, 22:25
 */

#include "Novela.h"
#include <iomanip>
Novela::Novela() {
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
}

void Novela::SetAutor(string &autor) {
    this->autor = autor;
}

string Novela::GetAutor() const {
    return autor;
}

void Novela::lee(ifstream &arch){
    
    Libro::lee(arch);
    arch.get();
    
    getline(arch, autor, '\n');
    
}

void Novela::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch << "Autor: " << autor << endl;
}

