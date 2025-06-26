/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.h
 * Author: 00123
 *
 * Created on 26 de junio de 2025, 03:24 PM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Automovil.h"
#include "Infraccion.h"


class Conductor {
public:
//    Conductor();
//    Conductor(const Conductor& orig);
//    virtual ~Conductor();
    
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetDni(int dni);
    int GetDni() const;
    
    void leer(ifstream&arch);
    void imprimir(ofstream&arch);
    
    void actualizar(ifstream&arch,Infraccion infrac);
private:
    int dni;
    string nombre;
    vector<Automovil>automoviles;
};

#endif /* CONDUCTOR_H */

