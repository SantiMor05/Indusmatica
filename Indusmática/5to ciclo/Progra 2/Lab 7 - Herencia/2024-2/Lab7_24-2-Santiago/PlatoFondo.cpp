/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlatoFondo.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 19:52
 */

#include "PlatoFondo.h"
#include <iomanip>

PlatoFondo::PlatoFondo() {
    proteina = nullptr;
}

//PlatoFondo::PlatoFondo(const PlatoFondo& orig) {
//}

PlatoFondo::~PlatoFondo() {
    if (proteina != nullptr)
        delete proteina;
}

void PlatoFondo::leerProteina(ifstream &arch) {

    leerProducto(arch);
    int contiene, cont = 0;
    char car;

    if (proteina == nullptr)
        proteina = new int[4] {
        };

    while (arch.get() != '\n') {
        arch >> contiene;
        proteina[cont] = contiene;
        cont++;
    }
}

void PlatoFondo::imprimirDatos(ofstream &arch)const{
    
    imprimirProducto(arch);
    
    if(proteina != nullptr){
        
        arch << setw(5) << " "<<"Incluye: ";
        
        if(proteina[0])
            arch << setw(10) << "Pollo";
        if(proteina[1])
            arch << setw(10) << "Carne";
        if(proteina[2])
            arch << setw(10) << "Pescado";
        if(proteina[3])
            arch << setw(10) << "Lacteos";
    }
    arch << endl;
}

void operator << (ofstream &arch, const PlatoFondo &plato){
    plato.imprimirDatos(arch);
}