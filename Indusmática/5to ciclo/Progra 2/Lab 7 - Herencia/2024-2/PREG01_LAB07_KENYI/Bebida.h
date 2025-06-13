/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bebida.h
 * Author: kenyi
 *
 * Created on 12 de junio de 2025, 04:16 PM
 */

#ifndef BEBIDA_H
#define BEBIDA_H
#include "Producto.h"

class Bebida : public Producto {
private:
    char *tamano;
public:
    Bebida();
    virtual ~Bebida();
    void SetTamano(const char* tamano);
    void GetTamano(char*) const;
    void leerBeb(ifstream &arch);
    void imprimirBeb(ofstream &arch);
};

#endif /* BEBIDA_H */

