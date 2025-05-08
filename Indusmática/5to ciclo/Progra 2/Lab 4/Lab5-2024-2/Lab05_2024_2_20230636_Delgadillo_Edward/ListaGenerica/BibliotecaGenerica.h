/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: alulab14
 *
 * Created on 7 de mayo de 2025, 10:48 AM
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void crealista(void*&lista,void*(*leer)(ifstream &),const char*nombArch);
void construir(void*&lis,int espacio);
void insertafinal(void*dato,void*lis);

void muestralista(void*lis,void(*imprimir)(const void*,ofstream&),
        const char*nombArch);

void cargalista(void*lis,int(*comparar)(const  void*,const void*),
        void*(*leerReg)(ifstream &),
        const char*nombArch);
void buscar(void*lis,void*reg,int(*comparar)(const  void*,const void*));
void agregarReg(void*&arr,void*nuevo);



#endif /* BIBLIOTECAGENERICA_H */
