/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.h
 * Author: kenyi
 *
 * Created on 19 de junio de 2025, 04:05 PM
 */

#ifndef BOLETA_H
#define BOLETA_H
#include <fstream>
using namespace std;
#include "Alumno.h"

class Boleta {
private:
    Alumno *pboleta;
public:
    Boleta();
    virtual ~Boleta();
    void leer(char tipo, ifstream &arch);
    bool operator>(const class Boleta &dato)const;
    int getCodigo()const ;
    int getEscala();
    void imprime(ofstream &arch) const;
    void inicializa();
    void actualiza(double prec);
    
};

void operator<<(ofstream&arch,const class Boleta &boleta);

#endif /* BOLETA_H */

