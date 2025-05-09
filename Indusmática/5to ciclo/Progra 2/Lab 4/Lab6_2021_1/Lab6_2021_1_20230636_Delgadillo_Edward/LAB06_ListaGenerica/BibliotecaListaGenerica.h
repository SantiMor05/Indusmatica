/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: 00123
 *
 * Created on 8 de mayo de 2025, 04:54 PM
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

#include <fstream>
using namespace std;

void creaLista(void*&lis,void*(*leer)(ifstream &),
        int(*comparar)(const void*,const void*),const char*nombArch);
void insertaLista(void*dato,void*lis,
        int(*comparar)(const void*,const void*));
void obtenerAnt(void*dato,void**lista,
        int(*comparar)(const void*,const void*),
        void**&ant,void*&esValido);
void**crearNodo(void*dato,void*conti);

void imprimeLista(void*lis,void(*imprimir)(const void*,ofstream&),
        const char*nombArch);

void uneLista(void*lis1,void*lis2);

#endif /* BIBLIOTECALISTAGENERICA_H */
