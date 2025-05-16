/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: Usuario
 *
 * Created on 8 de mayo de 2025, 18:20
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

void crearLista(void *&lista, const char* nomArch);
void construirLista(void *&lista);
void* leer_registro(ifstream &arch);
char * leer_cadena(ifstream &arch, char flag = '\n');
void insertar_dato(void *registro, void**lista);
void* buscar_familia(void *registro,void**lista);
int comparaReg(void *registro, void* recorrido);
void llenar_dato_extraordinario(void *registro, void** lista, int opcion);
bool esListaVacia(void *lista);
void imprimeLista(void *lis,const char* nomArch);
void imprimir_registro(void *registro, ofstream &arch);
void unirColasFinal(void *lista);

#endif /* BIBLIOTECAGENERICA_H */
