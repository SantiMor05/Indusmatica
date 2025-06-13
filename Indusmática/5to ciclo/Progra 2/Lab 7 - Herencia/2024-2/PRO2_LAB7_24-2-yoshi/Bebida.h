/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Bebida.h
 * Author: Usuario
 *
 * Created on 12 de junio de 2025, 08:17
 */

#ifndef BEBIDA_H
#define BEBIDA_H
#include <fstream>
using namespace std;
#include "Producto.h"

class Bebida : public Producto{
private:
    char* tamano;
public:
    Bebida();
    virtual ~Bebida();
    void SetTamano(const char* tamano);
    void GetTamano(char* cad) const;
    void llenarDatos(char *cad, double precio, char* tam);
    void imprimir(ofstream &arch);
};

#endif /* BEBIDA_H */

