/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncioneAuxiliares.h
 * Author: santi
 *
 * Created on 10 de octubre de 2024, 23:46
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
using namespace std;

void leerPacientes(int &cant_pacientes, int *dni, int *distrito, 
        char *clasificacion, double *descuento, const char *nombPacientes);
void leerMedicinas(int &cant_medicinas, int *medicina, double *costo, 
        const char *nombMedicinas);
void emitiirPrueba(int cant_pacientes, int *dni, int *distrito, 
        char *clasificacion, double *descuento, int cant_medicinas, 
        int *medicina, double *costo, const char *nombPrueba);
void imprimirCaracter(char car, int n, ofstream &archSalida);
char clasificar(int aa);
void saltarTexto(char deli, ifstream &archPacientes);
int buscarPos(int codigo, int cant, int *arr);
void intercabiarInt(int i, int j, int *arr);
void intercabiarChar(int i, int j, char *arr);
void intercabiarDouble(int i, int j, double *arr);
void actualizarDatos(int cant_pacientes, int *dni, int *distrito, 
        char *clasificacion, double *descuento, int *cant_citas, 
        int *num_medicinas, double *pago, int cant_medicinas, 
        int *medicina, double *costo, const char *nombCitas);
void ordenarArreglos(int cant_pacientes, int *dni, int *distrito, 
        char *clasificacion, double *descuento, int *cant_citas, 
        int *num_medicinas, double *pago);
void imprimirEncabezado(ofstream &archReporte);
void imprimirReporte(int cant_pacientes, int *dni, int *distrito,
        char *clasificacion, double *descuento, int *cant_citas,
        int *num_medicinas, double *pago, const char *nombReporte);

#endif /* FUNCIONESAUXILIARES_H */

