/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 1 de noviembre de 2024, 15:44
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

int pedirCiclo();
void leerAlumnos(int &cant_alumnos, int *alumno, char **nombre, 
        char *escala_alum, const char *nombAlum);
char *leerCadenaExacta(ifstream &archAlum);
void strcpy2(char *destino, const char *fuente);
int strlen(char *nombre);
void imprimirCaracter(char car, ofstream &archReporte);
void formatearNombre(char *nombre);
void intercambiarInt(int i, int j, int *arr);
void intercambiarDouble(int i, int j, double *arr) ;
void intercambiarChar(int i, int j, char *arr);
void intercambiarCadena(char *&ptr1, char *&ptr2);
int buscar(int cod, int cant, int *arr);
int buscarEscala(int ciclo, char escala_alum, int cant_escalas, 
        int *ciclo_escala, char *escala);
void imprimirEncabezado(int ciclo, ofstream &archReporte);
void leerCursos(int &cant_cursos, int *curso, double *creditos,
        const char *nombCurso);
void leerEscalas(int &cant_escalas, int *ciclo_escala, char *escala,
        double *costo, const char *nombEscala);
void ordenarAlumnos(int cant_alumnos, int *alumno, char **nombre,
        char *escala_alum);
void ordenarCursos(int cant_cursos, int *curso, double *creditos);
void leerMatricula(int ciclo, int cant_alumnos, int *alumno, char *escala_alum, 
        int *cursos_alum, double *creditos_alum, double *monto, int cant_cursos, 
        int *curso, double *creditos, int cant_escalas, int *ciclo_escala, 
        char *escala, double *costo, const char *nombMatri);
void emitirReporte(int ciclo, int cant_alumnos, int *alumno, char **nombre, 
        char *escala_alum, int *cursos_alum, double *creditos_alum, 
        double *monto, const char *nombReporte);
void ordenarArreglos(int cant_alumnos, int *alumno, char **nombre, 
        char *escala_alum, int *cursos_alum, double *creditos_alum, 
        double *monto);
#endif /* FUNCIONESAUXILIARES_H */

