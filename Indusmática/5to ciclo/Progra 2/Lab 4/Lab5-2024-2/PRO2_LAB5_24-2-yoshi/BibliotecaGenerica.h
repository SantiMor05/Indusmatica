/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: Usuario
 *
 * Created on 7 de mayo de 2025, 13:50
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

void crearLista(void* &lista, void*(*leer)(ifstream &arch),const char* nomArch);
void construir(void* &lista);
void insertarAlFinal(void *lista, void*registro);
bool esListaVacia(void* lista);
void muestraLista(void* lista, void(*imprime)(ofstream &arch,void* dato),const char* nomArch);
void cargarLista(void *lista, bool (*compara)(const void* a, const void* b),
        void*(*leer)(ifstream &arch),const char* nomArch);
void* buscar_pos(void *lista, void *registro, bool (*compara)(const void* a, const void* b));
void ubicar_en_pos(void *&ubicacion, void*registro);
void borrar_dato_inncesario(void *&registro);

#endif /* BIBLIOTECAGENERICA_H */
