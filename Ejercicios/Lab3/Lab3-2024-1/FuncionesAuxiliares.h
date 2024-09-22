/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 20 de septiembre de 2024, 22:22
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

void abrirArchivos(ifstream &archCitas, ifstream &archMed,
        ofstream &archReporte, const char *nombreCitas,
        const char *nombreMedicos, const char *nombreReporte);
void leerProcesarImpirmirDatos(ifstream &archCitas, ifstream &archMed,
        ofstream &archReporte);
void buscarMedico(int cod_med, ifstream &archMed, ofstream &archReporte,
        double &tarifa);
void leerImprimirNombre(ifstream &archMed, ofstream &archReporte,int opcion);
void imprimirFechaHora(int dd,int mm,int aa,char deli, ofstream &archReporte);
void imprimirEncabezado(ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, double &duracion, int &hh_dura,
        int &min_dura, int &seg_dura);
void imprimirEstadisticas(int dni_mayor, double pago_mayor, double total, 
        ofstream &archReporte);

#endif /* FUNCIONESAUXILIARES_H */

