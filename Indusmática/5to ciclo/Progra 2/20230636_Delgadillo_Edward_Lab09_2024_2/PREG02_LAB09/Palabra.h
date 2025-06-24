/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.h
 * Author: 00123
 *
 * Created on 23 de junio de 2025, 05:05 PM
 */

#ifndef PALABRA_H
#define PALABRA_H

#include <string>
using namespace std;

class Palabra {
public:
//    Palabra();
//    Palabra(const Palabra& orig);
//    virtual ~Palabra();
    
    void SetPolaridad(int polaridad);
    int GetPolaridad() const;
    void SetTexto(string texto);
    string GetTexto() const;
private:
    string texto;
    int polaridad;
};

#endif /* PALABRA_H */

