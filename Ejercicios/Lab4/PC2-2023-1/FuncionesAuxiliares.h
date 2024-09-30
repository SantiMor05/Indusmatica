/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 26 de septiembre de 2024, 23:48
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H


#include <fstream>
using namespace std;

void leerLibros(int *cod_libro, double *precio_libro, int &cant_libros, 
        const char *nombLibros);
void leerAutores(int *cod_autor, int *libro, double *porcentaje, 
        int &cant_autores, const char *nombAutores);
void pedirFechas(int &fecha_ini, int &fecha_fin);
void emitirReporte(int *cod_libro, int *cod_autor, int *libro, 
        double *precio_libro, double *porcentaje, int cant_libros, 
        int cant_autores, int fecha_ini, int fecha_fin, 
        const char *nombReporte, const char *nombVentas);
void imprimirEncabezado(int fecha_ini, int fecha_fin, ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archSalida);
void formatoFecha(int &dd,int &mm,int &aa,int fecha);
int calcularFecha(int dd, int mm, int aa);
int buscarLibro(int codigo, int *cod_libro, int cant_libros) ;
void imprimirEncabezadoLibro(int contador, int codigo, ofstream &archReporte) ;
void imprimiRegalias(int codigo, double monto, int cant_autores, int *cod_autor,
        int *libro, double *porcentaje, ofstream &archReporte);

#endif /* FUNCIONESAUXILIARES_H */

