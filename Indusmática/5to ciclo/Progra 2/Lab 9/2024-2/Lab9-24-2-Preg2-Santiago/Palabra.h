/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.h
 * Author: santi
 *
 * Created on 24 de junio de 2025, 22:36
 */

#ifndef PALABRA_H
#define PALABRA_H

#include <string>
#include <fstream>
using namespace std;

class Palabra {
private:
    string texto;
    int polaridad;
    
public:
    Palabra();
    Palabra(const Palabra& orig);
    virtual ~Palabra();
    void SetPolaridad(int polaridad);
    int GetPolaridad() const;
    void SetTexto(string texto);
    string GetTexto() const;
    void operator =(const Palabra& orig);
    void imprimir(ofstream &arch);

};

#endif /* PALABRA_H */

