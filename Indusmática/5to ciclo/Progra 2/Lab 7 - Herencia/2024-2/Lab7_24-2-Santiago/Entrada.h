/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrada.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 19:28
 */

#ifndef ENTRADA_H
#define ENTRADA_H

#include "Producto.h"

class Entrada : public Producto {
private:
    bool picante;
        
public:
    Entrada();
//    Entrada(const Entrada& orig);
    virtual ~Entrada();
    void SetPicante(bool picante);
    bool IsPicante() const;
    void leerEntrada(ifstream &arch);
    void imprimirDatos(ofstream &arch)const;
};

void operator << (ofstream &arch, const Entrada &entrada);

#endif /* ENTRADA_H */

