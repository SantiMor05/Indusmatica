/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrada.h
 * Author: kenyi
 *
 * Created on 12 de junio de 2025, 04:18 PM
 */

#ifndef ENTRADA_H
#define ENTRADA_H
#include "Producto.h"

class Entrada: public Producto {
private:
    bool picante;
public:
    Entrada();
    void SetPicante(bool picante);
    bool IsPicante() const;
    void leerEnt(ifstream &arch);
    void imprimirEnt(ofstream &arch);
};

#endif /* ENTRADA_H */

