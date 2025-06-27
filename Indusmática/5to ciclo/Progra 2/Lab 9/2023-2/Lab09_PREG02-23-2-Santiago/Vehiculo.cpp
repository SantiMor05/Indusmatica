/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: santi
 * 
 * Created on 26 de junio de 2025, 18:34
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(string placa) {
    this->placa = placa;
}

string Vehiculo::GetPlaca() const {
    return placa;
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream &arch){
    char car;
    arch >> cliente;
    if(arch.eof())return;
    arch.get();
    getline(arch, placa,',');
    arch >> maxcarga;
    actcarga = 0;
    
}

void Vehiculo::imprime(ofstream &arch){
    
    arch << "Codigo Cliente: " << cliente << endl;
    arch << "Placa:          " << placa << endl;
    arch << "Carga Maxima:   " << maxcarga << endl;
    arch << "Carga Actual:   " << actcarga << endl;
    
}
