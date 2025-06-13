/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Bebida.cpp
 * Author: Lenovo
 * 
 * Created on 12 de junio de 2025, 05:20 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Bebida.h"
using namespace std;

Bebida::Bebida() {
    tamano = nullptr;
}

Bebida::~Bebida() {
    if(tamano != nullptr)delete tamano;
}

void Bebida::SetTamano(const char* tam) {
    if(tamano != nullptr)delete tamano;
    tamano = new char[strlen(tam) + 1];
    strcpy(tamano, tam);
}

void Bebida::GetTamano(char* tam) const {
    if(tamano == nullptr)tam[0] = 0;
    else strcpy(tam, tamano);
}

/*
 161,B,Agua Mineral,2.5,mediano
 */

//Leer datos
void Bebida::leerDatos(ifstream &arch){
    char aux[60];
    Producto::leerDatos(arch);
    arch>>aux;
    arch.get();
    SetTamano(aux);
}

//Imprimir
void Bebida::imprimir(ofstream &arch){
    Producto::imprimir(arch);
    arch<<"TAMAÑO: ";
    arch<<setw(20)<<left<<tamano<<endl;
}