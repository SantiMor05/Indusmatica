/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.h
 * Author: 00123
 *
 * Created on 26 de junio de 2025, 03:24 PM
 */

#ifndef FALTA_H
#define FALTA_H

#include <fstream>
#include <string>
using namespace std;

class Falta {
public:
//    Falta();
//    Falta(const Falta& orig);
//    virtual ~Falta();
    
    void SetDronPolicia(string dronPolicia);
    string GetDronPolicia() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void leer(ifstream&arch);
    void imprimir(ofstream&arch);
private:
    int fecha;
    string dronPolicia;
};

#endif /* FALTA_H */

