/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: kenyi
 *
 * Created on 12 de junio de 2025, 04:15 PM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    char *nombre;
    double precio;
public:
    Producto();
    virtual ~Producto();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
};

#endif /* PRODUCTO_H */

