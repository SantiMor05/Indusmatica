/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.h
 * Author: 00123
 *
 * Created on 18 de junio de 2025, 07:48 PM
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include <fstream>
#include "Arbol.h"
using namespace std;

class Almacen {
public:
//    Almacen();
//    Almacen(const Almacen& orig);
//    virtual ~Almacen();
    void carga(const char*nombArch);
    void imprime(const char*nombArch);
    void actualiza(const char*nombArch);
private:
    Arbol arbolalma;
};

#endif /* ALMACEN_H */

