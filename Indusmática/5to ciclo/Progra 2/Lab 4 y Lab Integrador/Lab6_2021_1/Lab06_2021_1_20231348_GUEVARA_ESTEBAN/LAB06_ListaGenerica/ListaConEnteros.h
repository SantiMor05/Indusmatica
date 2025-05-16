/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.h
 * Author: esteban
 *
 * Created on 8 de mayo de 2025, 17:17
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void* leenum(ifstream &archLee);
int cmpnum(const void* datLst,const void* dato);
int obtenernum(void* dato);
void imprimenum(void* datoAnterior,void* datoActual,ofstream & archReport);
#endif /* LISTACONENTEROS_H */
