/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: 00123
 *
 * Created on 18 de junio de 2025, 07:47 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Medicamento.h"
#include "Arbol.h"

class Nodo {
public:
    Nodo();
    friend class Arbol;
//    Nodo(const Nodo& orig);
    virtual ~Nodo();
private:
    Medicamento*med;
    Nodo*izq;
    Nodo*der;
};

#endif /* NODO_H */

