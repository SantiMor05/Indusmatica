/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 26 de septiembre de 2024, 20:19
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

void leerDatos(double *x,double *y, int &numDat, const char *nombreArch);
void probarDatos(double *x,double *y, int numDat, const char *nombReporte);
void imprimirCaracter(char car, int n, ofstream &archReporte);
void calcularAreaYPerimetro(int numDat, double *x, double *y, double &area, 
        double &perimetro);
void imprimirReporteFinal(double *x,double *y,int numDat, 
        const char *nombReporte);

#endif /* FUNCIONESAUXILIARES_H */

