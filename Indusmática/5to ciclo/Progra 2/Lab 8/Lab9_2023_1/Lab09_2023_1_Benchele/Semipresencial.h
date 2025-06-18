/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Semipresencial.h
 * Author: Lenovo
 *
 * Created on 18 de junio de 2025, 03:04 PM
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"


class Semipresencial: public Alumno {
    
private:
    double descuento;
    double total;
    
public:
    Semipresencial();
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;

    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    
    void actualiza(double);
};

#endif /* SEMIPRESENCIAL_H */

