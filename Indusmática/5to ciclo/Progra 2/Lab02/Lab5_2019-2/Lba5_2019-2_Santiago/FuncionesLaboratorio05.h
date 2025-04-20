/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesLaboratorio05.h
 * Author: santi
 *
 * Created on 18 de abril de 2025, 21:00
 */

#ifndef FUNCIONESLABORATORIO05_H
#define FUNCIONESLABORATORIO05_H

#include <fstream>
using namespace std;

void leerPalets(char *** &almacenes);
char **leerRegistroPalet(ifstream &arch);
void incrementarEspacios(char ** &productos, int &numDat, int &cap);
char *leerCadenaExacta(ifstream &arch, char delimitador) ;
void imprimirPalets(char ***almacenes);
void imprimirProductosEnAlmacen(char **almacen,ofstream &archReporte);
void leerProductos(char **&codigoProd, char **&nombreProd);
void imprimirProductos(char **codigoProd, char **nombreProd);
void ordenarProductos(char **codigoProd, char **nombreProd);
void qsort(char **codigoProd, char **nombreProd, int izq, int der);
void cambiar(char **codigoProd, char **nombreProd, int i, int k);
void cuentaProductos(char ***almacenes,char **codigoProd, char **nombreProd);
int contarPalets(char *codigoProd, char ***almacenes);
int contarPaletsEnAlmacen(char *codigoProd,char **almacen);
void imprimirCaracter(ofstream &archReporte, int n, char car);

#endif /* FUNCIONESLABORATORIO05_H */

