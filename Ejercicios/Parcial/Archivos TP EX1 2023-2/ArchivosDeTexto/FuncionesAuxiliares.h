/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 14 de octubre de 2024, 11:41
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
using namespace std;

void solicitarCiclo(int &ciclo, int &anho) ;
void procesarDatos(int ciclo, int anho, const char *nombAlumnos,
        const char *nombCursos, const char *nombEscalas,
        const char *nombMatricula, const char *nombReporte);
void imprimirReporte(int ciclo, int anho, ifstream &archAlumnos,
        ifstream &archCursos, ifstream &archEscalas, ifstream &archMatricula,
        ofstream &archReporte);
void imprimirResumen(int cont, double ingreso_total, ofstream &archReporte);
void imprimirEstadisticasAlumno(double creditos_total, double monto_total, 
        ofstream &archReporte);
void imprimirCursosMatriculados(int ciclo, int anho, double credito, int alumno,
        double &creditos_total, double &monto_total, ifstream &archMatricula,
        ifstream &archCursos, ofstream &archReporte);
void buscarImprimirCurso(int curso, double credito, double &creditos_total,
        double &monto_total, ifstream &archCursos,
        ofstream &archReporte);
void imprimirEncabezadoCursos(ofstream &archReporte);
double buscarEscala(char escala, int ciclo, int anho, ifstream &archEscalas);
void imprimirTexto(char deli, int n, ifstream &archAlumnos,
        ofstream &archReporte);
void imprimirEncabezado(int ciclo, int anho, ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);

#endif /* FUNCIONESAUXILIARES_H */

