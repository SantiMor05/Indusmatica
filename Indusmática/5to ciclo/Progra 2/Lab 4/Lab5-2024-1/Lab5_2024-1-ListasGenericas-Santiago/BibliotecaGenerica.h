/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: santi
 *
 * Created on 6 de mayo de 2025, 22:39
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

bool listavacia(void *lista);
void crealista(void *&pedidos, void *(*lee)(ifstream &), const char *nombArch);
void imprimelista(void *pedidos, void(*imprime)(void *dato, ofstream &arch),
        const char *nombArch);
void insertalista(void *pedidos, void *dato);
void construyeLista(void *&pedidos);

void *quitalista(void *lista);
void combinaLista(void *&pedidos1, void *&pedidos2, void *&pedidosfinal, 
        int cmpnum(const void*, const void*));
void liberarMemoria(void *&lista);
#endif /* BIBLIOTECAGENERICA_H */
