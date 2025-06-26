/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: santi
 *
 * Created on 25 de junio de 2025, 22:35
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Arbol.h"

class Biblioteca {
private:
    Arbol AEstante;
public:
    Biblioteca();
//    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga();
    void muestra();
    void prueba(double num);

};

#endif /* BIBLIOTECA_H */

