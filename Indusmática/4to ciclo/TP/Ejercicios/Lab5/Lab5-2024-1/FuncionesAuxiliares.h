/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 5 de octubre de 2024, 11:46
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

void leerMedicos(int &cant_medicos, int *cod_med, double *tarifa, 
        const char *nombMedicos);
void leerMedicinas(int &cant_medicinas, int *cod_medicina, double *precio, 
            const char * nombMedicinas);
void imprimirReportePrueba(int cant_medicos, int cant_medicinas, int *cod_med, 
        int *cod_medicina, double *tarifa,double *precio, 
        const char *nombReporte);
void imprimirCaracter(char car, int n, ofstream &archReporte);
void saltarTexto(char deli, ifstream &archMedicos);
void actualizarDatos(int cant_medicos, int cant_medicinas, int *cod_med,
        int *cod_medicina, double *tarifa, double *precio, double *monto_cita,
        int *cant_pacientes, int *paciente_medicina, double *ingreso_medicina,
        int *unidades, double *ingreso_sin, double *descuentos_medi, 
        const char *nombCitas);
double calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin);
int buscarPos(int cod, int cant, int *codigo);
void imprimirEncabezadoMedicos(ofstream &archReporte);
void imprimirEncabezadoMedicinas(ofstream &archReporte);
void emitirReporte(int cant_medicos, int cant_medicinas, int *cod_med,
        int *cod_medicina, double *tarifa, double *precio, double *monto_cita,
        int *cant_pacientes, int *paciente_medicina, double *ingreso_medicina,
        int *unidades, double *ingreso_sin, double *descuentos_medi,
        const char *nombReporte, double &promedio, int opcion);
void borrarMenoresPromedio(int &cant_medicos, int *cod_med, double *tarifa,
        double *monto_cita, double *ingreso_medicina, int *cant_pacientes, 
        int *paciente_medicina, double promedio);


#endif /* FUNCIONESAUXILIARES_H */

