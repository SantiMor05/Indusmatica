/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.h
 * Author: kenyi
 *
 * Created on 19 de junio de 2025, 04:01 PM
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"


class Semipresencial:public Alumno {
private:
    double descuento;
    double total;
public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leer(ifstream& arch) ;
     void imprime(ofstream& arch);
    void actualiza(double) ;


};

#endif /* SEMIPRESENCIAL_H */

