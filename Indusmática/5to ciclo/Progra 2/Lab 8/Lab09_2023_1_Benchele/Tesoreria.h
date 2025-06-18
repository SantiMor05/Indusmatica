/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tesoreria.h
 * Author: Lenovo
 *
 * Created on 18 de junio de 2025, 03:06 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Boleta.h"
#include "Escala.h"
using namespace std;

class Tesoreria {

private:
    class Boleta lBoleta[100];
    class Escala lEscala[10];
public:
    Tesoreria();
    virtual ~Tesoreria();

    void cargaEscalas(const char*nombArch);
    void cargaAlumnos(const char*nombArch);
    void actualiza(double );
    void imprimirBoleta(const char*nombArch);
    void imprimirLinea(ofstream &arch, char linea);

};

#endif /* TESORERIA_H */

