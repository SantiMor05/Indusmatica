/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.cpp
 * Author: kenyi
 * 
 * Created on 19 de junio de 2025, 04:05 PM
 */

#include "Boleta.h"
#include "Virtual.h"
#include "Presencial.h"
#include "Semipresencial.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::~Boleta() {
    if (pboleta != nullptr)delete pboleta;
}

void Boleta::leer(char tipo, ifstream& arch) {
    if (tipo == 'P') {
        pboleta = new Presencial;
    } else if (tipo == 'S') {
        pboleta = new Semipresencial;
    } else {
        pboleta = new Virtual;
    }

    pboleta->leer(arch);
}

bool Boleta::operator>(const class Boleta &dato) const {
    int cod1 = pboleta->GetCodigo();
    int cod2 = dato.getCodigo();
    return cod1>cod2;
}

int Boleta::getCodigo() const {
    return pboleta->GetCodigo();
}

void Boleta::imprime(ofstream& arch) const {
    pboleta->imprime(arch);
}

void Boleta::inicializa() {
    pboleta = nullptr;
}

void operator<<(ofstream&arch, const class Boleta &boleta) {
    boleta.imprime(arch);
}

int Boleta::getEscala() {
    pboleta->GetEscala();
}

void Boleta::actualiza(double prec) {
    pboleta->actualiza(prec);
}
