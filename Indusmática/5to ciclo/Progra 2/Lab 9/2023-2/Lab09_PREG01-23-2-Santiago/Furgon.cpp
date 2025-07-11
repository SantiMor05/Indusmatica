/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.cpp
 * Author: santi
 * 
 * Created on 26 de junio de 2025, 18:38
 */

#include "Furgon.h"
#include <iterator>

Furgon::Furgon() {
}

Furgon::Furgon(const Furgon& orig) {
}

Furgon::~Furgon() {
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::lee(ifstream& arch){
    char car;
    Vehiculo::lee(arch);
    arch.get();
    
    arch >> filas >> car  >> puertas;
    
}

void Furgon::imprime(ofstream &arch){
    
    Vehiculo::imprime(arch);
    arch << "#Filas:         " << filas << endl;
    arch << "#Puertas:       " << puertas << endl;
    
    for(list<NPedido>::iterator it = pdeposito.begin(); it != pdeposito.end(); it++){
        it;
    }
    
}