/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: santi
 *
 * Created on 18 de junio de 2025, 10:47
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <fstream>
using namespace std;

class Producto {
private:
    char *nombre;
    double precio;

public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(char* nombre);
    void GetNombre(char *buffer) const;
    void inicializa();
    virtual void operator =(const Producto& orig);
    virtual void leerDatos(ifstream &arch);
    virtual void imprimirDatos(ofstream &arch);
};

#endif /* PRODUCTO_H */

