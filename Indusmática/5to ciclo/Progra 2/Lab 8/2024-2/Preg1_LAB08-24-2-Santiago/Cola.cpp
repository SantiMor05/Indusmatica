/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.cpp
 * Author: santi
 * 
 * Created on 18 de junio de 2025, 11:02
 */

#include "Cola.h"
#include <iostream>
using namespace std;

Cola::Cola() {
    inicializa();
}

//Cola::Cola(const Cola& orig) {
//}

Cola::~Cola() {
    if(cabeza == nullptr)delete[] cabeza;
    if(cola == nullptr)delete []cola;
}

void Cola::SetLongitud(int longitud) {
    this->longitud = longitud;
}

int Cola::GetLongitud() const {
    return longitud;
}

void Cola::inicializa(){
    cabeza = nullptr;
    cola = nullptr;
    longitud  = 0;
}

void Cola::encola(DetalleComanda &comanda){
    
    Nodo *nuevoNodo = new Nodo;
    
    nuevoNodo->dato = comanda;
    nuevoNodo->sig = nullptr;
    if(cabeza == nullptr){
        cabeza = nuevoNodo;
    }
    else
        cola->sig = nuevoNodo;
    
    cola = nuevoNodo;
    longitud++;
    
}

void Cola::desencola(DetalleComanda &comanda){
    
    Nodo *nodo = cabeza;
    if(longitud == 0)
        cout << "No hay elementos en la cola" << endl;
    else{
        cabeza = cabeza->sig;
        comanda = nodo->dato;
        nodo->dato = new DetalleComanda;
        delete nodo;
        longitud--;
    }
}


void Cola::elimina(int tipo_prote){
    
    int n = longitud;
    DetalleComanda comanda;
    for(int i = 0; i < n; i++){
       // comanda = desencola();
        //if(comanda.)
    }
    
}