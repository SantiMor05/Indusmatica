/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibManejoDinamicoDeMemoria.h
 * Author: esteban
 *
 * Created on 23 de abril de 2025, 13:27
 */

#ifndef BIBMANEJODINAMICODEMEMORIA_H
#define BIBMANEJODINAMICODEMEMORIA_H

#include <fstream>
using namespace std;

void cargaConductores(int *&licencia, char **&conductor);
char *leerCadenaExacta(ifstream &arch, char deli);
void incrementarEspacios(int *&licencia, char **&conductor, int &numDat,
        int &cap);
void reporteConductores(int *licencia, char **conductor);
void cargaFaltas(int *licencia, char ***&placa, int **&faltas);
void incrementarEspacios(char **&placa, int *&falta, int &ndatos);
int buscarDocumento(int documento,int *licencia);
int contarDatos(int *licencia);
void reporteFaltas(int *licencia, char **conductor, char ***placa, int **falta);
void imprimirLinea(ofstream &arch, int n, char car);
void imprimirFaltas(char **placas, int *falta, ofstream &arch);
void imprimirMultas(double *multa, ofstream &arch);
void colocarMultas(int **falta, double **multa, int numFalta, char *tipoFalta,
        double monto, int numDat);
void darleEspacios(double *&multa);
void resumenMultas(int *licencia, int **falta, double **&multa);

void reporteMultas(int *licencia, char **conductor, double **multa);


#endif /* BIBMANEJODINAMICODEMEMORIA_H */
