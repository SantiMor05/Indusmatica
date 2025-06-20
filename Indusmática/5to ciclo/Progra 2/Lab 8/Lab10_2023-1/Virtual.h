/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.h
 * Author: kenyi
 *
 * Created on 19 de junio de 2025, 04:02 PM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"


class Virtual:public Alumno {
private:
    char *licencia;
    double total;
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* licencia);
    void GetLicencia(char*) const;
    void leer(ifstream& arch) ;
    void imprime(ofstream& arch);
    void actualiza(double) override;

};

#endif /* VIRTUAL_H */

