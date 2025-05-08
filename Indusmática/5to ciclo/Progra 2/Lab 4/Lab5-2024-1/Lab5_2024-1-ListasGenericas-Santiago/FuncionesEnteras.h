/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEnteras.h
 * Author: santi
 *
 * Created on 6 de mayo de 2025, 22:59
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H

#include <fstream>
using namespace std;

void *leenum(ifstream &arch);
void imprimenum(void *dato, ofstream &arch);
int cmpnum(const void *dato1, const void *dato2);

#endif /* FUNCIONESENTERAS_H */
