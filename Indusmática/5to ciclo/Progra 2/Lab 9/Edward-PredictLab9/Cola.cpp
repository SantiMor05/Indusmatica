/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.cpp
 * Author: 00123
 * 
 * Created on 26 de junio de 2025, 03:55 PM
 */

#include <iostream>
using namespace std;
#include "Nodo.h"
#include "Conductor.h"
#include "Cola.h"

Cola::Cola() {
    cabeza=nullptr;
    cola=nullptr;
}

//Cola::Cola(const Cola& orig) {
//}
//
//Cola::~Cola() {
//}

void Cola::encolar(Conductor condu) {

    Nodo*nuevo=new Nodo;
    nuevo->conductor=condu;
    if(cola){
        cola->siguiente=nuevo;
    }
    else{
        cabeza=nuevo;
    }
    cola=nuevo;
//    cout<<cola->conductor.GetDni()<<endl;
}

Conductor Cola::desencolar() {
    
    Conductor condu;
    
    condu=cabeza->conductor;
    Nodo*aux=cabeza;
    cabeza=cabeza->siguiente;
    delete aux;
    return condu;
}

bool Cola::esVacia() {

    return cabeza==nullptr;
}
