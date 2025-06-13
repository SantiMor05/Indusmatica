/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: santi
 *
 * Created on 19 de abril de 2025, 18:52
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

#include <fstream>
using namespace std;

void lecturaDeLibros(const char *nomArch, char ***&libros, int **&stock);
int *leerStock(ifstream &arch);
char **leerLibro(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char deli);
void pruebaDeLecturaDeLibros(const char *nomArch, char ***libros, int **stock);
void imprimirRegistroLibro(ofstream &arch, char **libro, int *stock);
void imprimirCaracter(ofstream &arch, int n, char car);

void atencionDePedidos(const char *nomArch, char ***libros, int **stock,
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos);
void crearEspaciosExactos(int **buffClientes, char ***buffLibros, 
        bool **buffAtendidos, int numDat, int ** &pedidosClientes, 
        char ***&pedidosLibros, bool **&pedidosAtendidos);
void recolocarEspacios(int *&auxClientes, char **&auxLibros, bool *&auxAtendidos, 
        int *buffClientes, char **buffLibros, bool *buffAtendidos);
void agregarPedido(int pedido, char *cod, char ***libros, int **stock,
        int *buffClientes, char **buffLibros, bool *buffAtendidos);
char *asignarCadena(char *cod);
void inicializarCliente(int dni, int *cliente);
int buscarCliente(int **clientes, int numDat, int dni);
void reporteDeEntregaDePedidos(const char *nomArch,int **pedidosClientes,
            char *** pedidosLibros, bool **pedidosAtendidos);
void imprimirEstado(ofstream &arch, int *pedido, char **pedidosLibros, 
        bool *pedidosAtendidos);

#endif /* METODOEXACTODEMEMORIA_H */

