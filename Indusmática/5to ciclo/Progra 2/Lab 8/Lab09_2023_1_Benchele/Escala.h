/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Escala.h
 * Author: Lenovo
 *
 * Created on 18 de junio de 2025, 03:03 PM
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
    
private:
    int codigo;
    double precio;
public:
    Escala();
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;

    void asigna(int cod, double prec);
};

#endif /* ESCALA_H */

