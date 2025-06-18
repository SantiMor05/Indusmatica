/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Presencial.h
 * Author: Lenovo
 *
 * Created on 18 de junio de 2025, 03:04 PM
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"


class Presencial: public Alumno{
    
private:
    double recargo;
    double total;
public:
    Presencial();
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    
    void actualiza(double);

};

#endif /* PRESENCIAL_H */

