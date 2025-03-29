/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 14 de octubre de 2024, 12:54
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

void leerAlumnos(int &cant_alumnos, int *alumno, char *escala, 
        const char *nombAlumnos);
void leerCursos(int &cant_cursos, int *curso, double *creditos, 
        const char *nombCursos);
void leerEscalas(int &cant_escalas, int *anho, int *ciclo, char *escala_escala, 
        double *costo, const char *nombEscalas);
void reportePrueba(int &cant_escalas, int *anho, int *ciclo, char *escala_escala, 
        double *costo, const char *nomReporte);
void imprimirCaracter(char car, int n, ofstream &archReporte);
void saltarTexto(char deli, ifstream &archEntrada);
int buscar(int codigo, int n, int *arr);
void imprimirEncabezado(ofstream &archReporte);
void intercammbiarInt(int i,int j,int *arr);
void intercammbiarChar(int i,int j,char *arr);
void intercammbiarDouble(int i,int j,double *arr);
int buscarEscala(int aa, int semestre, char escala_alum, int cant_escalas, 
                int *anho, int *ciclo, char *escala_escala);
void actualizarDatos(int cant_alumnos, int *alumno, char *escala, 
        int cant_cursos, int *curso, double *creditos, int cant_escalas, 
        int *anho, int *ciclo, char *escala_escala, double *costo, 
        int *cant_alumn_escalas, double *cant_creditos, 
        double *total_ingresos, const char *nombMatricula);
void ordenar(int cant_escalas, int *anho, int *ciclo, char *escala_escala, 
        double *costo, int *cant_alumn_escalas, double *cant_creditos, 
        double *total_ingresos);
void imprimirReporte(int cant_escalas, int *anho, int *ciclo, char *escala_escala, 
        double *costo, int *cant_alumn_escalas, double *cant_creditos, 
        double *total_ingresos, const char *nombReporte);

#endif /* FUNCIONESAUXILIARES_H */

