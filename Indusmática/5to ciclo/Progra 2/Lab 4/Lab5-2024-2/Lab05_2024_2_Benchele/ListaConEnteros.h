/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: Lenovo
 *
 * Created on 6 de mayo de 2025, 11:48 PM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

#include <fstream>
using namespace std;

void *leeNumeros(ifstream &arch);
void imprimeNumeros(ofstream &arch, void *dat);
void* leeRegNumeros(ifstream &arch);
int compruebaNumero(const void*a, const void*b);

void imprimirUno(ofstream &arch, void *entero, int i);

#endif /* LISTACONENTEROS_H */
