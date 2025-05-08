/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaconEnteros.h
 * Author: kenyi
 *
 * Created on 8 de mayo de 2025, 12:07 PM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H
#include <fstream>
using namespace std;
void* leenumeros(ifstream &arch);
int compruebanumero(const void *dato1,const void*dato2);

void* leeregnumeros(ifstream &arch);

void imprimenumeros(const void *dato,ofstream &arch);
#endif /* LISTACONENTEROS_H */
