/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinisterioTransportes.h
 * Author: 00123
 *
 * Created on 26 de junio de 2025, 03:24 PM
 */

#ifndef MINISTERIOTRANSPORTES_H
#define MINISTERIOTRANSPORTES_H

#include <vector>
#include <fstream>
using namespace std;
#include "Conductor.h"
#include "Infraccion.h"
#include "Cola.h"

class MinisterioTransportes {
public:
//    MinisterioTransportes();
//    MinisterioTransportes(const MinisterioTransportes& orig);
//    virtual ~MinisterioTransportes();
    void cargarConductores();
//    void cargarUnidades();
    void cargarInfracciones();
    void destinarFaltas();
    void impirmir();
    Conductor buscarCondu(int dni);
    Infraccion buscarInfrac(int codigo);
private:
    Cola colaConductores;
    vector<Infraccion>infracciones;
};

#endif /* MINISTERIOTRANSPORTES_H */

