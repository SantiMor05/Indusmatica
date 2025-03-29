/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 23 de octubre de 2024, 20:46
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

char *pedirFacultad();
void pasarAMayusculas(char *facultad);
void insertarOrdenado(int &num_alumnos, int *arrCodigoAlumnos, int *arrNumCursos, 
        double *arrSumaPonderada, double *arrNumCreditos, int alumno,
        int nota, double creditos);
void leerAlumnos(int &num_alumnos, int *arrCodigoAlumnos, int *arrNumCursos, 
        double *arrSumaPonderada, double *arrNumCreditos, const char *nombCali);
int buscarAlumno(int alumno, int num_alumnos, int *arrCodigoAlumnos);
void imprimirReporte(const char *nombAlumnos, char *facultad, int num_alumnos, 
        int *arrCodigoAlumnos, int *arrNumCursos, double *arrSumaPonderada, 
        double *arrNumCreditos,  const char *nombReporte);
void imprimirEncabezado(char *facultad, ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void copiarFormateada(char *aux, const char *facultad);
int calcularLongitudTexto(char *facultad);
int comparar(char *cadena1, char *cadena2);
void formatearNombre(char *nombre);
void concatenar(char *cadena1, char *cadena2);
int strlen(char *cadena);
void pasarATipoOracion(char *nombre);


#endif /* FUNCIONESAUXILIARES_H */

