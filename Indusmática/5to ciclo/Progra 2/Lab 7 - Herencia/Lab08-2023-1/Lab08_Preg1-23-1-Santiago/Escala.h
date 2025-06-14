/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.h
 * Author: santi
 *
 * Created on 11 de junio de 2025, 23:20
 */

#ifndef ESCALA_H
#define ESCALA_H

#include <fstream>
using namespace std;

class Escala {

private:
    int codigo;
    double precio;

public:
    Escala();
    //Escala(const Escala& orig);
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leerDatos(ifstream &arch);

};

#endif /* ESCALA_H */

