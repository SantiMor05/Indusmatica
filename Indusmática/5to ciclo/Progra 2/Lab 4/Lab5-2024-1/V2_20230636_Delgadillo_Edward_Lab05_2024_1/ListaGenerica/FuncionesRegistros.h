/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesRegistros.h
 * Author: 00123
 *
 * Created on 8 de mayo de 2025, 08:56 AM
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

#include <fstream>
using namespace std;

void*leeregistro(ifstream &arch);
int cmpregistro(const void*a,const void*b);
void imprimeregistro(const void*reg,ofstream &arch);


#endif /* FUNCIONESREGISTROS_H */
