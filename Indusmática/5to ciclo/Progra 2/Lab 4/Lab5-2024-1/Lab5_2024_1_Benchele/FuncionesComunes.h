/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesComunes.h
 * Author: Lenovo
 *
 * Created on 6 de mayo de 2025, 11:48 PM
 */

#ifndef FUNCIONESCOMUNES_H
#define FUNCIONESCOMUNES_H

#include <fstream>
using namespace std;

void verificar_Apertura_I(ifstream &arch, const char*nombArch);
void verificar_Apertura_O(ofstream &arch, const char*nombArch);
char *leerCadenaExacta(ifstream &arch, char delimitador = '\n');

#endif /* FUNCIONESCOMUNES_H */
