/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Usuario
 *
 * Created on 12 de junio de 2025, 08:17
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    char* nombre;
    double precio;
public:
    Producto();
    virtual ~Producto();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(const char* cad);
    void GetNombre(char* cad) const;

};

#endif /* PRODUCTO_H */

