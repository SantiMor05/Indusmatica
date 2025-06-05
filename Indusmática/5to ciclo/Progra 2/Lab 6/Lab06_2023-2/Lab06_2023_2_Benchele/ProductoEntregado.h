/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ProductoEntregado.h
 * Author: Lenovo
 *
 * Created on 3 de junio de 2025, 08:10 PM
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado {
private:
    char *codigo;
    double precio;
public:
    ProductoEntregado();
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *cod) const;
    
    void operator=(const class ProductoEntregado &pe);

};

#endif /* PRODUCTOENTREGADO_H */

