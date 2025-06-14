/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.cpp
 * Author: santi
 * 
 * Created on 11 de junio de 2025, 23:21
 */

#include "Presencial.h"
#include <iomanip>

Presencial::Presencial() {
}

//Presencial::Presencial(const Presencial& orig) {
//}

Presencial::~Presencial() {
    total = 0;
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::leerDatos(ifstream &arch){
    int escala;
    Alumno::leerDatos(arch);
//    arch.get();
    arch >> recargo;
    arch.get();
    arch >> escala;
    SetEscala(escala);
}


void Presencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    
    arch << setw(25) << Alumno::GetTotal() << endl;
}

void Presencial::actualiza(double precio){
    total = precio * recargo / 100;
    Alumno::SetTotal(total + precio);
}