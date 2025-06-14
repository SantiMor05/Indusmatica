/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrdenVenta.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 23:58
 */

#include "OrdenVenta.h"
#include "PrioridadAlta.h"
#include "PrioridadBaja.h"
#include "PrioridadMedia.h"

OrdenVenta::OrdenVenta() {
    inicializa();
}

//OrdenVenta::OrdenVenta(const OrdenVenta& orig) {
//}

OrdenVenta::~OrdenVenta() {
    if(ptr_orden != nullptr)
        delete ptr_orden;
}

void OrdenVenta::inicializa(){
    ptr_orden = nullptr;
}
void OrdenVenta::lee(ifstream &arch){
    ptr_orden->lee(arch);
}

void OrdenVenta::asignaPrioridadBaja(){
    ptr_orden = new PrioridadBaja;
}

void OrdenVenta::asignaPrioridadMedia(){
    ptr_orden = new PrioridadMedia;
}

void OrdenVenta::asignaPrioridadAlta(){
    ptr_orden = new PrioridadAlta;
}

void OrdenVenta::imprime(ofstream &arch){
    
    ptr_orden->imprime(arch);
    
}

void OrdenVenta::actualiza(){
    ptr_orden->actualiza();
}
