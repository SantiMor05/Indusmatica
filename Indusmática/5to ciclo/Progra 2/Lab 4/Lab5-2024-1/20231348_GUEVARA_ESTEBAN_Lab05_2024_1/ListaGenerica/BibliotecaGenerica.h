/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: esteban
 *
 * Created on 8 de mayo de 2025, 10:09
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>

using namespace std;


void crealista(void* &lista,void* (*lee)(ifstream &),const char* nombreArch);
void inicializamosLista(void*& lista);
bool  listaVacia(void* lista);
void insertalista(void* lst,void* reg);
void imprimelista(void* pedido1,void (*imprime)(void*,ofstream&),
        const char* nombreArch);
void combinalista(void* lst1,void*lst2,void*& lstFinal,
        int (*cmp)(const void*,const void*));
void * quitarlista(void* &lista);
#endif /* BIBLIOTECAGENERICA_H */
