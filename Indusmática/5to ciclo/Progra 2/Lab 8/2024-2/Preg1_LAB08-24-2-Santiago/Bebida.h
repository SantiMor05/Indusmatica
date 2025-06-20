/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bebida.h
 * Author: santi
 *
 * Created on 18 de junio de 2025, 10:51
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
    Bebida(const Bebida& orig);
    virtual ~Bebida();
    void SetTamano(char* tamano);
    void GetTamano(char *buffer) const;
    void inicializa();
    void operator =(const Bebida& orig);
    void leerDatos(ifstream &arch);
    void imprimirDatos(ofstream &arch);
};

#endif /* BEBIDA_H */

