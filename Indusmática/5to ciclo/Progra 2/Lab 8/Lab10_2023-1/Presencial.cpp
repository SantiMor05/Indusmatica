/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.cpp
 * Author: kenyi
 * 
 * Created on 19 de junio de 2025, 03:58 PM
 */
#include <fstream>
#include <iomanip>
using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    total=0;
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

void Presencial::leer(ifstream& arch) {
    Alumno::leer(arch);
    arch>>recargo;
    arch.get();
}

void Presencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<< setw(4) << recargo << setw(6) << total << endl;
}

void Presencial::actualiza(double prec) {
    total=prec*GetEscala()*(1+GetRecargo()/100);
    Alumno::SetTotal(total);
}
