/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones auxiliares.h
 * Author: alulab14
 *
 * Created on 23 de abril de 2025, 07:11 PM
 */

#ifndef FUNCIONES_AUXILIARES_H
#define FUNCIONES_AUXILIARES_H

void leer_conductores(int *&dni, char **&conductor, char ***&placas);
char* leer_cadena(ifstream &arch,char flag='\n', int n=200);
void incrementar_espacios(int *&dni, char **&conductor, char ***&placas, int &NumDat, int &cap);
void incrementar_placas(char **&placas,int &nd, int &capi);
void imprimir_conductores(int *dni, char **conductor, char ***placas);
void imprimir_linea(ofstream &arch,int n,char c);
void imprimir_placas(ofstream &arch,char **placas);
void leer_multas(double *&multas);
void imprimir_multas(double *multas);
void leer_infracciones_cometidas(int *dni, char ***placas, double *multas, double ***&montoXmultas);
int buscar_conductor(int DNI, int *dni);
void llenar_montos(double **montoXmultas, char *placa,char **placas, int codMulta, double *multas);
int buscar_placa(char *placa, char **placas);
void espacios_exacto(double **&montoXmultas, char **placas);
int buscar_multa(int codMulta, double *multas);
void imprimir_infracciones_cometidas(int *dni, char **conductor, char ***placas, double ***montoXmultas);
void imprimir_placas_infracciones(ofstream &arch,char **placas, double **montoXmultas);

#endif /* FUNCIONES_AUXILIARES_H */
