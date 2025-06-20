/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 18:24
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"
#include <fstream>
using namespace std;

class Virtual : public Alumno{
private:
    char *licencia;
    double total;
    
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char* licencia);
    void GetLicencia(char *buffer) const;
    void inicializa();
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualizatotal(double escala);
};

#endif /* VIRTUAL_H */

