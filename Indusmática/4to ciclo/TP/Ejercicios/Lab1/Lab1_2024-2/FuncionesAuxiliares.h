/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 12 de septiembre de 2024, 21:52
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

#define MAX_CAR 150
#define MAX_CAR_NOMBRE 40

using namespace std;

void abrirArchivos(ifstream &archDatos, ofstream &archReporte, 
        const char *nombreDatos,  const char *nombreReporte);
void imprimirEncabezado(ifstream &archDatos, ofstream &archReporte);
void imprimirCaracter(int n, char car,ofstream &archReporte);
void leerProcesarImprimirReporte(ifstream &archDatos, ofstream &archReporte);
void imprimirDatosRepartidor(ifstream &archDatos,ofstream &archReporte, 
        int dni);
void leerImprimirTexto(ifstream &archDatos, ofstream &archReporte);
void calcularPuntos(double x1, double y1, double &x2, double &y2, 
        double distancia, int grados, int min_grados, int seg_grados);
void calcularPago(double distancia, double &pago, double &pago_acumulado);
void calcularDistancia(double &distancia, double &dist_acumulado, int hh_part,
        int min_part, int seg_part, int hh_llega, int min_llega, int seg_llega,
        double velocidad);
void imprimirEncabezadoDatos(ofstream &archReporte);
void imprimirTramo(int i, int hh_part, int min_part, int seg_part, int hh_llega,
        int min_llega, int seg_llega, double velocidad, double distancia,
        double x1, double y1, double x2, double y2, double dist_acumulado,
        double pago, ofstream &archReporte);
void calcularRetorno(double &distancia, double x1, double y1,
        double &dist_acumulado, double velocidad, int &hh_part, int &min_part,
        int &seg_part, int &hh_llega, int &min_llega, int &seg_llega);
void calcularMenorMayor(int &dni_menor, int &dni_mayor, double &dist_mayor, 
        double &dist_menor, double dist_acumulado, int dni, int cont );
void imprimirResumen(int dni_mayor, double dist_mayor, double dist_menor, 
        int dni_menor, ofstream &archReporte);


#endif /* FUNCIONESAUXILIARES_H */

