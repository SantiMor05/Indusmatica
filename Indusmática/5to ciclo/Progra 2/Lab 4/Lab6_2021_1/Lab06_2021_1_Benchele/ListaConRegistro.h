/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaConRegistro.h
 * Author: Lenovo
 *
 * Created on 9 de mayo de 2025, 12:03 AM
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H

#include <fstream>
using namespace std;

void *leeReg(ifstream &arch);
int cmpReg(const void*a, const void*b);
void imprimeReg(ofstream &arch, void*anterior, void*actual);


void imprimirEncabezado(ofstream &arch, int fecha);
void sacarDiaMesAnio(int &dia, int &mes, int &anio, int fecha);
void imprimirRegistro(ofstream &arch, void **reg);
char* buscarConductor(ifstream &arch, int licencia);

#endif /* LISTACONREGISTRO_H */
