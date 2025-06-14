/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: santi
 *
 * Created on 11 de junio de 2025, 23:30
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Tesoreria {
private:
    Presencial lpresencial[100];
    Semipresencial lsemipresencial[100];
    Virtual lvirtual[100];
    Escala lescala[5];

public:
    Tesoreria();
//    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    void cargaescalas();
    void cargaalumnos();
    void imprime();
    void actualiza(double creditos);
};

#endif /* TESORERIA_H */

