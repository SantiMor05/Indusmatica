/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListasGenericas.h
 * Author: Lenovo
 *
 * Created on 8 de mayo de 2025, 07:43 PM
 */

#ifndef LISTASGENERICAS_H
#define LISTASGENERICAS_H

#include <fstream>
using namespace std;

//Funciones lista
void construirLista(void *&lista);
bool esListaVacia(void *lst);
int longitudLista(void *lst);
void *quitaPrimerNodo(void *lst);

void crearListaHeroes(void *arrHeroes, void *&listaHeroes, void *(*leer)(void*));
void *leerRegHeroe(void *dato);
void insertarAlFinal(void *reg, void *&lista);

void imrpimirListaHeroes(void *listaHeroes, void (*imprimirRegHeroe)(ofstream &arch, void *dato), 
                         const char*nombArch);
void imprimirRegHeroe(ofstream &arch, void *dato);

void eliminarHeroesRepetidos(void *listaHeroes, int (*eliminar)(const void*, const void*));
int eliminarRegistro(const void*a, const void*b);


#endif /* LISTASGENERICAS_H */
