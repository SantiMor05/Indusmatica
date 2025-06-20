/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 14:26
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"
#include <fstream>
using namespace std;

class Camion : public Vehiculo{
private:
    int ejes;
    int llantas;
    
    
public:
    Camion();
//    Camion(const Camion& orig);
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* CAMION_H */

