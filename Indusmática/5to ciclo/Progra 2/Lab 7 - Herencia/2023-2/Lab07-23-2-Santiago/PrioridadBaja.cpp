/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadBaja.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 23:55
 */

#include "PrioridadBaja.h"
#include <iomanip>

PrioridadBaja::PrioridadBaja() {
    nueva_fecha_entrega = 0;
}

PrioridadBaja::PrioridadBaja(const PrioridadBaja& orig) {
}

PrioridadBaja::~PrioridadBaja() {
}

void PrioridadBaja::inicializa(){
    nueva_fecha_entrega = 0;
}

void PrioridadBaja::setNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadBaja::getNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadBaja::setDias_espera(int dias_espera) {
    this->dias_espera = dias_espera;
}

int PrioridadBaja::getDias_espera() const {
    return dias_espera;
}

void PrioridadBaja::lee(ifstream &arch){
    Pedido::lee(arch);
    
    arch.get();
    arch >> dias_espera;
    
}

void PrioridadBaja::imprime(ofstream &arch){
    
    arch << "PRIORIDAD BAJA:" << endl;
    Pedido::imprime(arch);
    
    arch << setw(6) << dias_espera << " dias" << setw(4) << " ";
    imprimirFecha(arch, nueva_fecha_entrega);
    arch << endl;
}

void PrioridadBaja::actualiza(){
    Pedido::actualiza();
    nueva_fecha_entrega = GetFecha() + dias_espera;
}