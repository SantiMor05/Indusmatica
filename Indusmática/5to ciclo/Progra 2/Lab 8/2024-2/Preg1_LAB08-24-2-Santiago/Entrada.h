/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrada.h
 * Author: santi
 *
 * Created on 18 de junio de 2025, 10:56
 */

#ifndef ENTRADA_H
#define ENTRADA_H

#include "Producto.h"
#include <fstream>
using namespace std;

class Entrada : public Producto{

private:
    bool picante;
    
public:
    Entrada();
    Entrada(const Entrada& orig);
    virtual ~Entrada();
    void SetPicante(bool picante);
    bool IsPicante() const;
    void operator =(const Entrada& orig);
    void leerDatos(ifstream &arch);
    void imprimirDatos(ofstream &arch);
};

#endif /* ENTRADA_H */

