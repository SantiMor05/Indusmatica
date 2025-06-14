/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.cpp
 * Author: santi
 * 
 * Created on 11 de junio de 2025, 23:23
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


void Semipresencial::leerDatos(ifstream &arch){
    int escala;
    
    Alumno::leerDatos(arch);
    arch >> descuento;
    arch.get();
    arch >> escala;
    SetEscala(escala);
    
}


void Semipresencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch << setw(25) << Alumno::GetTotal() << endl;
}

void Semipresencial::actualiza(double precio){
    total = precio * descuento / 100;
    Alumno::SetTotal(precio - total);
}