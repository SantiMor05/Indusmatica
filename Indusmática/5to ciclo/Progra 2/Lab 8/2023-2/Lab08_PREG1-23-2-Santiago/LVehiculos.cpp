/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LVehiculos.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 14:32
 */

#include "LVehiculos.h"
#include "Furgon.h"
#include "Camion.h"

LVehiculos::LVehiculos() {
    inicializa();
}

LVehiculos::LVehiculos(const LVehiculos& orig) {
}

LVehiculos::~LVehiculos() {
}

void LVehiculos::inicializa(){
    lfin = nullptr;
    lini = nullptr;
}

void LVehiculos::cargaFlota(ifstream &arch){
    
    char tipo;
    while(true){
        arch >> tipo;
        if(arch.eof())break;
        arch.get();
        inserta(arch,tipo);
    }
    
}

void LVehiculos::inserta(ifstream &arch,char tipo){
    
    NodoLista *nuevoNodo = new NodoLista;
    
    if(tipo == 'F')
        nuevoNodo->unidad = new Furgon;
    else
        nuevoNodo->unidad = new Camion;
    
    nuevoNodo->unidad->lee(arch);
    
    if(lini == nullptr){
        lini = nuevoNodo;
    }
    else
        lfin->sig = nuevoNodo;
    
    lfin = nuevoNodo;
    
}


void LVehiculos::imprime(ofstream &arch){
    
    NodoLista *ptr = lini;
    
    while(ptr != nullptr){
        ptr->unidad->imprime(arch);
        ptr = ptr->sig;
        arch << endl << endl;
    }
    
}


bool LVehiculos::buscaActaulizaCliente(ifstream &arch, int cli){
    
    
    NodoLista *ptr =lini;
    bool encontrado = false;
    while(ptr != nullptr){
        
        if(ptr->unidad->GetCliente() == cli){
            encontrado = true;
            ptr->unidad->leePedido(arch);
        }
        
        ptr = ptr->sig;
    }
    
    return encontrado;
}