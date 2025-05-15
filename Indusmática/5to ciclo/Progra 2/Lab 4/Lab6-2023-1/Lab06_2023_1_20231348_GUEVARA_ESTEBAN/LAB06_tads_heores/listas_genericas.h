/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listas_genericas.h
 * Author: esteban
 *
 * Created on 15 de mayo de 2025, 11:34
 */

#ifndef LISTAS_GENERICAS_H
#define LISTAS_GENERICAS_H

#include <fstream>

void crear_lista_heroes(void* arreglo_heroes,void* &lista_heroes,void* (*lee_heroe)
    (void*,int));
void construirLista(void* &lista);
void* lee_heroe(void *,int);
void insertarLista(void* lista,void* registro);
void imprimir_lista_heroes(void* lista_heroes, 
        void (*imprimir_registro)(void*,ofstream & archReporte));
void imprimir_registro_heroe(void* registro,ofstream & archReporte);
void eliminar_lista_heroes_repetidos(void* lst,bool (*eliminar_registro)(void*,void*&));
bool eliminar_registro(void* regAnt,void*& regAct);
#endif /* LISTAS_GENERICAS_H */
