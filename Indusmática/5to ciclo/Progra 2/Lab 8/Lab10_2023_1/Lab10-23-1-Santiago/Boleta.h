/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 21:29
 */

#ifndef BOLETA_H
#define BOLETA_H

#include "Alumno.h"
#include <fstream>
using namespace std;


class Boleta {
private:
    Alumno *pboleta;
    
public:
    Boleta();
    Boleta(const Boleta& orig);
    virtual ~Boleta();
    void asignaMemoria(char tipo);
    void lee(ifstream &arch);
    void inicializa();
    bool operator <(const Boleta &boleta);
    void imprime(ofstream &arch);
    int obtenEscala();
    void actualizatotal(double escala);
};

#endif /* BOLETA_H */

