/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: kenyi
 *
 * Created on 24 de noviembre de 2024, 05:54 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;
void leerArticulosBin(const char*nombArch, const char*nombArchBin);

void leerArticulo(struct Articulo &articulo, ifstream &archArticulo);

void leerVendedoresBin(const char*nombArch, const char*nombArchBin);

void leerVendedores(struct Vendedor &vendedor, ifstream &archVendedores);

void procesarVentas(const char*nombVentas, const char*nombArticuloBin,
        const char*nombVendedorBin);

int buscarArticulo(char *codigo, int tamRegA, int numRegA,
        fstream &archArticuloBin);

int buscarVendedor(int codigoVendedor, int tamRegV, int numRegV,
        fstream &archVendedoresBin);

void corregirVendedores(const char*nombVendedorBin);

void ordenarVendedores(const char*nombVendedorBin);

void emitirReporte(const char*nombReporte, const char*nombArticuloBin,
        const char*nombVendedorBin);

void imprimirLinea(char c, int n, ofstream &archReporte);

void datosArchivoIfstream(int tamReg, int &numReg, ifstream &archBin);

void datosArchivoFstream(int tamReg, int &numReg, fstream &archBin);
#endif /* FUNCIONESAUXILIARES_H */

