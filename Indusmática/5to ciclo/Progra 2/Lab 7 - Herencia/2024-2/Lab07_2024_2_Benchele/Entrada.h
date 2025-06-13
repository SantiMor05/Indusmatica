/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Entrada.h
 * Author: Lenovo
 *
 * Created on 12 de junio de 2025, 05:21 PM
 */

#ifndef ENTRADA_H
#define ENTRADA_H

#include <fstream>
#include "Producto.h"
using namespace std;

class Entrada: public Producto {

private:
    bool picante;
public:
    Entrada();
    virtual ~Entrada();
    void SetPicante(bool picante);
    bool IsPicante() const;
    
    //Leer datos
    void leerDatos(ifstream &arch);
    
    //Imprimir
    void imprimir(ofstream &arch);
};

#endif /* ENTRADA_H */

