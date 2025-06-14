/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conreceta.cpp
 * Author: santi
 * 
 * Created on 12 de junio de 2025, 22:12
 */

#include "Conreceta.h"
#include <cstring>
#include <iomanip>
using namespace std;

Conreceta::Conreceta() {
    inicializa();
}

//Conreceta::Conreceta(const Conreceta& orig) {
//}

Conreceta::~Conreceta() {
    if(especialidad != nullptr) delete especialidad;
}

void Conreceta::SetEspecialidad(char* esp) {
    if(especialidad != nullptr) delete especialidad;
    especialidad = new char[strlen(esp) + 1];
    strcpy(especialidad, esp);
}

void Conreceta::GetEspecialidad(char *buffer) const {
    if(especialidad == nullptr) buffer[0] = 0;
    else strcpy(buffer, especialidad);
}

void Conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int Conreceta::GetCodmed() const {
    return codmed;
}

void Conreceta::inicializa(){
    especialidad = nullptr;
}

void Conreceta::asigna(ifstream &arch, int medicamento, int cantidad,
            const Medico &medico,int fecha){
    char espe[30];
    codmed = medico.GetCodigo();
    medico.GetEspecialidad(espe);
    SetEspecialidad(espe);
    buscarLeerMedicamento(arch, medicamento);
    
    SetCantidad(cantidad);
    SetFecha(fecha);
}

void Conreceta::imprimir(ofstream &arch){
    Medicamento::imprimir(arch);
    arch << setw(12) << codmed << setw(4) << " " << especialidad << endl;
}