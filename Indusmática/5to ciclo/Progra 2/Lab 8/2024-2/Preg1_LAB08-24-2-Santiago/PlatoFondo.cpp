/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlatoFondo.cpp
 * Author: santi
 * 
 * Created on 18 de junio de 2025, 10:57
 */

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
}

PlatoFondo::PlatoFondo(const PlatoFondo& orig) {
    *this = orig;
}

PlatoFondo::~PlatoFondo() {
}

void PlatoFondo::SetProteina(int proteina) {
    this->proteina = proteina;
}

int PlatoFondo::GetProteina() const {
    return proteina;
}

void PlatoFondo::operator =(const PlatoFondo& orig){
    Producto::operator =(orig);
     proteina = orig.proteina;
}

void PlatoFondo::leerDatos(ifstream &arch){
    Producto::leerDatos(arch);
    arch.get();
    arch >> proteina;
}

void PlatoFondo::imprimirDatos(ofstream &arch){
    Producto::imprimirDatos(arch);
    if(proteina ==1)
        arch << "Pollo" << endl;
    else if(proteina ==2)
        arch << "Carne" << endl;
    else if(proteina ==3)
        arch << "Pescado" << endl;
    else
        arch << "Lacteos" << endl;
}