/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Escala.h
 * Author: Usuario
 *
 * Created on 10 de junio de 2025, 15:54
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
    Escala(const Escala& orig);
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

void operator >>(ifstream &arch, Escala &escala);
double Busca_escala(Escala *escalas,int escalin);

#endif /* ESCALA_H */

