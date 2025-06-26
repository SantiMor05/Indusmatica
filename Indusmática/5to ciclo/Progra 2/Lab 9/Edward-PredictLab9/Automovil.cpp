/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Automovil.cpp
 * Author: 00123
 * 
 * Created on 26 de junio de 2025, 03:26 PM
 */

#include <string>
#include <vector>
#include <map>
using namespace std;
#include "Infraccion.h"
#include "Falta.h"
#include "Automovil.h"

//Automovil::Automovil() {
//}
//
//Automovil::Automovil(const Automovil& orig) {
//}
//
//Automovil::~Automovil() {
//}

void Automovil::SetPlaca(string placa) {
    this->placa = placa;
}

string Automovil::GetPlaca() const {
    return placa;
}

void Automovil::actualizar(ifstream& arch, Infraccion infrac) {

    Falta falta;
    falta.leer(arch);
    
    faltas[infrac].push_back(falta);
    
}

void Automovil::imprimir(ofstream& arch) {

    arch<<"  Placa: "<<placa<<endl;
    for(auto falta:faltas){
        arch<<"    Infraccion: "<<falta.first.GetCodigo()<<endl;
        for(auto i:falta.second){
            i.imprimir(arch);
        }
    }
}
