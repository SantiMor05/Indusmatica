/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 24 de noviembre de 2024, 11:37
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
#include "Cliente.h"
#include "Fecha.h"
#include "Libro.h"
#include "Venta.h"

using namespace std;

void crearBinarioClientes(const char *nombClientes, const char *nombBinario);
void crearBinarioLibros(const char *nombLibros, const char *nombBinario);
void completarDatos(const char *nombVentas, const char *nombCli,
        const char *nombLibros) ;
int buscarLibro(char *codigo, int tamRegL, int numRegL, fstream &archLibros);
int buscarDni(int dni, int tamRegC, int numRegC, ifstream &archClientes);
void datosArchivoLibros(int tamReg, int &numReg, fstream &archLibros);
void datosArchivoCliente(int tamReg, int &numReg, ifstream &archClientes);
void determinarRankig(const char *nombBin);
int calcularRanking(int promedio);
void ordernar(const char *nombBin);
void emitirReporte(const char *nombBin, const char *nombReporte);
void imprimirEncabezado(ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void datosArchivoLibrosLectura(int tamReg, int &numReg, ifstream &archLibros);

#endif /* FUNCIONESAUXILIARES_H */

