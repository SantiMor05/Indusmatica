/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaconRegistros.h
 * Author: santi
 *
 * Created on 5 de mayo de 2025, 23:08
 */

#ifndef LISTACONREGISTROS_H
#define LISTACONREGISTROS_H

#include <fstream>
using namespace std;

void* leeregistros(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char deli);
void *leeOrdenes(ifstream &arch);
int compruebaregistros(const void *repartidor, const void *dato);
void imprimeRegistro(const void*dupla, ofstream &arch);
void imprimirOrdenes(void *ordenes, ofstream &arch);

#endif /* LISTACONREGISTROS_H */
