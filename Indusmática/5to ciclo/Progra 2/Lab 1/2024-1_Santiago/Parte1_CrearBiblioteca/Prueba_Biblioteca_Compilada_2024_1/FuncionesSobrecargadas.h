/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesSobrecargadas.h
 * Author: santi
 *
 * Created on 9 de abril de 2025, 19:23
 */

#ifndef FUNCIONESSOBRECARGADAS_H
#define FUNCIONESSOBRECARGADAS_H

#include <fstream>
#include "Estructuras.h"
using namespace std;

bool operator >> (ifstream &arch, struct Libro &libro);
bool operator >> (ifstream &arch, struct Cliente &cliente);
bool operator >> (struct LibroSolicitado &libroPedido, struct Libro *libros);
bool operator << (struct Cliente &cliente, const struct LibroSolicitado &pedido);
void operator ++ (struct Cliente &cliente);
void operator << (ofstream &arch, const struct Libro &libro);
void operator << (ofstream &arch, const struct Cliente &cliente);


#endif /* FUNCIONESSOBRECARGADAS_H */

