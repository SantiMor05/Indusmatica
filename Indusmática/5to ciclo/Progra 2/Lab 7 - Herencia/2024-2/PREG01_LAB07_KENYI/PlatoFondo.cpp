/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlatoFondo.cpp
 * Author: kenyi
 * 
 * Created on 12 de junio de 2025, 04:19 PM
 */
#include <fstream>
#include <iomanip>
using namespace std;
#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina = nullptr;
}

PlatoFondo::~PlatoFondo() {
    if (proteina != nullptr)delete proteina;
}

void PlatoFondo::SetProteina(int prot1,
        int prot2, int prot3, int prot4) {
    if (proteina != nullptr)delete proteina;
    proteina = new int[4];
    proteina[0] = prot1;
    proteina[1] = prot2;
    proteina[2] = prot3;
    proteina[3] = prot4;
}

void PlatoFondo::GetProteina(int*prot) const {
    if (proteina == nullptr) prot[0] = 0;
    else {
        prot[0] = proteina[0];
        prot[1] = proteina[1];
        prot[2] = proteina[2];
        prot[3] = proteina[3];
    }
}

void PlatoFondo::leerPlat(ifstream& arch) {
    char aux[60], c;
    int prot1, prot2, prot3, prot4;
    double prec;
    arch.getline(aux, 60, ',');
    SetNombre(aux);
    arch>>prec;
    arch.get();
    SetPrecio(prec);
    arch >> prot1 >> c >> prot2 >> c >> prot3 >> c>>prot4;
    SetProteina(prot1, prot2, prot3, prot4);
}

void PlatoFondo::imprimirPlat(ofstream& arch) {
    int prot[4];
    char nomb[60];
    GetNombre(nomb);
    GetProteina(prot);
    arch << setw(40) << left << nomb << right << setw(12) << GetPrecio() << " ";
    if (prot[0]) arch << "Pollo, ";
    if (prot[1]) arch << "Carne, ";
    if (prot[2]) arch << "Pescado, ";
    if (prot[3]) arch << "Lácteos. ";
    arch << endl;
}

