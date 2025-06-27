/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.h
 * Author: santi
 *
 * Created on 26 de junio de 2025, 18:38
 */

#ifndef FURGON_H
#define FURGON_H

#include "NPedido.h"
#include "Vehiculo.h"
#include <list>

class Furgon : public Vehiculo{
private:
    int filas;
    int puertas;
    list <NPedido> pdeposito;
    
    
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void cargadeposito(ifstream &arch);
};

#endif /* FURGON_H */

