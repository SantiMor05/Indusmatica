/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaConRegistros.h
 * Author: esteban
 *
 * Created on 15 de mayo de 2025, 22:36
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H
void* leeregistro(ifstream& archLee);
char* lecturaExacta(ifstream &archLee,char delim);
int cmpregistro(const void* dA, const void* dB);
void imprimeregistro(void* reg,ofstream& archReporte);
#endif /* PILACONREGISTROS_H */
