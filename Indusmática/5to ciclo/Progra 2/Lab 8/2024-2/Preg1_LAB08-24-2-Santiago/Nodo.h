/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: santi
 *
 * Created on 18 de junio de 2025, 11:00
 */

#ifndef NODO_H
#define NODO_H

#include "DetalleComanda.h"

class Nodo {

private:
    DetalleComanda dato;
    Nodo *sig;

public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();

    friend class Cola;
};

#endif /* NODO_H */

