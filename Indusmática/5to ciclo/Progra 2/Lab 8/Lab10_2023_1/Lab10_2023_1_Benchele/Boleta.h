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
    
    void inicializa(); 
    void asignaMemoria(char tipo);

    
    void lee(ifstream &arch);
    void actualiza(double);
    void imprime(ofstream &arch) const;
    
    int GetEscala() const;
    int GetCodigo() const;
    
    bool operator >(const class Boleta &dato) const;
};

void operator >>(ifstream &arch, class Boleta &boleta);
void operator <<(ofstream &arch, const class Boleta &boleta);
 
#endif /* BOLETA_H */

