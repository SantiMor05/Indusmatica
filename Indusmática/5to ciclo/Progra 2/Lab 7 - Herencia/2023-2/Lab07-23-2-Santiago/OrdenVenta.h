/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrdenVenta.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 23:58
 */

#ifndef ORDENVENTA_H
#define ORDENVENTA_H

#include "Pedido.h"

class OrdenVenta {

private:
    Pedido *ptr_orden;

public:
    OrdenVenta();
//    OrdenVenta(const OrdenVenta& orig);
    virtual ~OrdenVenta();
    void inicializa();
    void lee(ifstream &arch);
    void asignaPrioridadBaja();
    void asignaPrioridadMedia();
    void asignaPrioridadAlta();
    void imprime(ofstream &arch);
    void actualiza();
};

#endif /* ORDENVENTA_H */

