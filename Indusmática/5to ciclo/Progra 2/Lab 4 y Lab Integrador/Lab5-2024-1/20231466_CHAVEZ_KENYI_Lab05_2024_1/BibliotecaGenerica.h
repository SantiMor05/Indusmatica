/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: kenyi
 *
 * Created on 7 de mayo de 2025, 08:26 PM
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void insertarlista(void *&lista,void *dato);

bool listavacia(void *lista);

void construir(void *&lista);

void crearlista(void *&pedido, void* (*lee)(ifstream&), const char *nombArch);

void imprimelista(void *pedido, void (*imprime)(const void *, ofstream &),
        const char *nombArch);

void combinalista(void *lista1,void *lista2,void *&listafinal,
        int (*cmp)(const void *,const void*));


void *quitalista(void *lista);
#endif /* BIBLIOTECAGENERICA_H */
