/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones auxiliares.h
 * Author: alulab14
 *
 * Created on 23 de abril de 2025, 10:58 AM
 */

#ifndef FUNCIONES_AUXILIARES_H
#define FUNCIONES_AUXILIARES_H

void cargar_vemtas(char **&ventasLibroCodigo,int **&ventasDNIFechaPuntaje,const char *nomArch);
char* leer_cadena(ifstream &arch,char flag='\n');
void incrementar_espacios(char **&ventasLibroCodigo, int **&ventasDNIFechaPuntaje,int &numDat, int &cap);
int llenar_fecha(int dd, int mm, int aa);
void llenarInt(int *ventasDNIFechaPuntaje,int dni, int fecha, int puntaje);
void pruebaCargaVentas(char **ventasLibroCodigo,int **ventasDNIFechaPuntaje,const char *nomArch);
void cargaLibros(char ***&libro, const char* nomArch);
void llenar_char(char **libro, char *codigo, char *nombre, char*autor);
void incrementar_espacios(char ***&libro,int &numDat,int &cap);
void pruebaCargaLibros(char ***libro, const char* nomArch);

#endif /* FUNCIONES_AUXILIARES_H */

