/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistro.h
 * Author: 00123
 *
 * Created on 8 de mayo de 2025, 04:54 PM
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H

#include <fstream>
using namespace std;

void*leeregistro(ifstream &arch);
int cmpregistro(const void*a,const void*b);
void imprimeregistro(const void*reg,ofstream &arch);
char*buscarNombre(int buscado,ifstream &arch);
void imprimeLinea(ofstream &arch,int n,char c);
#endif /* LISTACONREGISTRO_H */
