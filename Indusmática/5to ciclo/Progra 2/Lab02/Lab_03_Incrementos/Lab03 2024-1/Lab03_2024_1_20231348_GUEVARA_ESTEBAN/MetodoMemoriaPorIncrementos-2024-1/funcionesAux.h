/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.h
 * Author: alulab14
 *
 * Created on 22 de abril de 2025, 06:46 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

#include <fstream>


//Lectura de Libros
void lecturaDeLibros(const char*nombreArch,char***&libros,int**&stock);
char**  lecturaLibro(ifstream &archLee);
int* lecturaStock(ifstream &archLee);
char* lecturaExacta(ifstream &archLee,char delim);
void aumentarEspacios(char***&libros,int**&stock,int&numDat,int&cap);
//Prueba de Lectura
void pruebaDeLecturaDeLibros(const char*nombreArch,char***libros,int**stock);

//Lectura Pedidos
void atencionPedidos(const char*nombreArch,char***libros,int**stock,
        int**&pedidosClientes,char***&pedidosLibros,bool**&pedidosAtendidos);
void aumentarCapClien(int **&pedidosClientes,int &numDat, int&capClien);
int buscamosCliente(int dniClien,int**pedidosClientes);
void agregarCliente(int*& cliente,int &ndClie,
                    int& capClien,int dniClien,int numPed);
void modificarCliente(int*& cliente,int &ndPed,int& capPed,int numPed);
void asignacionLibros(ifstream &archLee,bool*& atendidos,
                char**& cadLibros,int& ndLib,int& capLib,
                char ***libros,int**stock);
void aumentarCapLib(bool**&pedidosAtendidos,char***&pedidosLibros,
    int&capLibros,int numPed);
void asignamos(bool*& atendidos,char**& libros,int& ndLib,
                int& capLib,char* ptCodLib);
int buscamosLibro(char ***libros,char*ptCodLib);

// Ordenar
void ordenarPedidosClientes(int** pedidosClientes);

//Reporte final
//void reporteDeEntregaDePedidos(const char*nombreArch,
//        int**pedidosClientes,char***pedidosLibros,bool**pedidosAtendidos);

void reporteDeEntregaDePedidos(const char *nombreArch, int** pedidosClientes,
        char*** pedidosLibros, bool** pedidosAtendidos);
void impresionLinea(ofstream &archReport,int cant,char car);
void impresionPedidos(ofstream &archReport, int* pedidosCliente, bool** pedidosAtendidos,
        char***pedidosLibros);

#endif /* FUNCIONESAUX_H */

