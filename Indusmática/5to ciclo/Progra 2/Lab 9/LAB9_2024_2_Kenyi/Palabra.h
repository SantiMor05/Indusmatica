/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.h
 * Author: kenyi
 *
 * Created on 23 de junio de 2025, 07:55 PM
 */

#ifndef PALABRA_H
#define PALABRA_H
#include <string>
using namespace std;
class Palabra {
private:
    string texto;
    int polaridad;
public:
    void SetPolaridad(int polaridad);
    int GetPolaridad() const;
    void SetTexto(string texto);
    string GetTexto() const;
};

#endif /* PALABRA_H */

