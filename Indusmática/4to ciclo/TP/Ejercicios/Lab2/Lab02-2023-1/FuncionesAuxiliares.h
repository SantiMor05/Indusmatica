/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 14 de septiembre de 2024, 14:54
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
#define MAX_CAR 120

using namespace std;

void abrirArchivos(ifstream &archDatos, ofstream &archReporte,
        const char * nombreDatos, const char *nombreReporte);
void leerProcesarImprimirDatos(ifstream &archDatos, ofstream &archReporte);
void imprimirEncabezado(int dd_doce, int mm_doce, int aa_doce, int dd_alum,
        int mm_alum, int aa_alum, ofstream &archReporte);
void imprimirFecha(int dd, int mm, int aa, ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
int calcularFecha(int dd, int mm, int aa);
void imprimirDatosUsuario(int carne, char usuario, char calificacion,
        ofstream &archReporte);
void imprimirDatosLibro(int codigo, int dd, int mm, int aa,
        double multa, ofstream &archReporte);
void hallarMayorDeuda(double &mayor_deuda_docente, double &mayor_deuda_estudiante,
        int &carne_estudiante, int &carne_docente, int carne,
        double multa_total, char usuario, int &primer_estudiante, 
        int &primer_docente);
void imprimirResumen(double mayor_deuda_docente, double mayor_deuda_estudiante,
        int carne_estudiante, int carne_docente,
        ofstream &archReporte);


#endif /* FUNCIONESAUXILIARES_H */

