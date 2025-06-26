/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.h
 * Author: 00123
 *
 * Created on 26 de junio de 2025, 03:55 PM
 */

#ifndef COLA_H
#define COLA_H

using namespace std;
#include "Nodo.h"
#include "Conductor.h"

class Cola {
public:
    Cola();
//    Cola(const Cola& orig);
//    virtual ~Cola();
    void encolar(Conductor condu);
    Conductor desencolar();
    bool esVacia();
private:
    class Nodo*cabeza;
    class Nodo*cola;
};

#endif /* COLA_H */

