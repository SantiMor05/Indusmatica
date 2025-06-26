/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.h
 * Author: santi
 *
 * Created on 25 de junio de 2025, 22:26
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"
#include <fstream>
using namespace std;
class Revista : public Libro{
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

