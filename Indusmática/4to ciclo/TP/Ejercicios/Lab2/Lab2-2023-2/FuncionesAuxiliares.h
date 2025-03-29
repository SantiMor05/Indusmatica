/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 14 de septiembre de 2024, 12:40
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
#define MAX_CAR 130
#define MAX_CAR_NOMBRE 40

using namespace std;

void abrirArchivos(ifstream &archDatos, ofstream &archReporte, 
        const char *nombreDatos, const char *nombreReporte);
void imprimirEmcabezado(ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void leerImprimirTexto(ifstream &archDatos, ofstream &archReporte) ;
void imprimirSexo(char sexo, ofstream &archReporte);
void imprimirCategoria(int aa, ofstream &archReporte, char &categoria);
void imprimirCompania(char compania, ofstream &archReporte);
void procesarCanales(ifstream &archDatos, ofstream &archReporte, 
        char categoria,int &tiempo_total, int &cont_menores_adultos);
void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &hh_dura, int &min_dura, int &seg_dura,
        int &duracion);
void imprimirHora(int hh_ini, int min_ini, int seg_ini,ofstream &archReporte);
void leerProcesarImprimirDatos(ifstream &archDatos, ofstream &archReporte);
void imprimirEstadisticas(int cant_televidentes,int cant_mujeres,int cant_muj_tv,
            int tiempo_total,int cont_menores_adultos, ofstream &archReporte);

#endif /* FUNCIONESAUXILIARES_H */

