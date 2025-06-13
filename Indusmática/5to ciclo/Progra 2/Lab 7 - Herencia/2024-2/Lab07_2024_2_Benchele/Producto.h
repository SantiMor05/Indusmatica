/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Lenovo
 *
 * Created on 12 de junio de 2025, 05:20 PM
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
    virtual ~Producto();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    
    void inicaliza();
    void operator =(const class Producto &orig);
    
    //Leer datos compartidos
    void leerDatos(ifstream &arch);

    //Imprimir
    void imprimir(ofstream &arch);
};

#endif /* PRODUCTO_H */

