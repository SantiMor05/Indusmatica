/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PlatoFondo.h
 * Author: Lenovo
 *
 * Created on 12 de junio de 2025, 05:22 PM
 */

#ifndef PLATOFONDO_H
#define PLATOFONDO_H

#include <fstream>
#include "Producto.h"
using namespace std;

class PlatoFondo: public Producto {
    
private:
    int *proteina;
public:
    PlatoFondo();
    virtual ~PlatoFondo();
    void SetProteina(int* proteina);
    int* GetProteina() const;
    
    //Leer datos
    void leerDatos(ifstream &arch);
    
    //Imprimir
    void imprimir(ofstream &arch);
};

#endif /* PLATOFONDO_H */

