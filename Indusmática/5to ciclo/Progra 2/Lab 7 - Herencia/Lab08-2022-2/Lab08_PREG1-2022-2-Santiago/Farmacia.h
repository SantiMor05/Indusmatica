/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Farmacia.h
 * Author: santi
 *
 * Created on 12 de junio de 2025, 22:24
 */

#ifndef FARMACIA_H
#define FARMACIA_H

#include "Medico.h"
#include "Conreceta.h"
#include "Sinreceta.h"


class Farmacia {
private:
    Medico lmedicos[50];
    Sinreceta lsinreceta[1000];
    Conreceta lconreceta[1000];
    
    void imprimirLinea(ofstream &arch, char car, int n);

public:
    Farmacia();
//    Farmacia(const Farmacia& orig);
    virtual ~Farmacia();
    void cargamedico();
    void leerecetas();
    int buscarMed(int medico);
    void imprimirrecetas();

};

#endif /* FARMACIA_H */

