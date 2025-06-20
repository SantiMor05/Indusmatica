/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 18:22
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"

#include <fstream>
using namespace std;

class Presencial : public Alumno{
private:
    double recargo;
    double total;

public:
    Presencial();
//    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualizatotal(double escala);
};

#endif /* PRESENCIAL_H */

