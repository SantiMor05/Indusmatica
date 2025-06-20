/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 14:27
 */

#include "Furgon.h"
#include <iomanip>

Furgon::Furgon() {
}

//Furgon::Furgon(const Furgon& orig) {
//}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
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

void Furgon::lee(ifstream &arch){
    char car;
    Vehiculo::lee(arch);
    arch >>  car >> filas >> car >> puertas;
}



void Furgon::imprime(ofstream &arch){
    
    Vehiculo::imprime(arch);
    arch << "#Filas: " << setw(19) << filas << endl;
    arch << "#Puertas: " << setw(17) << puertas << endl;
    imprimePedidos(arch);
}