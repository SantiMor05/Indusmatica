/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 17 de noviembre de 2024, 12:18
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
#include "Cliente.h"
#include "Fecha.h"
#include "Libro.h"
#include "Venta.h"

using namespace std;

void leerDatosClientes(struct Cliente *arrClientes, int &num_cientes,
        const char *nombClientes);
void leerCliente(struct Cliente &cliente, ifstream &archClientes);
char *leerCadenaExacta(ifstream &archEntrada, const char delimitador);
void leerDatosLibros(struct Libro *arrLibros, int &num_libros,
        const char *nombLibros);
void leerLibro(struct Libro &libro, ifstream &archLibros) ;
void leerVentas(struct Libro *arrLibros, int num_libros,
        const char *nombVentas);
int buscarLibro(char *libro, int num_libros, struct Libro *arrLibros);
void determinarRankings(struct Libro *arrLibros, int num_libros);
int calcularRanking(double promedio);
void ordenarLibros(struct Libro *arrLibros, int num_libros);
void intercambiar(struct Libro &libro1, struct Libro &libro2);
void emitirReporte(struct Cliente *arrClientes, int num_clientes,
        struct Libro *arrLibros, int num_libros, const char *nombReporte);
void imprimirVentas(ofstream &archReporte, struct Venta *ventas,
        int cant_ventas, struct Cliente *arrClientes, int num_clientes);
int buscarCliente(int dni, int num_clientes, struct Cliente *arrClientes);
void imprimirEncabezado(ofstream &archReporte);
void imprimirCaracter(ofstream &archReporte, char car);

#endif /* FUNCIONESAUXILIARES_H */

