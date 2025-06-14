/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlatoFondo.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 19:52
 */

#ifndef PLATOFONDO_H
#define PLATOFONDO_H

#include "Producto.h"

#include <fstream>
using namespace std;

class PlatoFondo : public Producto{
private:
    int *proteina;
    
public:
    PlatoFondo();
//    PlatoFondo(const PlatoFondo& orig);
    virtual ~PlatoFondo();
    void leerProteina(ifstream &arch);
    void imprimirDatos(ofstream &arch)const;
};

void operator << (ofstream &arch, const PlatoFondo &plato);

#endif /* PLATOFONDO_H */

