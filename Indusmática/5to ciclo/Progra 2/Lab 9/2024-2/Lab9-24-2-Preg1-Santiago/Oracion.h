/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Oracion.h
 * Author: santi
 *
 * Created on 24 de junio de 2025, 22:37
 */

#ifndef ORACION_H
#define ORACION_H

#include "Palabra.h"
#include <vector>
#include <map>

class Oracion {
private:
    vector <Palabra>palabras;
    int polaridad_total;
    int cantidad_palabras;
    
public:
    Oracion();
//    Oracion(const Oracion& orig);
    virtual ~Oracion();
    void SetCantidad_palabras(int cantidad_palabras);
    int GetCantidad_palabras() const;
    void SetPolaridad_total(int polaridad_total);
    int GetPolaridad_total() const;
    void inicializa();
    void operator =(const Oracion& orig);
    void imprimir();
    void dividirPalabras(string &comentario, map <string, int> &lexicon);
};

#endif /* ORACION_H */

