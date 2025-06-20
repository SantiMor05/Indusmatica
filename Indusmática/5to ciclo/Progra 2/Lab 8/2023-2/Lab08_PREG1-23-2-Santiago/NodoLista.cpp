/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoLista.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 14:29
 */

#include "NodoLista.h"

NodoLista::NodoLista() {
    inicializa();
}

//NodoLista::NodoLista(const NodoLista& orig) {
//}

NodoLista::~NodoLista() {
}


void NodoLista::inicializa(){
    sig = nullptr;
    unidad = nullptr;
}
