/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Entrada.h
 * Author: Usuario
 *
 * Created on 12 de junio de 2025, 08:18
 */

#ifndef ENTRADA_H
#define ENTRADA_H

#include <fstream>
using namespace std;
#include "Producto.h"

class Entrada : public Producto {
private:
    bool picante;
public:
    Entrada();
    virtual ~Entrada();
    void SetPicante(bool picante);
    bool IsPicante() const;
    void llenarDatos(char *nombre, double precio, char *picante);
    void imprimir(ofstream &arch);
};

#endif /* ENTRADA_H */

