/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 10 de abril de 2025, 13:10
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include "Estructuras.h"
#include <fstream>
using namespace std;

void leerCliente(struct Cliente *clientes);
void leerProductoas(struct Producto *productos);
void leerPedidos(struct Cliente *clientes, struct Producto *productos);
void imprimirReporte(struct Cliente *clientes, struct Producto *productos);
void imprimirCaracter(char car, int n, ofstream &arch);



#endif /* FUNCIONESAUXILIARES_H */

