/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: santi
 * 
 * Created on 25 de junio de 2025, 22:24
 */

#include "Enciclopedia.h"
#include <iomanip>

Enciclopedia::Enciclopedia() {
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

void Enciclopedia::lee(ifstream &arch){
    char car;
    Libro::lee(arch);
    arch.get();
    arch >> sku >> car >> anho;
    
}


void Enciclopedia::imprime(ofstream &arch){
    
    Libro::imprime(arch);
    arch << "SKU:"<<setw(8) << sku << setw(8) << "Año: " << anho << endl;
    
}