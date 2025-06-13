/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesParte02EX1.h
 * Author: santi
 *
 * Created on 20 de abril de 2025, 23:00
 */

#ifndef FUNCIONESPARTE02EX1_H
#define FUNCIONESPARTE02EX1_H

#include <fstream>
using namespace std;

void leerConductores(int *&dni, char **&conductor, char ***&placas);
void incrementarEspacios(int &numDat, int &cap, int *&dni, char **&conductor, 
        char ***&placas);
char **leerPlacas(ifstream &arch);
void incrementarEspacios(int &numDat, int &cap, char **&placas);
char *leerCadenaExactaGet(ifstream &arch, int);
char *leerCadenaExacta(ifstream &arch, char deli);
void imprimirConductores(int *dni, char **conductor, char ***placas);
void imprimirPlacas(ofstream &arch, char **placas);
void imprimirCaracter(ofstream &arch, int n, char car);
void leerMultas(double *&multas);
void imprimirMultas(double *multas);
void leerInfraccionesCometidas(int *dni, char ***placas,double *multas,
        double ***&montoXMultas);
void agregarMulta(double **montoXMultas, char **placas, char *codigo, double monto);
void destinarEspacios(double **&montoXMultas, char **placas);
int buscarDni(int documento, int *dni);
int calcularCantidadPersonas(int *dni);
void imprimirInfraccionesCometidas(int *dni, char **conductor,char ***placas,
        double ***montoXMultas);
void imprimirPlacas(ofstream &arch, char **placas, double **montXMultas);


#endif /* FUNCIONESPARTE02EX1_H */

