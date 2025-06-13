/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesSobrecargadas.h
 * Author: santi
 *
 * Created on 6 de abril de 2025, 14:35
 */

#ifndef FUNCIONESSOBRECARGADAS_H
#define FUNCIONESSOBRECARGADAS_H

#include <fstream>
using namespace std;

//LECTURA
void operator >>(ifstream &arch, struct Plato &plato);
void operator >>(ifstream &arch, struct Repartidor &repartidor);
void operator >>(ifstream &arch, struct Pedido &pedido);


//Operaciones
bool operator <=(struct Pedido &pedido, struct Plato *arregloPlatos);
void operator <=(struct Repartidor *arregloRepartidores, 
        const struct Pedido &pedido);
void operator !(struct OrdenDeCompra &orden);
void operator !(struct Repartidor &repartidor);

//Impresion
void operator << (ofstream &out, const struct Plato &plato);
void operator << (ofstream &out, const struct Repartidor &repartidor);


#endif /* FUNCIONESSOBRECARGADAS_H */

