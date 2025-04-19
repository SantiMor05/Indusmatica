/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: kenyi
 *
 * Created on 18 de abril de 2025, 08:02 PM
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void lecturaDeProductos(const char*nombArch, char ***&productos, int *&stock,
        double *&precios);


char **leerProd(ifstream &archProd);

char *leerCadenaExacto(ifstream &archProd, int max, char del);

void pruebaDeLecturaDeProductos(const char*nombArch, char ***productos,
        int *stock, double *precios);

void imprimirProd(ofstream &archRep, char **prod);

void lecturaDePedidos(const char*nombArch, int *&fechaPedidos,
        char ***&codigoPedidos, int ***&dniCantPedidos);

int juntarFecha(int dd, int mm, int aa);

int buscarFecha(int *buffFecha, int fecha, int cantF);

void agregarDato(int &buffFecha, char **&buffCodPed, int **&buffDni, int fecha,
        int &cantF, int &posF);

void insertarPedido(char **buffCodPed, int **buffDni, int dni, int cant,
        char *codProd, int &cantPorPed);

void cargarArreglos(int *&fechaPedidos, char ***&codigoPedidos,
        int ***&dniCantPedidos, int *buffFecha, char ***buffCodPed,
        int ***buffDni, int &cantF, int *cantPorPed);


void cargarCodYDni(char **codigoPedidos, int **dniCantPedidos, char **buffCodPed,
        int **buffDni, int cant);

void pruebaDeLecturaDePedidos(const char*nombArch, int *fechaPedidos,
        char ***codigoPedidos, int ***dniCantPedidos);


void imprimirPruebaPorFecha(ofstream &archRep,
        char **codigoPedidos, int **dniCantPedidos);

void reporteDeEnvioDePedidos(const char*nombArch, char ***productos,
        int *stock, double *precios, int *fechaPedidos,
        char ***codigoPedidos, int ***dniCantPedidos);

void imprimirDetalles(ofstream &archRep, char **codigoPedidos,
        int **dniCantPedidos, char ***productos, double *precios,
        int *stock,double &totalIng,double &totalPer);


int buscarProducto(char *codigoPedidos,char ***productos);

void imprimirFecha(ofstream &archRep, int fecha);

void imprimirTitulo(ofstream &archRep);

void imprimirLinea(ofstream &archRep, int n, char c);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */
