/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.h
 * Author: santi
 *
 * Created on 26 de junio de 2025, 18:36
 */

#ifndef CAMION_H
#define CAMION_H

#include "NPedido.h"
#include "Vehiculo.h"
#include <map>

class Camion : public Vehiculo{
private:
    int ejes;
    int llantas;
    map <int, NPedido> mdeposito;
    
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void cargadeposito(ifstream &arch);
};

#endif /* CAMION_H */

