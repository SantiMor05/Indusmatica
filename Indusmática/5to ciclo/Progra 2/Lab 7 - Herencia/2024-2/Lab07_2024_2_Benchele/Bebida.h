/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Bebida.h
 * Author: Lenovo
 *
 * Created on 12 de junio de 2025, 05:20 PM
 */

#ifndef BEBIDA_H
#define BEBIDA_H

#include <fstream>
#include "Producto.h"
using namespace std;

class Bebida: public Producto {
    
private:
    char *tamano;
public:
    Bebida();
    virtual ~Bebida();
    void SetTamano(const char* tamano);
    void GetTamano(char*) const;
    
    //Leer datos
    void leerDatos(ifstream &arch);
    
    //Imprimir
    void imprimir(ofstream &arch);
};

#endif /* BEBIDA_H */

