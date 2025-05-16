/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaConEnteros.h
 * Author: esteban
 *
 * Created on 15 de mayo de 2025, 15:43
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

#include <fstream>

int cmpnumero(const void* datA,const void* datB);
void * leenumero(ifstream& archLee);
void imprimenumero(void*dato,ofstream &archReport);
#endif /* PILACONENTEROS_H */
