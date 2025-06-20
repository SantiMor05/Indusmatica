/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 14:34
 */

#ifndef FLOTA_H
#define FLOTA_H

#include "LVehiculos.h"

class Flota {
private:
    LVehiculos lista;    
    
public:
    Flota();
//    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota();
    void muestracarga();
    void cargaPedidos();
    
};

#endif /* FLOTA_H */

