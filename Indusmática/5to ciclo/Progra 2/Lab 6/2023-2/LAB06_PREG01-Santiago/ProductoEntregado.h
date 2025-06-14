/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductoEntregado.h
 * Author: santi
 *
 * Created on 5 de junio de 2025, 14:39
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado {
private:
    char *codigo;
    double precio;

public:
    ProductoEntregado();
    ProductoEntregado(const ProductoEntregado& orig);
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(char* cod);
    void GetCodigo(char *buffer) const;
    void inicializa();
    void operator =(const ProductoEntregado &prod);

};

#endif /* PRODUCTOENTREGADO_H */

