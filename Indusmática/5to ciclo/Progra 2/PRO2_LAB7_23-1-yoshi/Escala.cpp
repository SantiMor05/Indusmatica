/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Escala.cpp
 * Author: YOSHI
 * 
 * Created on 10 de junio de 2025, 15:54
 */

#include <fstream>
using namespace std;
#include "Escala.h"

Escala::Escala() {
}

Escala::Escala(const Escala& orig) {
}

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

void operator >>(ifstream &arch, Escala &escala){
    int num;
    double monto;
    arch>>num;
    if (arch.eof()) return;
    arch.get();
    arch>>monto;
    escala.SetCodigo(num);
    escala.SetPrecio(monto);
}

double Busca_escala(Escala *escalas,int escalin){
    for (int i = 0; escalas[i].GetCodigo(); i++) {
        if (escalas[i].GetCodigo() == escalin) 
            return escalas[i].GetPrecio();
    }
    return -1;
}