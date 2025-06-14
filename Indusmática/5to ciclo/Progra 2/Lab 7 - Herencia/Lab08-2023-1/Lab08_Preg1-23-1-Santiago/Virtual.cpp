/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: santi
 * 
 * Created on 11 de junio de 2025, 23:25
 */

#include "Virtual.h"
#include <cstring>
#include <iomanip>

Virtual::Virtual() {
    inicializa();
}

//Virtual::Virtual(const Virtual& orig) {
//}

Virtual::~Virtual() {
    if(licencia != nullptr) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char* licen) {
    if(licencia != nullptr) delete licencia;
    licencia = new char[strlen(licen) + 1];
    strcpy(licencia, licen);
}

void Virtual::GetLicencia(char *buffer) const {
    if(licencia == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, licencia);
}

void Virtual::inicializa(){
    licencia = nullptr;
    total = 100;
}

void Virtual::leerDatos(ifstream &arch){
    char buffer[20];
    int escala;
    Alumno::leerDatos(arch);
    arch.getline(buffer, 20, ',');
    SetLicencia(buffer);
    arch >> escala;
    SetEscala(escala);
}

void Virtual::imprime(ofstream &arch){
    Alumno::imprime(arch);
    
    arch << setw(12) << licencia << setw(13) << Alumno::GetTotal() <<  endl;
}

void Virtual::actualiza(double precio){
    Alumno::SetTotal(precio + total);
}