/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Presencial.h
 * Author: Usuario
 *
 * Created on 10 de junio de 2025, 15:55
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"

class Presencial : public Alumno {
private:
    double recargo;
    double total;
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void insertarDatoP(int codigo,const char* cad,int escala,double monto);
    void actualiza(double monto);
    void imprimir(ofstream &arch);
};

#endif /* PRESENCIAL_H */

