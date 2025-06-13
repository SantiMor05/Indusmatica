/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bebida.cpp
 * Author: kenyi
 * 
 * Created on 12 de junio de 2025, 04:16 PM
 */

#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Bebida.h"

Bebida::Bebida() {
    tamano = nullptr;
}

Bebida::~Bebida() {
    if (tamano != nullptr)delete tamano;
}

void Bebida::SetTamano(const char* tam) {
    if (tamano != nullptr)delete tamano;
    tamano = new char[strlen(tam) + 1];
    strcpy(tamano, tam);
}

void Bebida::GetTamano(char* tam) const {
    if (tamano == nullptr)tam[0] = 0;
    else strcpy(tam, tamano);
}

void Bebida::leerBeb(ifstream& arch) {
    char aux[60];
    double prec;
    arch.getline(aux, 60, ',');
    SetNombre(aux);
    arch>>prec;
    arch.get();
    SetPrecio(prec);
    arch.getline(aux, 60);
    SetTamano(aux);
}

void Bebida::imprimirBeb(ofstream& arch) {
    char nomb[60];
    GetNombre(nomb);
    arch << setw(40) << left << nomb << right << setw(12) << GetPrecio() << "  "
            << setw(20) << left << tamano << right << endl;
}



