/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: Lenovo
 *
 * Created on 8 de mayo de 2025, 10:44 PM
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

#include <fstream>
using namespace std;

//Funciones lista
void construirLista(void *&lista);
bool esListaVacia(void *lst);
void *quitaPrimerNodo(void *lst);
void *obtenerCola(void *lst);

void creaLista(void *&lista, void *(*leer)(ifstream &arch), int (*comparar)(const void*, const void*), 
               const char*nombArch);
void insertarOrdenado(void *reg, void *lst, int (*comparar)(const void*, const void*));
void imprimeLista(void *lst, void (*imprimir)(ofstream &, void *, void*), const char*nombArch);
void uneLista(void *&lst1, void *lst2);


#endif /* BIBLIOTECALISTAGENERICA_H */
