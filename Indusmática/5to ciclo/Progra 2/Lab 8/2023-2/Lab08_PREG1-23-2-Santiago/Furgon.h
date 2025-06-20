/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 14:27
 */

#ifndef FURGON_H
#define FURGON_H

#include <fstream>
using namespace std;
#include "Vehiculo.h"

class Furgon : public Vehiculo{
private:
    int filas;
    int puertas;
    
public:
    Furgon();
//    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* FURGON_H */

