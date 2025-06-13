/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrada.cpp
 * Author: kenyi
 * 
 * Created on 12 de junio de 2025, 04:18 PM
 */
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
#include "Entrada.h"

Entrada::Entrada() {
    picante = false;
}

void Entrada::SetPicante(bool picante) {
    this->picante = picante;
}

bool Entrada::IsPicante() const {
    return picante;
}

void Entrada::leerEnt(ifstream& arch) {
    char aux[60], c;
    bool picante = false;
    double prec;
    arch.getline(aux, 60, ',');
    SetNombre(aux);
    arch>>prec;
    arch.get();
    SetPrecio(prec);
    arch.getline(aux, 60);
    if (strcmp(aux, "picante") == 0)picante = true;
    SetPicante(picante);
}

void Entrada::imprimirEnt(ofstream& arch) {
    char nomb[60];
    GetNombre(nomb);
    arch << setw(40) << left << nomb << right << setw(12) << GetPrecio();
    if (IsPicante()) arch << "  Picante" << endl;
    else arch << "  No es picante" << endl;
}

