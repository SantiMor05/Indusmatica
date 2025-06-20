/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 18:24
 */

#include "Virtual.h"
#include <iomanip>
#include <cstring>


Virtual::Virtual() {
    inicializa();
}

Virtual::Virtual(const Virtual& orig) {
    if(licencia != nullptr) delete licencia;
}

Virtual::~Virtual() {
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char* lic) {
    if(licencia != nullptr)delete licencia;
    licencia = new char[strlen(lic) +  1];
    strcpy(licencia, lic);
}

void Virtual::GetLicencia(char *buffer) const {
    if(licencia == nullptr)buffer[0] = 0;
    else
        strcpy(buffer, licencia);
}

void Virtual::inicializa(){
    licencia = nullptr;    
    total = 0;
}

void Virtual::lee(ifstream &arch){
    char lic[12];
    
    Alumno::lee(arch);
    arch.get();
    arch.getline(lic, 12);
    SetLicencia(lic);
}

void Virtual::imprime(ofstream &arch){
    
    Alumno::imprime(arch);
    arch << setw(12) << licencia << setw(10) << Alumno::GetTotal() << 
            endl;    
}

void Virtual::actualizatotal(double escala){
    
    Alumno::actualizatotal(escala);
    total = 100;
    Alumno::SetTotal(Alumno::GetTotal() + total);
    
}