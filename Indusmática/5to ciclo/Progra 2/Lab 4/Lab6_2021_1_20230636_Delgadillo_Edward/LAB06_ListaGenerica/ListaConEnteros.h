/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.h
 * Author: 00123
 *
 * Created on 8 de mayo de 2025, 04:54 PM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

#include <fstream>
using namespace std;

void*leenum(ifstream &arch);
int cmpnum(const void*a,const void*b);

void imprimenum(const void*a,ofstream &arch);
#endif /* LISTACONENTEROS_H */
