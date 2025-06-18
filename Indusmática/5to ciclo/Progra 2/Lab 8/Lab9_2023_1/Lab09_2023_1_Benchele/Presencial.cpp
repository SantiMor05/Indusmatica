/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: Lenovo
 * 
 * Created on 18 de junio de 2025, 03:04 PM
 */

#include <iostream>
#include <iomanip>
#include "Presencial.h"
using namespace std;

Presencial::Presencial() {
    total = 0;
}

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
    arch>>recargo;
    arch.get();
}
void Presencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<right<<setw(15)<<"+"<<setw(11)<<Alumno::getTotal()<<endl;
}

void Presencial::actualiza(double monto){
    total = monto*GetRecargo()/100;
    Alumno::setTotal(monto+total);
}