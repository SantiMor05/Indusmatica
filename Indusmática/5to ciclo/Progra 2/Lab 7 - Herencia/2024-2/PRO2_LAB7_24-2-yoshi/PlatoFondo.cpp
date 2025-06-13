/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PlatoFondo.cpp
 * Author: YOSHI
 * 
 * Created on 12 de junio de 2025, 08:18
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina = nullptr;
}


PlatoFondo::~PlatoFondo() {
    if (proteina!=nullptr) delete []proteina;
}

void PlatoFondo::SetProteina(int pos0, int pos1, int pos2, int pos3) {
    if (proteina!=nullptr) delete []proteina;
    proteina = new int[4]{};
    proteina[0] = pos0;
    proteina[1] = pos1;
    proteina[2] = pos2;
    proteina[3] = pos3;
}

void PlatoFondo::GetProteina(int* arr) const {
    if (proteina==nullptr) arr[0] = 0;
    else{
        arr[0] = proteina[0];
        arr[1] = proteina[1];
        arr[2] = proteina[2];
        arr[3] = proteina[3];
    }
}

void PlatoFondo::llenarDatos(char *cad, double precio, int pro0, int pro1, int pro2, int pro3){
    SetNombre(cad);
    SetPrecio(precio);
    SetProteina(pro0,pro1,pro2,pro3);
}

void PlatoFondo::imprimir(ofstream &arch){
    char cad[20];
    int prote[4];
    GetNombre(cad);
    GetProteina(prote);
    arch<<left<<setw(25)<<cad<<right<<setw(10)<<GetPrecio()<<"    Proteinas: ";
    if (prote[0]) arch<<"Pollo, ";
    if (prote[1]) arch<<"Carne, ";
    if (prote[2]) arch<<"Pescado, ";
    if (prote[3]) arch<<"Lácteos. ";
    arch<<endl;
}