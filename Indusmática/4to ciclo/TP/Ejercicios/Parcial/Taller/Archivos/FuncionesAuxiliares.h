/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 11 de octubre de 2024, 13:40
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>

using namespace std;

void procesarDatos(const char *nombProductos, const char *nombAlmacen, 
        const char *nombStock,const char *nombTransa, const char *nombReporte);
void imprimirEncabezado(ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void procesarInformacion(ifstream &archAlmacen, ifstream &archProductos, 
        ifstream &archStock, ifstream &archTransa, ofstream &archReporte);
void buscarImprimirStock(int producto, int &suma, int &errores, 
        ifstream &archAlmacen, ifstream &archStock, ifstream &archTransa,  
        ofstream &archReporte);
void imprimirStockFinal(int stockFinal, int &errores, ofstream &archReporte);
void buscarTransacciones(int producto, int almacen, int &operaciones, 
        ifstream &archTransa, ofstream &archReporte);
void imprimirEstadisticasAlmacen(int ingresos, int salidas, int recibidos, 
        int enviados, ofstream &archReporte);
void imprimirTransaccion(char tipo, int destino, int almacen, int cod_alma,
        int &opcion, ofstream &archReporte);
void imprimirFechaHora(int dd,int mm,int aa,char sep, ofstream &archReporte);
void imprimirEncabezadoTransacciones(ofstream &archReporte);
void buscarImprimirAlmacen(int almacen, ifstream &archAlmacen, 
                    ofstream &archReporte);
void leerImprimirTexto(char deli, int n, ifstream &archProductos, 
        ofstream &archReporte);


#endif /* FUNCIONESAUXILIARES_H */

