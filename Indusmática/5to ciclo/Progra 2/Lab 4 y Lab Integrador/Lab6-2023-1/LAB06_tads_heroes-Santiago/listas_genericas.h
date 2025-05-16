/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listas_genericas.h
 * Author: santi
 *
 * Created on 15 de mayo de 2025, 11:01
 */

#ifndef LISTAS_GENERICAS_H
#define LISTAS_GENERICAS_H

#include <fstream>
using namespace std;

void inicializarLista(void *&lista);
void crear_lista_heroes(void *arreglo_heroes, void *&lista, 
        void *(*leer_heroe)(void *heroe));
void imprimir_lista_heroes(void *lista, void (*imprime)(const void *dato, 
        ofstream &arch));

void eliminar_lista_heroes_repetidos(void *lista, bool (*elimina)(const void*anterior,
        void *actual));
#endif /* LISTAS_GENERICAS_H */
