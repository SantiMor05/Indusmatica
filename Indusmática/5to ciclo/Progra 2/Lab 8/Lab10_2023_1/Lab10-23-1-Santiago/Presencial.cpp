/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 18:22
 */

#include "Presencial.h"
#include <iomanip>

Presencial::Presencial() {
    total = 0;
}

//Presencial::Presencial(const Presencial& orig) {
//}

Presencial::~Presencial() {
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

void Presencial::lee(ifstream &arch){
    
    Alumno::lee(arch);
    arch.get();
    arch >> recargo;
    
}

void Presencial::imprime(ofstream &arch){
    
    Alumno::imprime(arch);
    arch << setw(22) << Alumno::GetTotal() << endl;
    
}


void Presencial::actualizatotal(double escala){
    
    Alumno::actualizatotal(escala);
    
    double monto = Alumno::GetTotal() * recargo / 100;
    total = monto;
    
    Alumno::SetTotal(Alumno::GetTotal() + monto);
    
}