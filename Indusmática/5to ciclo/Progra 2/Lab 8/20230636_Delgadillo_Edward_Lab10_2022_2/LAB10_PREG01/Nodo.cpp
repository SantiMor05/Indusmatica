/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: 00123
 * 
 * Created on 18 de junio de 2025, 07:47 PM
 */

#include "Nodo.h"

Nodo::Nodo() {
    
    med=nullptr;
    izq=nullptr;
    der=nullptr;
}

//Nodo::Nodo(const Nodo& orig) {
//}
//
Nodo::~Nodo() {
    
    delete med;
}

