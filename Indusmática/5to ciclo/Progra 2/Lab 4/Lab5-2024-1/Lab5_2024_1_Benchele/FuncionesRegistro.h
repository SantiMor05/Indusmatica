/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesRegistro.h
 * Author: Lenovo
 *
 * Created on 7 de mayo de 2025, 10:10 PM
 */

#ifndef FUNCIONESREGISTRO_H
#define FUNCIONESREGISTRO_H

#include <fstream>
using namespace std;

void *leeRegistro(ifstream &arch);
void imprimeRegistro(ofstream &arch, void *dato);
int cmpReg(const void*a, const void*b);

#endif /* FUNCIONESREGISTRO_H */
