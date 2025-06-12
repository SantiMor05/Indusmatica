/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Semipresencial.h
 * Author: Usuario
 *
 * Created on 10 de junio de 2025, 15:56
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"


class Semipresencial : public Alumno {
private:
    double descuento;
    double total;
public:
    Semipresencial();
    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void insertarDatoS(int codigo,const char* cad,int escala,double monto);
    void actualiza(double monto);
    void imprimir(ofstream &arch);
};

#endif /* SEMIPRESENCIAL_H */

