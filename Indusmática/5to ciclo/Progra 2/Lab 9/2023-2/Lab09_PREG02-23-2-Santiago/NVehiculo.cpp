/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NVehiculo.cpp
 * Author: santi
 * 
 * Created on 26 de junio de 2025, 18:42
 */

#include "NVehiculo.h"
#include "Furgon.h"
#include "Camion.h"

NVehiculo::NVehiculo() {
    inicializa();
}

//NVehiculo::NVehiculo(const NVehiculo& orig) {
//}

//NVehiculo::~NVehiculo() {
//    if(unidad != nullptr)delete unidad;
//    unidad = nullptr;
//}


void NVehiculo::inicializa(){
    
    unidad = nullptr;
    
}


void NVehiculo::asignaTipo(char car){
    
    if(car == 'F')
        unidad = new Furgon;
    else 
        unidad = new Camion;
    
}

void NVehiculo::lee(ifstream &arch){
    unidad->lee(arch);
}

void NVehiculo::imprime(ofstream &arch){
    unidad->imprime(arch);
}

int NVehiculo::retornaCliente()const{
    unidad->GetCliente();
}

void NVehiculo::cargadeposito(ifstream &arch){
    unidad->cargadeposito(arch);
}

bool NVehiculo::operator <(const NVehiculo &veh){
    
    return retornaCliente() < veh.retornaCliente();
    
}