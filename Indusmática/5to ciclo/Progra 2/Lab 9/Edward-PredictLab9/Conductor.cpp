/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: 00123
 * 
 * Created on 26 de junio de 2025, 03:24 PM
 */

#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Automovil.h"
#include "Infraccion.h"
#include "Conductor.h"

//Conductor::Conductor() {
//}
//
//Conductor::Conductor(const Conductor& orig) {
//}
//
//Conductor::~Conductor() {
//}

void Conductor::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Conductor::GetNombre() const {
    return nombre;
}

void Conductor::SetDni(int dni) {
    this->dni = dni;
}

int Conductor::GetDni() const {
    return dni;
}

void Conductor::leer(ifstream& arch) {

    arch>>dni;
    if(arch.eof())return;
    arch.get();
    getline(arch,nombre);
}

void Conductor::imprimir(ofstream& arch) {

    arch<<"DNI: "<<dni<<"  Nombre: "<<nombre<<endl;
    for(auto automovil:automoviles)
        automovil.imprimir(arch);
}

void Conductor::actualizar(ifstream& arch, Infraccion infrac) {

    string placa;
    getline(arch,placa,',');
    for(auto&automovil:automoviles){
        if(placa==automovil.GetPlaca()){
            automovil.actualizar(arch,infrac);
            automoviles.push_back(automovil);
            return;
        }
    }
    Automovil automovil;
    automovil.SetPlaca(placa);
    automovil.actualizar(arch,infrac);
    automoviles.push_back(automovil);
    
}


