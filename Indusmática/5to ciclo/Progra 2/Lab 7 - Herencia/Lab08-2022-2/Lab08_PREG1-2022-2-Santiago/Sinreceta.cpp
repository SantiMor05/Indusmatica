/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sinreceta.cpp
 * Author: santi
 * 
 * Created on 12 de junio de 2025, 22:16
 */

#include "Sinreceta.h"
#include <cstring>
#include <iomanip>
using namespace std;

Sinreceta::Sinreceta() {
    inicializa();
}

//Sinreceta::Sinreceta(const Sinreceta& orig) {
//}

Sinreceta::~Sinreceta() {
    if(nombre != nullptr) delete nombre;
}

void Sinreceta::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Sinreceta::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else strcpy(buffer, nombre);
}

void Sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int Sinreceta::GetDni() const {
    return dni;
}

void Sinreceta::inicializa(){
    nombre = nullptr;
}

void Sinreceta::asigna(ifstream &arch, int medicamento, int cantidad, int doc, 
            char *nomb, int fecha){
    
    buscarLeerMedicamento(arch, medicamento);
    dni = doc;
    SetNombre(nomb);
    SetFecha(fecha);
    SetCantidad(cantidad);
    
}

void Sinreceta::imprimir(ofstream &arch){
    
    Medicamento::imprimir(arch);
    arch << setw(15) << dni << setw(4) << " " << nombre << endl;
    
}