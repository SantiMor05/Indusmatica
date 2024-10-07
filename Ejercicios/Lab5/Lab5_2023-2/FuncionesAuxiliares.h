/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 5 de octubre de 2024, 15:00
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

void actualizarDatos(int cant_alumnos,int *cod_alum, int *escala_alum, 
        double *total_creditos, int *cant_cursos_matri, double *pago,
        int cant_cursos, int *cod_curso, double *credito_curso,
        int *alum_matriculados, double *total_ingresos, int cant_escalas, 
        double *escala, const char *nombMatricula);
void leerAlumnos(int &cant_alumnos,int *cod_alum, int *escala_alum, 
        const char *nombAlumnos);
void leerCursos(int &cant_cursos, int *cod_curso, double *credito_curso, 
        const char *nombCursos);
void ordenarAlumnos(int cant_alumnos,int *cod_alum, int *escala_alum, 
        double *total_creditos, int *cant_cursos_matri, double *pago);
void imprimirReporte(int cant_alumnos, int *cod_alum, int *escala_alum, 
        double *total_creditos, int *cant_cursos_matri, double *pago, 
        int cant_cursos, int *cod_curso, double *credito_curso, 
            int *alum_matriculados, double *total_ingresos, 
        const char *nombReporte);
void imprimirEncabezadoAlumnos(ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void ordenarCursos(int cant_cursos, int *cod_curso, double *credito_curso, 
            int *alum_matriculados, double *total_ingresos);
void intercambiarDouble(int i,int j,double *arr);
void intercambiarInt(int i, int j, int *arr);
int buscarDato(int codigo, int cant, int *cod);
void leerEscalas(int &cant_escalas, double *escala, const char *nombEscalas);
void saltarTexto(ifstream &archAlumnos);
void imprimirEncabezadoCursos(ofstream &archReporte);

#endif /* FUNCIONESAUXILIARES_H */

