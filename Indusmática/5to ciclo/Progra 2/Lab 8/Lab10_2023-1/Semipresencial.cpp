/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.cpp
 * Author: kenyi
 * 
 * Created on 19 de junio de 2025, 04:01 PM
 */
#include <iomanip>
using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total=0;
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

void Semipresencial::leer(ifstream& arch) {
    Alumno::leer(arch);
    arch>>descuento;
    arch.get();
}

void Semipresencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<< setw(6) << descuento << setw(6) << total << endl;
}

void Semipresencial::actualiza(double prec) {
    total= prec*GetEscala()*(1-descuento/100);
    Alumno::SetTotal(total);
}

