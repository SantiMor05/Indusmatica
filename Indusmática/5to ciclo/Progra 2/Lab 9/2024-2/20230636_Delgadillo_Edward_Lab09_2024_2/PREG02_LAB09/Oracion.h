/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Oracion.h
 * Author: 00123
 *
 * Created on 23 de junio de 2025, 05:05 PM
 */

#ifndef ORACION_H
#define ORACION_H

#include <fstream>
#include <vector>
#include <string>
using namespace std;
#include "Palabra.h"

class Oracion {
public:
    Oracion();
//    Oracion(const Oracion& orig);
//    virtual ~Oracion();
    void agregar(string aux,int pola);
    void estadistico(int&posi,int&nega,int&neutro);
    bool operator <(Oracion&o);
    void imprimir(ofstream&arch);
    void setCantidad_palabras(int cantidad_palabras);
    int getCantidad_palabras() const;
    void setPolaridad_total(int polaridad_total);
    int getPolaridad_total() const;
private:
    vector<Palabra>palabras;
    int polaridad_total;
    int cantidad_palabras;
};

#endif /* ORACION_H */

