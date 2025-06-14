/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: santi
 *
 * Created on 5 de junio de 2025, 14:52
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <fstream>
#include "Pedido.h"
using namespace std;

class Producto {
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[50];
    int clientes_no_servidos[50];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
    
public:
    Producto();
   // Producto(const Producto& orig);
    virtual ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(char* descripcion);
    void GetDescripcion(char *buffer) const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *buffer) const;
    void inicializa();
    bool operator +=(Pedido &pedido);

};

bool operator >> (ifstream &arch, Producto &producto);

#endif /* PRODUCTO_H */

