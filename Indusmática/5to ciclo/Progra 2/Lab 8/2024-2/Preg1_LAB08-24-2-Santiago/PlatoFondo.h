/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlatoFondo.h
 * Author: santi
 *
 * Created on 18 de junio de 2025, 10:57
 */

#ifndef PLATOFONDO_H
#define PLATOFONDO_H

#include "Producto.h"
#include <fstream>
using namespace std;

class PlatoFondo : public Producto{
private:
    int proteina;

public:
    PlatoFondo();
    PlatoFondo(const PlatoFondo& orig);
    virtual ~PlatoFondo();
    void SetProteina(int proteina);
    int GetProteina() const;
    void operator =(const PlatoFondo& orig);
    void leerDatos(ifstream &arch);
    void imprimirDatos(ofstream &arch);
};

#endif /* PLATOFONDO_H */

