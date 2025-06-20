/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 18:23
 */

#include "Semipresencial.h"
#include <iomanip>

Semipresencial::Semipresencial() {
    total = 0;
}

//Semipresencial::Semipresencial(const Semipresencial& orig) {
//}

Semipresencial::~Semipresencial() {
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::lee(ifstream &arch){
    
    Alumno::lee(arch);
    arch.get();
    arch >> descuento;
    
}

void Semipresencial::imprime(ofstream &arch){
    
    Alumno::imprime(arch);
    arch << setw(22) << Alumno::GetTotal() << endl;
    
}

void Semipresencial::actualizatotal(double escala){
    
    Alumno::actualizatotal(escala);
    
    double monto = Alumno::GetTotal() * descuento / 100;
    total = monto;
    
    Alumno::SetTotal(Alumno::GetTotal() - monto);
    
}