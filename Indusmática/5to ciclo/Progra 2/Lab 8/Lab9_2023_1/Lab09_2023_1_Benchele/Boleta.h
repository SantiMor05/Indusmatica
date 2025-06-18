/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Boleta.h
 * Author: Lenovo
 *
 * Created on 18 de junio de 2025, 03:06 PM
 */

#ifndef BOLETA_H
#define BOLETA_H

#include <fstream>
#include "Alumno.h"
using namespace std;

class Boleta {
    
private:
    class Alumno *pBoleta;
public:
    Boleta();
    virtual ~Boleta();
    
    void asignaPresencial();
    void asignaSemipresencial();
    void asignaVirtual();
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    
    bool ultimo();
    int GetEscala();
    void actualiza(double);
};

#endif /* BOLETA_H */

