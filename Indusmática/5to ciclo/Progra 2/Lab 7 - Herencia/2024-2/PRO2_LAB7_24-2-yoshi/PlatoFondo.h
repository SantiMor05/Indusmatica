/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PlatoFondo.h
 * Author: Usuario
 *
 * Created on 12 de junio de 2025, 08:18
 */

#ifndef PLATOFONDO_H
#define PLATOFONDO_H

#include <fstream>
using namespace std;
#include "Producto.h"

class PlatoFondo : public Producto{
private:
    int* proteina;
public:
    PlatoFondo();
    virtual ~PlatoFondo();
    void SetProteina(int,int,int,int);
    void GetProteina(int* arr) const;
    void llenarDatos(char *nombre, double precio, int pro0, int pro1, int pro2, int pro3);
    void imprimir(ofstream &arch);
};

#endif /* PLATOFONDO_H */

