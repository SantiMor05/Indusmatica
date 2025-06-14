/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.h
 * Author: santi
 *
 * Created on 11 de junio de 2025, 23:25
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include <fstream>
using namespace std;

#include "Alumno.h"

class Virtual : public Alumno{

private:
    char *licencia;
    double total;

public:
    Virtual();
//    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char* licencia);
    void GetLicencia(char *buffer) const;
    void inicializa();
    void leerDatos(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza(double precio);
};

#endif /* VIRTUAL_H */

