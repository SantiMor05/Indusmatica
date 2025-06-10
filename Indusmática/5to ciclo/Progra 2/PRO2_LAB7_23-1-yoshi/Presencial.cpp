/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: YOSHI
 * 
 * Created on 10 de junio de 2025, 15:55
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
}

Presencial::Presencial(const Presencial& orig) {
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

void Presencial::insertarDatoP(int codigo,const char* cad,int escala,double monto){
    setCodigo(codigo);
    setNombre(cad);
    setEscala(escala);
    SetRecargo(monto);
}

void Presencial::actualiza(double monto){
    total = recargo/100*monto;
    Alumno::setTotal(monto + total);
}

void Presencial::imprimir(ofstream &arch){
    char cad[100];
    getNombre(cad);
    arch<<getCodigo()<<"   "<<left<<setw(45)<<cad<<right<<getEscala()<<setw(12)
            <<"-"<<setw(15)<<Alumno::getTotal()<<endl;
}