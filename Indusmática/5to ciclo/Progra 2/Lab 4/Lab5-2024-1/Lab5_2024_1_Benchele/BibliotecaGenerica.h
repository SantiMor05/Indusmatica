/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: Lenovo
 *
 * Created on 7 de mayo de 2025, 11:11 AM
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void creaLista(void *&pedidos, void *(*leer)(ifstream &arch), const char*nombArch);
void combinaLista(void *ped1, void *ped2, void *&pedFinal, int (*comparar)(const void*, const void*));
void imprimeLista(void *ped, void (*imprimir)(ofstream &arch, void *dato), const char*nombArch);

void insertarAlFinal(void *reg, void *&pedidos);

bool esListaVacia(void **lista);
void *quitaLista(void *lst);
void insertarFaltantes(void *dato1, void *dato2, void **pedidos1, void **pedidos2, 
                       void *pedFinal);

#endif /* BIBLIOTECAGENERICA_H */
