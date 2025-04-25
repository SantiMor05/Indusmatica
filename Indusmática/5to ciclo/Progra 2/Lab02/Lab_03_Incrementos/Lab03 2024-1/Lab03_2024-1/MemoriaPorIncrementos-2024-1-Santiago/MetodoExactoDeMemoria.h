/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: santi
 *
 * Created on 24 de abril de 2025, 15:04
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

#include <fstream>
using namespace std;

void lecturaDeLibros(const char *nombArch, char ***&libros, int **&stock);
char **leerLibro(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char deli);
void incrementarEspacios(char ***&libros, int **&stock, int &numDat, int &cap);
void pruebaDeLecturaDeLibros(const char *nombArch, char ***libros, int **stock);
void imprimirLinea(ofstream &arch, int n, char car);
void atencionDePedidos(const char *nombArch, char ***libros, int **stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos);
void insertarPedidos(ifstream &arch, int pedido, char ***libros, int **stock, 
        char ***&pedidosLibros, bool **&pedidosAtendidos, int &numDat, int &cap,
        int *numlibros, int *caplibros);
void verificarStock(char *codigo, char ***libros, int **stock, 
        bool *pedidosAtendidos, int pos);
char *asignarCadena(char *codigo);
void incrementarEspacios(char **&pedidosLibros,bool *&atendidos, int &numlibros,
                    int &caplibros);
void incrementarEspacios(char ***&pedidosLibros, bool **&pedidosAtendidos, 
        int &numDat, int &cap,int pedido);
void insertarPedidoCliente(int *&pedidosClientes, int pedido, int &nd, 
                int &cap);
void incrementarEspacios(int *&pedidosClientes, int &nd, int &cap);
void aumentarEspaciosClientes(int **&pedidosClientes, int &numDat, 
        int &cap);
int buscarCliente(int dni,int **pedidosClientes);
void ordenarPedidosClientes(int **pedidosClientes);
void qsort(int **pedidosClientes,int izq, int der);
void cambiar(int *&a, int *&b);
int comparar(int *pedidoI, int *pedidoD);
void reporteDeEntregaDePedidos(const char *nombArch, int **pedidosClientes,
            char ***pedidoLibros,bool **pedidosAtendidos);
void imprimirPedidos(ofstream &arch, int *pedidosClientes, char ***pedidoLibros, 
        bool **pedidosAtendidos);

#endif /* METODOEXACTODEMEMORIA_H */
