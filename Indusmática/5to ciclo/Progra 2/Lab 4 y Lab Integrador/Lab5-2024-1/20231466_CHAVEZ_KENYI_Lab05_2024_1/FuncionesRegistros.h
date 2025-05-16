/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesRegistros.h
 * Author: kenyi
 *
 * Created on 7 de mayo de 2025, 08:28 PM
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

#include <fstream>
using namespace std;


int cmpregistro(const void *dato1,const void *dato2);

char *leerExacto(ifstream &arch,int max,char del);

void *leeregistro(ifstream &arch);

void imprimeregistro(const void*dato,ofstream &arch);

#endif /* FUNCIONESREGISTROS_H */
