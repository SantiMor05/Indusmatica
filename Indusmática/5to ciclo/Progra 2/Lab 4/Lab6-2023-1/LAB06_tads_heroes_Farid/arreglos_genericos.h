/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   arreglos_genericos.h
 * Author: Usuario
 *
 * Created on 8 de mayo de 2025, 03:20 PM
 */

#ifndef ARREGLOS_GENERICOS_H
#define ARREGLOS_GENERICOS_H

void llenar_arreglo_heroes(void *&arr, int &cant, const char* nomarch);
void * leerRegistro(ifstream &arch);
char*leerExacto(ifstream &arch, int max, char del);
void incrementarCap(void **&arreglo,int cant,int &cap);
int cmp_multicriteriovoid(const void*dato1, const void*dato2);
void imprimirarr(const void *arr, const char*nomarch, int nd);

void *leer_heroes(void *arr);
void imprimirLista(void *arr, ofstream &arch);
int eliminar_registro(const void*dato1, const void* dato2 );
#endif /* ARREGLOS_GENERICOS_H */


