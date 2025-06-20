/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 21:30
 */

#ifndef NODO_H
#define NODO_H

#include "Boleta.h"

class Nodo {
private:
    Boleta dboleta;
    Nodo *izq;
    Nodo *der;
  
    
public:
    Nodo();
//    Nodo(const Nodo& orig);
    virtual ~Nodo();
    void inicializa();
    
    friend class Arbol;
};

#endif /* NODO_H */

