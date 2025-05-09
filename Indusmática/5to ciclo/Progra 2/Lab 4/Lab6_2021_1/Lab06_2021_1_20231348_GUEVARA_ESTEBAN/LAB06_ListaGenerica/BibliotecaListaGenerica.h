/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: esteban
 *
 * Created on 8 de mayo de 2025, 16:40
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

#include <fstream>
using namespace std;

void creaLista(void* &lst,void* (*lee)(ifstream&),int (*cmp)(const void*,const void*),
        const char* nombreArch);
void inicializaLista(void*&lst);

void insertarLista(void *reg,void* lista,int (*cmp)(const void*,const void*));
bool listavacia(void* lst);
void uneLista(void *&lista1,void* lista2);
void imprimeLista(void* lista1,void (*imprime)(void*,void*,ofstream &),
        const char* nombreArch);  

#endif /* BIBLIOTECALISTAGENERICA_H */
