/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Lenovo
 * 
 * Created on 18 de junio de 2025, 03:04 PM
 */

#include <iostream>
#include <iomanip>
#include "Semipresencial.h"
using namespace std;

Semipresencial::Semipresencial() {
    total = 0;
}

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
    arch>>descuento;
    arch.get();
}
void Semipresencial::imprime(ofstream &arch){
    Alumno::imprime(arch);
    arch<<right<<setw(16)<<"-"<<setw(15)<<Alumno::getTotal()<<endl;
}

void Semipresencial::actualiza(double monto){
    total = monto*GetDescuento()/100;
    Alumno::setTotal(monto-total);
}

