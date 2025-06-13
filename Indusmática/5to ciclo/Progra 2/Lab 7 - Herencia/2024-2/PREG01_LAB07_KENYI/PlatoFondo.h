/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlatoFondo.h
 * Author: kenyi
 *
 * Created on 12 de junio de 2025, 04:19 PM
 */

#ifndef PLATOFONDO_H
#define PLATOFONDO_H

#include "Producto.h"

class PlatoFondo : public Producto {
private:
    int *proteina;
public:
    PlatoFondo();
    virtual ~PlatoFondo();
    void SetProteina( int, int, int, int);
    void GetProteina(int*) const;
    void leerPlat(ifstream &arch);
    void imprimirPlat(ofstream &arch);
};

#endif /* PLATOFONDO_H */

