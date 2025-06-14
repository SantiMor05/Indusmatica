/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadAlta.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 23:49
 */

#include "PrioridadAlta.h"
#include <iomanip>

PrioridadAlta::PrioridadAlta() {
    recargo = 0;
}

//PrioridadAlta::PrioridadAlta(const PrioridadAlta& orig) {
//}

PrioridadAlta::~PrioridadAlta() {
}

void PrioridadAlta::SetTotal(double total) {
    this->total = total;
}

double PrioridadAlta::GetTotal() const {
    return total;
}

void PrioridadAlta::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double PrioridadAlta::GetRecargo() const {
    return recargo;
}

void PrioridadAlta::lee(ifstream &arch){
    
    Pedido::lee(arch);
    arch.get();
    arch >> recargo;
    
    total = Pedido::GetSubtotal() * (recargo) / 100;
    
}

void PrioridadAlta::imprime(ofstream &arch){
    
    arch << "PRIORIDAD ALTA:" << endl;
    Pedido::imprime(arch);
    
    arch << setw(8) << recargo << "%" << setw(8) << total << endl;
    
}

void PrioridadAlta::actualiza(){
    Pedido::SetTotal(Pedido::GetTotal() + total);
}