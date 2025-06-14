/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.h
 * Author: santi
 *
 * Created on 11 de junio de 2025, 23:23
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"
#include <fstream>
using namespace std;

class Semipresencial : public Alumno {
private:
    double descuento;
    double total;

public:
    Semipresencial();
//    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leerDatos(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza(double precio);

};

#endif /* SEMIPRESENCIAL_H */

