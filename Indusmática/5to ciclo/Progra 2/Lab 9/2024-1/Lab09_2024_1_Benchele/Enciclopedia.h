/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: Lenovo
 *
 * Created on 26 de junio de 2025, 05:21 PM
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"
#include <fstream>
using namespace std;

class Enciclopedia: public Libro {
    
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

