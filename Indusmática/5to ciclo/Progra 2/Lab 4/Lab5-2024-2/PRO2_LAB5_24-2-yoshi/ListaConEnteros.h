/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: Usuario
 *
 * Created on 7 de mayo de 2025, 14:07
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void* leerNumeros(ifstream &arch);
void imprimeNumeros(ofstream &arch, void* dato);
bool compruebaNum(const void* a, const void* b);
void *leerRegNum(ifstream &arch);

#endif /* LISTACONENTEROS_H */
