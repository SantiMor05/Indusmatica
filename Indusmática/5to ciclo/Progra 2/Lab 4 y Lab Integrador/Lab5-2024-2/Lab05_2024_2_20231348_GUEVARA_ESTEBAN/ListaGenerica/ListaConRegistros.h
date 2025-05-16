/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistros.h
 * Author: esteban
 *
 * Created on 7 de mayo de 2025, 23:46
 */

#ifndef LISTACONREGISTROS_H
#define LISTACONREGISTROS_H

#include <fstream>
using namespace std;

void* leeregistros(ifstream &archLee);
char* lecturaExacta(ifstream &archLee,char delim='\n');
void * leeordenes(ifstream &archLee);
int compruebaregistro(const void* datoNodo,const void*datoRegistro);
void imprimeregistros(void*,ofstream &archReport);
void impremePedidos(void** arreglo,ofstream &archReport);

#endif /* LISTACONREGISTROS_H */
