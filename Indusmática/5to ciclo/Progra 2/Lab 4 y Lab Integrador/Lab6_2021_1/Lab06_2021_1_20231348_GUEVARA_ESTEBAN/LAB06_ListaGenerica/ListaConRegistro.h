/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistro.h
 * Author: esteban
 *
 * Created on 8 de mayo de 2025, 20:14
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H

#include <fstream>


void* leeregistro(ifstream &archLee);
char* lecturaExacta(ifstream &archLee,char delim);
int cmpregistro(const void* regLista,const void* reg);
void imprimeregistro(void* regAnt,void* reg,ofstream& archReporte);
void imprimirEncabezado(ofstream &archReporte,int fechEncaActual);
void impresionLinea(ofstream &archReporte,char car );
void imprimir(ofstream &archReporte,void** regActual);
#endif /* LISTACONREGISTRO_H */
