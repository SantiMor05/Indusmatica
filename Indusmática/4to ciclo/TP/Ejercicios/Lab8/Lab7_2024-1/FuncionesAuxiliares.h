/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 8 de noviembre de 2024, 22:34
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
using namespace std;

void pedirDatos(char *&facu1, char *&facu2);
char *leerCadenaExactaConsola();
void pasarAMayusculas(char *arr);
void leerCalificaciones(int &cant_alumnos, int *arrCodigoAlumnos, 
        int *arrNumCursos, double *arrSumaPonderada, double *arrNumCreditos, 
        const char *nombCali);
void leerAlumnos(int cant_alumnos, int *arrCodigoAlumnos, char **arrAlumnos, 
        char **arrFacultad, const char *nombAlum);
void emitirReporte(char *facu1, char *facu2, int cant_alumnos,
        int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada,
        double *arrNumCreditos, char **arrAlumnos, char **arrFacultad,
        double *promedio, const char *nombReporte, const char *nombFacu);
void imprimirEncabezado(const char *nombFacu, char *facu1, char *facu2, 
        ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void formatearNombre(char *nombre);
char *leerCadenaExacta(ifstream &archAlum, int opcion);
char *leerCadenaExacta(ifstream &archAlum, int opcion);
int buscarAlumno(int alumno, int cant_alumnos, int *arrCodigoAlumnos);
void ordenarAlumnos(int cant_alumnos, int *arrCodigoAlumnos, int *arrNumCursos,
        double *arrSumaPonderada, double *arrNumCreditos, char **arrAlumnos,
        char **arrFacultad, double *promedio) ;
void intercambiarInt(int i, int j, int *arr);
void intercambiarCadenas(char *&cad1, char *&cad2);
void intercambiarDouble(int i, int j, double *arr);



#endif /* FUNCIONESAUXILIARES_H */

