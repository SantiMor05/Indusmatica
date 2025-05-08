/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesEnteras.h
 * Author: kenyi
 *
 * Created on 7 de mayo de 2025, 08:27 PM
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H

#include <fstream>
using namespace std;


void *leenum(ifstream &arch);

void imprimenum(const void*dato,ofstream &arch);

int cmpnum(const void*dato1,const void*dato2);

#endif /* FUNCIONESENTERAS_H */
