/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 19:23
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
    //Producto(const Producto& orig);
    virtual ~Producto();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(char* nombre);
    void GetNombre(char *buffer) const;
    void inicializa();
    void leerProducto(ifstream &arch);
    void imprimirProducto(ofstream &arch)const;
};

#endif /* PRODUCTO_H */

