/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.h
 * Author: santi
 *
 * Created on 14 de mayo de 2025, 10:26
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

#include <fstream>
using namespace std;

void *leenum(ifstream &arch);
int cmpnum(const void *dato1, const void *dato2);
void imprimenum(const void *dato, ofstream &arch);

#endif /* LISTACONENTEROS_H */
