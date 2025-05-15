/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistro.h
 * Author: santi
 *
 * Created on 14 de mayo de 2025, 10:44
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H

#include <fstream>
using namespace std;

void *leeregistro(ifstream &arch);
int cmpregistro(const void *dato1, const void *dato2);
void imprimeregistro(const void *dato, ofstream &arch);
void imprimirLinea(ofstream &arch, int n, char car);
void buscarEImprimirNombre(int licencia, ifstream &archConductores, 
        ofstream &arch);

#endif /* LISTACONREGISTRO_H */
