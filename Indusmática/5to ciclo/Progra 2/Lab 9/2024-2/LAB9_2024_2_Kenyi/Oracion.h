/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Oracion.h
 * Author: kenyi
 *
 * Created on 23 de junio de 2025, 07:58 PM
 */

#ifndef ORACION_H
#define ORACION_H

#include "Palabra.h"
#include <vector>
#include <fstream>
using namespace std;
class Oracion {
private:
    vector<Palabra> palabras;
    int polaridad_total;
    int cantidad_palabras;
public:
    Oracion();
    void SetCantidad_palabras(int cantidad_palabras);
    int GetCantidad_palabras() const;
    void SetPolaridad_total(int polaridad_total);
    int GetPolaridad_total() const;
    void agregar(Palabra palabra);
    void imprimir(ofstream &arch);
    
    int operator<(const Oracion &oracion) const;
};

#endif /* ORACION_H */

