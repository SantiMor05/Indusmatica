/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 13 de octubre de 2024, 13:45
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
using namespace std;

void leerStock(int &cant_prods, int *almacen, int *producto, int *stock, 
        const char *nombStock);
void probarDatos(int cant_prods, int *almacen, int *producto, int *stock, 
        const char *nombPrueba);
void imprimirCaracter(char car, int  n, ofstream &archSalida);
void intercambiarInt(int i,int j,int *arr);
void imprimirEncabezado(int fecha_ini, int fecha_fin, ofstream &archReporte);
void descalcularFecha(int &dd,int &mm,int &aa,int fecha);
int calcularFecha(int dd, int mm, int aa);
void saltarTexto(char deli, ifstream &archTransa);
int buscarPosicion(int cod_alma, int cod_prod, int cant_prods, int *almacen,
        int *producto) ;
void imprimirEncabezadoProducto(int cod_prod, ofstream &archReporte);
void solicitarFechas(int &fecha_ini, int &fecha_fin);
void actualizarDatos(int fecha_ini, int fecha_fin, int cant_prods, int *almacen,
        int *producto, int *stock, int *salidas, int *ingresos, int *enviados,
        int *recibidos, const char *nombTransa) ;
void calcularStockFinal(int cant_prods, int *salidas, int *ingresos, 
        int *enviados, int *recibidos, int *stock_final, int *stock);
void ordenar(int cant_prods, int *almacen, int *producto, int *stock, 
        int *salidas, int *ingresos,int *enviados, int *recibidos, 
        int *stock_final);
void emitirReporte(int fecha_ini,int fecha_fin, int cant_prods, int *almacen, 
        int *producto, int *stock, int *salidas, int *ingresos,int *enviados, 
        int *recibidos, int *stock_final, const char *nombReporte);
void eliminar(int &cant_prods, int *almacen, int *producto, int *stock, 
        int *salidas, int *ingresos,int *enviados, int *recibidos, 
        int *stock_final);


#endif /* FUNCIONESAUXILIARES_H */

