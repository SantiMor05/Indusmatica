/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enciclopedia.h
 * Author: santi
 *
 * Created on 25 de junio de 2025, 22:24
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"
#include <fstream>
using namespace std;
class Enciclopedia : public Libro{
private:
    int sku;
    int anho;
    
    
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia& orig);
    virtual ~Enciclopedia();
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* ENCICLOPEDIA_H */

