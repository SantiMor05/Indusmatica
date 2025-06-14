/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medico.cpp
 * Author: santi
 * 
 * Created on 12 de junio de 2025, 22:04
 */

#include "Medico.h"
#include <cstring>

Medico::Medico() {
    inicializa();
}
//
//Medico::Medico(const Medico& orig) {
//}

Medico::~Medico() {
    if(nombre != nullptr) delete nombre;
    if(especialidad != nullptr) delete especialidad;
}

void Medico::SetEspecialidad(char* esp) {
    if(especialidad != nullptr) delete especialidad;
    especialidad = new char[strlen(esp) + 1];
    strcpy(especialidad, esp);
}

void Medico::GetEspecialidad(char *buffer) const {
    if(especialidad == nullptr) buffer[0] = 0;
    else strcpy(buffer, especialidad);
}

void Medico::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Medico::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else strcpy(buffer, nombre);
}

void Medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medico::GetCodigo() const {
    return codigo;
}

void Medico::inicializa(){
    especialidad = nullptr;
    nombre = nullptr;
    codigo = 0; //Servira para la impresion
}

void Medico::leerDatos(ifstream &arch){
    
    char nomb[60], espe[30];
    
    arch >> codigo;
    if(arch.eof())return;
    arch.get();
    arch.getline(nomb, 60, ',');
    arch.getline(espe, 30);
    
    SetEspecialidad(espe);
    SetNombre(nomb);
    
}