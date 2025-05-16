/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: kenyi
 *
 * Created on 8 de mayo de 2025, 11:48 AM
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H
void crelista(void *&lista, void *(*lee)(ifstream&),
        const char*nombArch);

void construir(void *&lista);

void insertarlista(void *&lista,void *dato);

bool eslistavacia(void *lista);

void cargalista(void *lista, int (*cmp)(const void*, const void*),
        void *(*lee)(ifstream&), const char*nombArch);

void buscargAgregar(void *dato,void *lista,int (*cmp)(const void*,
        const void*));


void ponerDatoEnArreglo(void **&dupla,void *dato);

void muestralista(const void *lista, void (*imprimenumeros)(const void*,
        ofstream&), const char*nombArch);
#endif /* BIBLIOTECAGENERICA_H */
