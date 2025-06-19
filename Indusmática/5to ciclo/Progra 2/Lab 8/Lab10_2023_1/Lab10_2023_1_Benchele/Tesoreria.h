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
#include "Arbol.h"
using namespace std;


class Tesoreria {

private:
    class Arbol aBoleta;
public:
    void cargaAlumnos(const char*nombArch);
    void actualiza(const char*nombArch);
    void imprimirBoleta(const char*nombArch);

};

#endif /* TESORERIA_H */

