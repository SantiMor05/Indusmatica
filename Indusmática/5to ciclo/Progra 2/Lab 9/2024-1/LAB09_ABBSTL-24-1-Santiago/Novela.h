/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.h
 * Author: santi
 *
 * Created on 25 de junio de 2025, 22:25
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"
#include <fstream>
using namespace std;

class Novela : public Libro{
private:
    string autor;
    
    
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(string &autor);
    string GetAutor() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* NOVELA_H */

