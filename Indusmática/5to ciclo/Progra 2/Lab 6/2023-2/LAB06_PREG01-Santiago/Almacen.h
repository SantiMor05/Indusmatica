/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.h
 * Author: santi
 *
 * Created on 5 de junio de 2025, 15:08
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "Cliente.h"
#include "Producto.h"

class Almacen {
private:
    Cliente arreglo_clientes[200];
    int cantidad_clientes;
    Producto arreglo_productos[200];
    int cantidad_productos;
    
public:
    Almacen();
    //Almacen(const Almacen& orig);
    virtual ~Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    void inicializa();

};

#endif /* ALMACEN_H */

