/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: santi
 *
 * Created on 13 de mayo de 2025, 23:32
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

#include <fstream>
using namespace std;

void construyeLista(void *&lista);
void creaLista(void *&lista, void *(*lee)(ifstream &arch), int cmp(const void *dato1,
        const void *dato2), const char *nombArch);
bool listavacia(void *lista);
void insertaLista(void *&lista, void *dato, int cmp(const void *dato1,
        const void *dato2));
void uneLista(void *lista1, void *lista2);
void imprimeLista(void *lista, void (*imprime)(const void *dato, ofstream &arch),
        const char *nombArch);

#endif /* BIBLIOTECALISTAGENERICA_H */
