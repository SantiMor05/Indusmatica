/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NLibro.h
 * Author: santi
 *
 * Created on 25 de junio de 2025, 22:28
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include "Libro.h"

#include <fstream>
using namespace std;

class NLibro {
private:
    Libro *plibro;
    
public:
    NLibro();
    NLibro(const NLibro& orig);
//    virtual ~NLibro();
    void asignaTipo(char car);
    void lee(ifstream &arch);
    double getPeso();
    void imprime(ofstream &arch);
    void inicializa();
    void operator =(const NLibro& orig);
};

#endif /* NLIBRO_H */

