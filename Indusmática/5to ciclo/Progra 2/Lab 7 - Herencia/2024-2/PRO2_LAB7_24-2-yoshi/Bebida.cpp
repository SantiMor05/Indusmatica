/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Bebida.cpp
 * Author: YOSHI
 * 
 * Created on 12 de junio de 2025, 08:17
 */
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Bebida.h"

Bebida::Bebida() {
    tamano = nullptr;
}

Bebida::~Bebida() {
    if (tamano!=nullptr) delete tamano;
}

void Bebida::SetTamano(const char* cad) {
    if (tamano!=nullptr) delete tamano;
    tamano = new char[strlen(cad)+1]{};
    strcpy(tamano,cad);
}

void Bebida::GetTamano(char* cad) const {
    if (tamano==nullptr) cad[0] = 0;
    else strcpy(cad,tamano);
}

void Bebida::llenarDatos(char *cad, double precio, char* tam){
    SetNombre(cad);
    SetPrecio(precio);
    SetTamano(tam);
}

void Bebida::imprimir(ofstream &arch){
    char cad[20], tam[20];
    GetNombre(cad);
    GetTamano(tam);
    arch<<left<<setw(25)<<cad<<right<<setw(10)<<GetPrecio()<<"    Tamaño: "<<tam<<endl;
}