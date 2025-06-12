/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Entrada.cpp
 * Author: YOSHI
 * 
 * Created on 12 de junio de 2025, 08:18
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Entrada.h"

Entrada::Entrada() {
}


Entrada::~Entrada() {
}

void Entrada::SetPicante(bool picante) {
    this->picante = picante;
}

bool Entrada::IsPicante() const {
    return picante;
}

void Entrada::llenarDatos(char *nombre, double precio, char *picante){
    SetNombre(nombre);
    SetPrecio(precio);
    if (strcmp(picante,"picante")==0) SetPicante(true);
    else SetPicante(false);
}

void Entrada::imprimir(ofstream &arch){
    char cad[20];
    GetNombre(cad);
    arch<<left<<setw(25)<<cad<<right<<setw(10)<<GetPrecio()<<"    Picante: ";
    if (IsPicante()) arch<<"SI"<<endl;
    else arch<<" NO"<<endl;
}