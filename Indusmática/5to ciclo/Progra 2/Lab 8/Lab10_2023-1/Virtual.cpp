/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: kenyi
 * 
 * Created on 19 de junio de 2025, 04:02 PM
 */

#include <cstring>
#include <iomanip>
#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
}

Virtual::~Virtual() {
    if (licencia != nullptr)delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* lic) {
    if (licencia != nullptr)delete licencia;
    licencia = new char[strlen(lic) + 1];
    strcpy(licencia, lic);
}

void Virtual::GetLicencia(char* lic) const {
    if (licencia == nullptr)lic[0] = 0;
    else strcpy(lic, licencia);
}

void Virtual::leer(ifstream& arch) {
    char lic[10];
    Alumno::leer(arch);
    arch.getline(lic, 10);
    SetLicencia(lic);
}

void Virtual::imprime(ofstream& arch) {
    char lic[10];
    GetLicencia(lic);
    Alumno::imprime(arch);
    arch << " " << lic << " " << total << endl;
}

void Virtual::actualiza(double prec) {
    total = prec*GetCreditos()+100;
    Alumno::SetTotal(total);
}




