/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.h
 * Author: esteban
 *
 * Created on 7 de mayo de 2025, 20:53
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

#include <fstream>


void * leenumeros(ifstream &archLeer);
void* leeregnumeros(ifstream &archLee);
int compruebanumero(const void* datoLista,const void* datoReg);

void imprimenumeros(void* reg,ofstream& archReport);
#endif /* LISTACONENTEROS_H */
