/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: Lenovo
 * 
 * Created on 18 de junio de 2025, 03:05 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Virtual.h"
using namespace std;

Virtual::Virtual() {
    licencia = nullptr;
    //total = 0.0;
    total = 100;
}

Virtual::~Virtual() {
    if(licencia != nullptr)delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* lic) {
    if(licencia != nullptr)delete licencia;
    licencia = new char[strlen(lic) + 1];
    strcpy(licencia, lic);
}

void Virtual::GetLicencia(char *lic) const {
    if(licencia == nullptr)lic[0] = 0;
    else strcpy(lic, licencia);
}

void Virtual::lee(ifstream &arch){
    char aux[30];
    Alumno::lee(arch);
    arch.getline(aux,30);
    SetLicencia(aux);
}
void Virtual::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<right<<setw(15)<<licencia<<setw(11)<<Alumno::getTotal()<<endl;
}

void Virtual::actualiza(double monto){
    Alumno::setTotal(monto+total);
}