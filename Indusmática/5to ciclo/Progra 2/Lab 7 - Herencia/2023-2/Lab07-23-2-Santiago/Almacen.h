/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.h
 * Author: santi
 *
 * Created on 10 de junio de 2025, 22:38
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "OrdenVenta.h"

class Almacen {
private:
    OrdenVenta ordenes[600];
    int cantidad_ordenes;


public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void inicializa();
    void cargar_pedidos();
    void imprimir_ordenes_venta();
    void actualizar_orden();

};

#endif /* ALMACEN_H */

