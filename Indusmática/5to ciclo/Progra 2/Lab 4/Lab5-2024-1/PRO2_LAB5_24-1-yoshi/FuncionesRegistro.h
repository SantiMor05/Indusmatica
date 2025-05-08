/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesRegistro.h
 * Author: Usuario
 *
 * Created on 8 de mayo de 2025, 11:23
 */

#ifndef FUNCIONESREGISTRO_H
#define FUNCIONESREGISTRO_H

#include <fstream>

void* leeReg(ifstream &arch);
void imprimeReg(ofstream &arch, void* dato);
int cmpReg(const void* a, const void* b);
char* leer_cadena(ifstream &arch, char flag='\n');

#endif /* FUNCIONESREGISTRO_H */
