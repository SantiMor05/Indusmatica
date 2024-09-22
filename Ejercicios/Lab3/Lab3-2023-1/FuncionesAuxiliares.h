/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 21 de septiembre de 2024, 14:03
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;


void abrirArchivos(ifstream &archCartelera, ifstream &archCli,
        ofstream &archReporte, const char *nombCartelera,
        const char* nombClientes, const char *nombReporte);
void leerProcesarImprimirDatos(ifstream &archCartelera, ifstream &archCli,
        ofstream &archReporte);
void leerImprimirPeliculas(ifstream &archCartelera, ifstream &archCli,
        ofstream &archReporte, int cod_dist);
void buscarPersonas(ifstream &archCli, int hh_ini, int min_ini, int seg_ini,
        int duracion, char alimentos, ofstream &archReporte, int cod_dist);
void imprimirHora(int hh, int min, int seg, ofstream &archReporte);
void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin,
        int min_fin, int seg_fin, int &duracion, int &hh_peli,
        int &min_peli, int &seg_peli);
void leerImprimirTexto(ifstream &archCartelera, ofstream &archReporte, int n);
void imprimirCaracter(char car, ofstream &archReporte);
void imprimirEncabezado(ofstream &archReporte);
void imprimirEncabezadoListaPersonas(ofstream &archReporte);

#endif /* FUNCIONESAUXILIARES_H */

