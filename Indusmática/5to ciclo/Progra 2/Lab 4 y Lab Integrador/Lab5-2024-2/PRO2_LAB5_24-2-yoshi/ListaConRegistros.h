/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaConRegistros.h
 * Author: Usuario
 *
 * Created on 7 de mayo de 2025, 23:06
 */

#ifndef LISTACONREGISTROS_H
#define LISTACONREGISTROS_H

#include <fstream>

void* leerRegistros(ifstream &arch);
void imprimeReg(ofstream &arch, void* dato);
bool compruebaRegistro(const void* a, const void* b);
void *leerOrdenes(ifstream &arch);
char* leer_cadena(ifstream &arch,char flag='\n');
void imprimir_datos0(ofstream &arch,void **datos);
void imprimir_orden(void *arreglo, ofstream &arch);

#endif /* LISTACONREGISTROS_H */
