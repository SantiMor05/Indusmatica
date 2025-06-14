/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bebida.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 19:59
 */

#ifndef BEBIDA_H
#define BEBIDA_H

#include "Producto.h"
#include <fstream>
using namespace std;

class Bebida : public Producto{
    private:
        char *tamano; 
public:
    Bebida();
//    Bebida(const Bebida& orig);
    virtual ~Bebida();
    void SetTamano(char* tamano);
    void GetTamano(char *buffer) const;
    void inicializa();
    void leerBebida(ifstream &arch);
    void imprimirDatos(ofstream &arch);
};

void operator << (ofstream &arch, Bebida &bebida);

#endif /* BEBIDA_H */

