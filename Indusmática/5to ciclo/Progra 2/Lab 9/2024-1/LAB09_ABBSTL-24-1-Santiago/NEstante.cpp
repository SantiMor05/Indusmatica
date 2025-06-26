/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NEstante.cpp
 * Author: santi
 * 
 * Created on 25 de junio de 2025, 22:29
 */

#include "NEstante.h"

NEstante::NEstante() {
    inicializa();
}
//
//NEstante::NEstante(const NEstante& orig) {
//}

NEstante::~NEstante() {
}

void NEstante::SetDisponible(double disponible) {
    this->disponible = disponible;
}

double NEstante::GetDisponible() const {
    return disponible;
}

void NEstante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double NEstante::GetCapacidad() const {
    return capacidad;
}

void NEstante::SetId(int id) {
    this->id = id;
}

int NEstante::GetId() const {
    return id;
}


void NEstante::inicializa(){
    izq = nullptr;
    der = nullptr;
}
