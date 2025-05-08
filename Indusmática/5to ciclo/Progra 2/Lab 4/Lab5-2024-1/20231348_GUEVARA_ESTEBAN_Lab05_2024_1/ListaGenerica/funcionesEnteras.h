/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesEnteras.h
 * Author: esteban
 *
 * Created on 8 de mayo de 2025, 10:14
 */

#ifndef FUNCIONESENTERAS_H
#define FUNCIONESENTERAS_H

#include <fstream>


void * leenum(ifstream& archLeer);
void imprimenum(void* reg,ofstream &archReport);
int cmpnum (const void* datoLst1,const void* datoLst2);
#endif /* FUNCIONESENTERAS_H */
