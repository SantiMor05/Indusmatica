/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 13 de septiembre de 2024, 23:27
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
#define MAX_CAR 120

using namespace std;

void abrirArchivos(ifstream &archDatos, ofstream &archReporte, 
        const char *nombreDatos, const char *nombreReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void imprimirEncabezado(ofstream &archReporte);
void leerProcesarImprimirDatos(ifstream &archDatos, ofstream &archReporte);
void calcularMaxMinDuracion(int &min_duracion, int &max_duracion);
void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &hh_dura, int &min_dura, int &seg_dura,
        int &duracion, double &duracion_horas);
void imprimirTextoConDelimitador(int dd, int mm, int aa, char car,
        ofstream &archReporte, int espacios_separacion);
void imprimirEstadisticas(double total, int cant_procesados, int cant_archivo,
        ofstream &archReporte);

#endif /* FUNCIONESAUXILIARES_H */

