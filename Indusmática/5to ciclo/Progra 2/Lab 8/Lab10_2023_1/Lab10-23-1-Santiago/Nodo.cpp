/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 21:30
 */

#include "Nodo.h"

Nodo::Nodo() {
    inicializa();
}

//Nodo::Nodo(const Nodo& orig) {
//}

Nodo::~Nodo() {
}

void Nodo::inicializa(){
    der = nullptr;
    izq = nullptr;
}