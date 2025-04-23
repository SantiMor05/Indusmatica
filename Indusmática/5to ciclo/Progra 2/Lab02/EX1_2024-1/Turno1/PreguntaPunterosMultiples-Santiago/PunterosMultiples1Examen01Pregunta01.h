/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosMultiples1Examen01Pregunta01.h
 * Author: santi
 *
 * Created on 22 de abril de 2025, 22:11
 */

#ifndef PUNTEROSMULTIPLES1EXAMEN01PREGUNTA01_H
#define PUNTEROSMULTIPLES1EXAMEN01PREGUNTA01_H

#include <fstream>
using namespace std;

void cargarVentas(char **&ventasLibroCodigo, int **&ventasDniFechaPuntaje, 
        const char *nombArch);
int *leerCalifacion(ifstream &arch);
void incrementarEspacios(char **&codLibro, int **&ventasDniFechaPuntaje, 
        int &numDat, int &cap);
char *leerCadenaExacta(ifstream &arch, char deli);
void pruebaDeCargaDeVentas(char **ventasLibroCodigo, int **ventasDniFechaPuntaje, 
        const char *nombArch);
void imprimirCaracter(ofstream &arch, int n, char car);
void cargaLibros(char ***&libro, const char *nombArch);
int comparar(const void *a, const void *b);
char **leerInfoLibro(ifstream &arch);
void incrementarEspacios(char ***&libro,int &numDat, int &cap);
void pruebaDeCargaDeLibros(char ***libro, const char *nombArch);

#endif /* PUNTEROSMULTIPLES1EXAMEN01PREGUNTA01_H */

