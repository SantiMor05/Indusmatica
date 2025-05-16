/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: Lenovo
 *
 * Created on 8 de mayo de 2025, 11:00 PM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

#include <fstream>
using namespace std;

void *leeNum(ifstream &arch);
int cmpNum(const void*a, const void*b);
void imprimeNum(ofstream &arch, void *anterior, void *actual);

#endif /* LISTACONENTEROS_H */
