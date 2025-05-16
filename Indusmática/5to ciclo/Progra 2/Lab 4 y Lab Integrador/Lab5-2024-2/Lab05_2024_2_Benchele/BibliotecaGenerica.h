/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: Lenovo
 *
 * Created on 6 de mayo de 2025, 11:48 PM
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void creaLista(void *&lst, void *(leer)(ifstream &arch), const char*nombArch);
void insertar(void *reg, void *&lista);
void muestraLista(void *&lst, void (*imprimir)(ofstream &arch, void *dato), const char*nombArch);
void cargaLista(void *lst, int (comprobar)(const void *, const void *), void *(*leer)(ifstream &arch),
                const char*nombArch);
void buscarCoincidencia(void *reg, void **lista, int (comprobar)(const void *, const void *));
void insertaDatoEnArreglo(void *dpl, void *buscado);

#endif /* BIBLIOTECAGENERICA_H */
