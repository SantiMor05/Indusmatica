/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEnteras.h
 * Author: 00123
 *
 * Created on 8 de mayo de 2025, 08:55 AM
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H

#include <fstream>
using namespace std;

void*leenum(ifstream &arch);
void imprimenum(const void*a,ofstream &arch);

int cmpnum(const void*a,const void*b);

#endif /* FUNCIONESENTERAS_H */
