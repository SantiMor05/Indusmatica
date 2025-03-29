/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: kenyi
 *
 * Created on 24 de noviembre de 2024, 02:17 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;

void leerClienteBin(const char*nombCliente, const char*nombClienteBin);

void leerClientes(struct Cliente &cliente, ifstream &archCliente);

void leerLibrosBin(const char*nombLibro, const char*nombLibroBin);

void leerLibros(struct Libro &libro, ifstream &archLibro);

void leerVentas(const char*nombVentas, const char*nombClienteBin,
        const char*nombLibroBin);

int buscarLibro(char *codigo, int tamRegL, int numRegL, fstream &archBinLibro);

int buscarCliente(int dni, int tamRegC, int numRegC, ifstream &archBinCliente);

void datosArchivoFstream(int tamReg, int &numReg, fstream &archBin);

void datosArchivoIstream(int tamReg, int &numReg, ifstream &archBin);

void determinarRanking(const char*nombLibroBin);

int calcularRanking(double promedio);

void imprimirLinea(char c, int n, ofstream &archReporte);

void imprimirEncabezado(ofstream &archReporte);

void ordenarBin(const char*nombLibroBin);

void emitirReporte(const char*nombLibroBin, const char*nombReporte);
#endif /* FUNCIONESAUXILIARES_H */

