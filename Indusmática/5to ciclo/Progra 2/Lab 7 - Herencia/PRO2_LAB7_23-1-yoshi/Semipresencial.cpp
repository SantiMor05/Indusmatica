/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: YOSHI
 * 
 * Created on 10 de junio de 2025, 15:56
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial() {
}

Semipresencial::Semipresencial(const Semipresencial& orig) {
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

void Semipresencial::insertarDatoS(int codigo,const char* cad,int escala,double monto){
    setCodigo(codigo);
    setNombre(cad);
    setEscala(escala);
    SetDescuento(monto);
}

void Semipresencial::actualiza(double monto){
    total = descuento/100*monto;
    Alumno::setTotal(monto - total);
}

void Semipresencial::imprimir(ofstream &arch){
    char cad[100];
    getNombre(cad);
    arch<<getCodigo()<<"   "<<left<<setw(45)<<cad<<right<<getEscala()<<setw(12)
            <<"-"<<setw(15)<<Alumno::getTotal()<<endl;
}