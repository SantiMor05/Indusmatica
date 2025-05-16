/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ArreglosGenericos.h
 * Author: Lenovo
 *
 * Created on 8 de mayo de 2025, 06:56 PM
 */

#ifndef ARREGLOSGENERICOS_H
#define ARREGLOSGENERICOS_H

#include <fstream>
using namespace std;

void llenarArregloHeroes(void *&arrHer, int &cant, const char*nombArch);
int cmpMulticriterioVoid(const void*a, const void*b);

void *leerRegistro(ifstream &arch);

void imrpimriHeros(void *arrHeroes);


#endif /* ARREGLOSGENERICOS_H */
