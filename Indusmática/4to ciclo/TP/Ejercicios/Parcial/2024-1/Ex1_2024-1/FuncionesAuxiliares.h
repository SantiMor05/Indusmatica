/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 10 de octubre de 2024, 21:46
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
using namespace std;

void procesarDatos(const char *nombPacientes, const char *nombCitas,
        const char *nombMedicos, const char *nombMedicinas,
        const char *nombReporte);
void procesarCitas(int dni, double descuento, double &suma, ifstream &archCitas,
        ifstream &archMedicinas, ifstream &archMedicos, ofstream &archReporte);
void buscarImprimirMedico(int medico, double &tarifa, ifstream &archMedicos, 
        ofstream &archReporte);
void imprimirFechaHora(int dd, int mm, int  aa, char deli, 
        ofstream &archReporte);
void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &duracion, int &hh_dura, int &min_dura,
        int &seg_dura);
void imprimirEncabezadoCita(ofstream &archReporte);
void leerImprimirTexto(int n, char deli, ifstream &archEntrada,
        ofstream &archReporte);
void imprimirEncabezado(ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void imprimirEncabezadoMedicinas(ofstream &archReporte);
void buscarImprimirMedicamento(int medicamento, int cantidad, double descuento,
        double &pago_medicamentos, ifstream &archMedicinas, 
        ofstream &archReporte);
void imprimirEstadisticasFinalesCita(double pago_medicamentos, double monto, 
                    ofstream &archReporte);


#endif /* FUNCIONESAUXILIARES_H */

