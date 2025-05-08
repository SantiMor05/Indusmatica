/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: Usuario
 *
 * Created on 8 de mayo de 2025, 10:05
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

void crearLista(void *&pedidos1, void*(*leer)(ifstream &arch),const char* nomArch);
void construirLista(void* &pedidos1);
void insertarFinal(void *registro,void *lista);
bool esListaVacia(void** lista);
void imprimeLista(void *&pedidos1, void(*imprime)(ofstream &arch, void*registro),const char* nomArch);
void* quitaLista(void** &lista, void **cabeza);
void combinaLista(void *pedidos1, void *pedidos2, void* &pedidosFinal, int(*compara)(const void*a, const void*b));

#endif /* BIBLIOTECAGENERICA_H */
