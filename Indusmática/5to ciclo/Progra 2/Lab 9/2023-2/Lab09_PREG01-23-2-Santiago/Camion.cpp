/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.cpp
 * Author: santi
 * 
 * Created on 26 de junio de 2025, 18:36
 */

#include "Camion.h"

Camion::Camion() {
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::lee(ifstream &arch){
    char car;
    Vehiculo::lee(arch);
    arch.get();
    
    arch >> ejes >> car >> llantas;
}


void Camion::imprime(ofstream &arch){
    
    Vehiculo::imprime(arch);
    arch << "#Ejes:          " << ejes << endl;
    arch << "#LLantas:       " << llantas << endl;
    arch << "Listas Pedidos:" << endl;
    for(auto x: mdeposito){
        x.second;
    }
    
}