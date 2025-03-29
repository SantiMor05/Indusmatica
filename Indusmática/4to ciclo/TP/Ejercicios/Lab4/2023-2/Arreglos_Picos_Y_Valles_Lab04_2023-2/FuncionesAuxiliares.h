
/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 26 de septiembre de 2024, 21:32
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

void leerDatos(int *anhos, int *ganancias, int &numDat, const char *nombDatos);
void imprimirCaracter(char car, int n, ofstream &archSalida);
void reporteDePrueba(int *anhos, int *ganancias, int numDat, 
        const char *nombPrueba);
void encontrarPicosYValles(int *anhos, int *ganancias, int *picos, int *valles, 
        int *a_picos, int *a_valles, int &cant_picos, int &cant_valles, 
        int numDat);
void imprimirEncabezado(ofstream &archReporte);
int encontrarPicoMayor(int *picos, int cant_picos);
void imprimirEncabezadoValles(ofstream &archReporte);
int encontrarValleMenor(int *valles, int cant_valles);
void emitirReporte(int *anhos, int *ganancias, int numDat, 
        const char *nombReporte);

#endif /* FUNCIONESAUXILIARES_H */

