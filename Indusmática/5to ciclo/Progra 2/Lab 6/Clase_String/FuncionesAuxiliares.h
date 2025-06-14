/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 1 de junio de 2025, 12:39
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
using namespace std;

void leerDatos(Cadena *&ptr);
void incrementarEspacios(Cadena *&ptr, int &n, int &cap);
void imprimirDatos(const Cadena *ptr);
int compara(const void *a, const void *b);
int contar(Cadena *ptr);

#endif /* FUNCIONESAUXILIARES_H */
