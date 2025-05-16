/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: santi
 *
 * Created on 5 de mayo de 2025, 19:01
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void construir (void *&lista);
bool eslistavacia(void *lista);
void crealista(void *&lista, void* (*lee)(ifstream &), const char*nombArch);
void insertarfinal(void *&lista, void *aux);

void cargalista(void *lista, int (*cmp)(const void *, const void *), 
        void *(*lee)(ifstream &), const char *nombArch);
void buscarActualizarDupla(void *numero, void *lista, 
        int (*cmp)(const void *, const void *));
void insertarArreglo(void *dupla, void *dato);
void muestralista(void *lista, void(*imprime)(const void *, ofstream&), 
        const char *nombArch);


#endif /* BIBLIOTECAGENERICA_H */
