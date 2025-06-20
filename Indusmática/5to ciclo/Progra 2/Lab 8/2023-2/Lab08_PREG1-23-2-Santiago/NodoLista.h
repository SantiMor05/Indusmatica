/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoLista.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 14:29
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Vehiculo.h"
//#include "LVehiculos.h"

class NodoLista {
private:
    Vehiculo *unidad;
    NodoLista *sig;
    
public:
    NodoLista();
    NodoLista(const NodoLista& orig);
    virtual ~NodoLista();
    void inicializa();
    
    friend class LVehiculos;
};

#endif /* NODOLISTA_H */

