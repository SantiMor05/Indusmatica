/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Virtual.h
 * Author: Lenovo
 *
 * Created on 18 de junio de 2025, 03:05 PM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"
using namespace std;

class Virtual: public Alumno {
    
private:
    char *licencia;
    double total;
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* licencia);
    void GetLicencia(char*) const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    
    void actualiza(double);
};

#endif /* VIRTUAL_H */

