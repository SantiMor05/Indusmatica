/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesSobrecargadas.h
 * Author: santi
 *
 * Created on 9 de abril de 2025, 23:28
 */

#ifndef FUNCIONESSOBRECARGADAS_H
#define FUNCIONESSOBRECARGADAS_H

#include <fstream>
#include "Estructuras.h"
using namespace std;

bool operator  >> (ifstream &arch, struct Cliente &cliente);
bool operator >> (ifstream &arch, struct Producto &producto);
bool operator >> (ifstream &arch, struct Pedido &pedido);
void operator += (struct Cliente *clientes, const struct Pedido &pedido);
bool operator += (struct Producto *productos, struct Pedido &pedido);
void operator << (ofstream &arch, const struct Cliente &cliente);
void operator << (ofstream &arch, const struct Producto &producto);

#endif /* FUNCIONESSOBRECARGADAS_H */

