/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 21 de septiembre de 2024, 11:10
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

void abrirArchivos(ifstream &archCanal, ifstream &archTele, ifstream &archPrefe,
        ofstream &archReporte, const char *nombreCanal, const char *nombreTele,
        const char *nombrePreferencias, const char *nombreReporte);
void leerProcesarImprimirDatos(ifstream &archCanal, ifstream &archTele, 
        ifstream &archPrefe, ofstream &archReporte);
void imprimirInfoCanal(int canal,ifstream &archCanal,ofstream &archReporte);
void leerImprimirTexto(ifstream &archCanal, ofstream &archReporte, int n,
        int opcion);
void imprimirEncabezado(ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void buscarImprimirClientes(int canal, ifstream &archTele, ifstream &archPrefe,
        ofstream &archReporte, int &cant_personas, int &dura_total,
        int &menores, int &jovenes, int &adultos);
void imprimirEstadisticas(int dura_total, int cant_personas, int menores, 
        int jovenes,int adultos, ofstream &archReporte);
void buscarImprimirInfoPersona(int dni, ifstream &archTele,
        ofstream &archReporte, int &categoria) ;
void calcularImprimirDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &duracion, ofstream &archReporte);
void imprimirHora(int hh, int min, int seg, ofstream &archReporte);
void imprimirSexo(char sexo, ofstream &archReporte);
void imprimirCompania(char compania, ofstream& archReporte);

#endif /* FUNCIONESAUXILIARES_H */

