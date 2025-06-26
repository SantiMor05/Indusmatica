/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: 00123
 *
 * Created on 26 de junio de 2025, 03:24 PM
 */

#ifndef NODO_H
#define NODO_H

using namespace std;
#include "Conductor.h"
#include "Cola.h"

class Nodo {
public:
    Nodo();
//    Nodo(const Nodo& orig);
//    virtual ~Nodo();
    friend class Cola;
private:
    Conductor conductor;
    Nodo*siguiente;
};

#endif /* NODO_H */

