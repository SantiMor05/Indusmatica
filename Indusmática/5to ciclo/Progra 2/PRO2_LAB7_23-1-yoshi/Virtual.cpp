/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: YOSHI
 * 
 * Created on 10 de junio de 2025, 15:56
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Virtual.h"

Virtual::Virtual() {
    total = 100.00;
    licencia = nullptr;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* cad) {
    if (licencia!=nullptr) delete licencia;
    licencia = new char[strlen(cad)+1]{};
    strcpy(licencia,cad);
}

void Virtual::GetLicencia(char* cad) const {
    if (licencia==nullptr) cad[0] = 0;
    else strcpy(cad,licencia);
}

void Virtual::insertarDatoV(int codigo,const char *cad, int escala,const char *lic){
    setCodigo(codigo);
    setNombre(cad);
    setEscala(escala);
    SetLicencia(lic);
}

void Virtual::actualiza(double monto){
    Alumno::setTotal(total + monto);
}

void Virtual::imprimir(ofstream &arch){
    char cad[100], lic[12];
    getNombre(cad);
    GetLicencia(lic);
    arch<<getCodigo()<<"   "<<left<<setw(45)<<cad<<right<<getEscala()<<setw(12)
            <<lic<<setw(15)<<Alumno::getTotal()<<endl;
}