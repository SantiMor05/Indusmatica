/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesEnteras.h
 * Author: Lenovo
 *
 * Created on 7 de mayo de 2025, 11:28 AM
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H

#include <fstream>
using namespace std;

void *leeNum(ifstream &arch);
void imprimeNum(ofstream &arch, void *dato);
int cmpNum(const void*, const void *);

#endif /* FUNCIONESENTERAS_H */
