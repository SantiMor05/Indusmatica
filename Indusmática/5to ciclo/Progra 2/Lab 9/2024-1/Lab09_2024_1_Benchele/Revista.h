/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Revista.h
 * Author: Lenovo
 *
 * Created on 26 de junio de 2025, 05:22 PM
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"
#include <fstream>
using namespace std;


class Revista: public Libro {
    
private:
    int ISSN;
    int anho;
    int numero;
public:
    Revista();
    Revista(const Revista& orig);
    virtual ~Revista();
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;

    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* REVISTA_H */

