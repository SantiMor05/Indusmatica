/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Lenovo
 *
 * Created on 3 de junio de 2025, 08:11 PM
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
    int clientes_servidos[100];
    int clientes_no_servidos[100];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(const char* descripcion);
    void GetDescripcion(char *descp) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *cod) const;

    void inicializa();
    void elimina();
    void operator =(const class Producto &orig);
    
    bool operator +=(class Pedido &pedido);
    int *GetClientes_no_servidos();
    int *GetClientes_servidos();
    
    
};

bool operator >>(ifstream &arch, class Producto &producto);
void operator <<(ofstream &arch, class Producto &producto);

#endif /* PRODUCTO_H */

