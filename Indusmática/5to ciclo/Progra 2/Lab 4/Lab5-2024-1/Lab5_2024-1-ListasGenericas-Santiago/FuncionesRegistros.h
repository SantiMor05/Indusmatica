/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesRegistros.h
 * Author: santi
 *
 * Created on 7 de mayo de 2025, 21:50
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

#include <fstream>
using namespace std;

void *leeregistro(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char deli);
void imprimeRegistro(void *dato, ofstream &arch);
int cmpregistro(const void *dato1, const void *dato2);

#endif /* FUNCIONESREGISTROS_H */
