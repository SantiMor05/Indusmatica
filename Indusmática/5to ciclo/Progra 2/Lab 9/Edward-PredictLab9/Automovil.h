/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Automovil.h
 * Author: 00123
 *
 * Created on 26 de junio de 2025, 03:26 PM
 */

#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include <string>
#include <vector>
#include <map>
using namespace std;
#include "Infraccion.h"
#include "Falta.h"

class Automovil {
public:
//    Automovil();
//    Automovil(const Automovil& orig);
//    virtual ~Automovil();
    
    void SetPlaca(string placa);
    string GetPlaca() const;
    void actualizar(ifstream&arch,Infraccion infrac);
    void imprimir(ofstream&arch);
private:
    string placa;
    map<Infraccion,vector<Falta>>faltas;
};

#endif /* AUTOMOVIL_H */

