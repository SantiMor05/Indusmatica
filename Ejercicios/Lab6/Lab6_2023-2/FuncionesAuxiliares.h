/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 27 de octubre de 2024, 21:57
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

int pedirCiclo();
void leerAlumnos(int &cant_alumnos, int *alumnos, char *escala_alum,
        const char *nombAlumnos) ;
void ordenarAlumnos(int cant_alumnos, int *alumnos, char *escala_alum);
void intercambiarInt(int i, int j, int *arr);
void intercambiarChar(int i, int j, char *arr);
void intercambiarDouble(int i, int j, double *arr);
void leerCursos(int &cant_cursos, int *curso, double *creditos,
        const char *nombCurso);
void ordernarCursos(int cant_cursos, int *curso, double *creditos);
void leerEscalas(int &cant_escalas, int *ciclo, char *escala, double *costo,
        const char *nombEscalas);
void leerMatricula(int ciclo_usuario, int cant_alumnos, int *alumnos,
        char *escala_alum, int *num_cursos, double *total_creditos,
        int cant_cursos, int *curso, double *creditos, int cant_escalas,
        int *ciclo, char *escala, double *costo, double *pago,
        const char *nombMatricula);
void emitirReporte(int ciclo, int cant_alumnos, int *alumnos, char *escala_alum,
        int *num_cursos, double *total_creditos, double *pago,
        const char *nombNombres, const char *nombApellidos,
        const char *nombReporte);
void imprimirEncabezado(int ciclo, ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void modificaTexto(char *cadena1, char *cadena2);
void concatenar(char *cadena1, const char *cadena2);
int strlen(char *cadena);
void copiar(char *destino, const char *fuente);
int buscarEscalas(int cant_escalas, int ciclo_matri,
        char escala_alum, int *ciclo, char *escala);
int buscar(int codigo, int cant, int *arr);


#endif /* FUNCIONESAUXILIARES_H */

