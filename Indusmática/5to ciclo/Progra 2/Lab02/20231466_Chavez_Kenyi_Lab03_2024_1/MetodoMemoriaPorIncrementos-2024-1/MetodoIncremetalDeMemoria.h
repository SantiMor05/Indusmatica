/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   MetodoIncremetalDeMemoria.h
 * Author: kenyi
 *
 * Created on 24 de abril de 2025, 04:18 PM
 */

#ifndef METODOINCREMETALDEMEMORIA_H
#define METODOINCREMETALDEMEMORIA_H

void lecturaDeLibros(const char*nombArch, char ***&libros, int **&stock);

char *leeExacto(ifstream &archLibros, int max, char del);
char **leerLibro(ifstream &archLibros);

void aumentarEspacioLibro(char ***&libros, int **&stock, int &nd, int &cap);

int *leerStock(ifstream &archLibros);
void aumentarEspacioCliente(int **&pedidosClientes, int &numCli, int &capPedCli);

int buscarDni(int **pedidosClientes, int dni);

void agregarCliente(int **pedidosClientes, int &numCli, int &posC, int dni,
        int *numPedCli, int *capPedCli);

void incrementarEspacioClienteInterno(int *&pedidosClientes,
        int &capPedCli, int &numPedCli);

void agregarPedido(int *&pedidosClientes, int numPed, int &numPedCli, int &capPedCli);

void aumentarEspacioPedidos(char ***&pedidosLibros, bool **&pedidosAtendidos,
        int &capLib,int numLibro);

void aumentarEspacioPedidosInterno(char **&pedidosLibros,
                    bool *&pedidosAtendidos, int &nd,int &cap);

void leerPedidos(char ***&pedidosLibros, bool **&pedidosAtendidos,
        int &numLibro, ifstream &archPed, int numPed, int &capLib,
        int **stock,char ***libros);

int buscarLibro(char ***libro, char *cod);

bool verificarStock(int *stock);

void imprimirLinea(int n, char c, ofstream &archRep);

void imprimirPedidos(bool *pedidosAtendidos, char **pedidosClientes,
        ofstream &archRep) ;


void pruebaDeLecturaDeLibros(const char*nombArch, char ***libros, int **stock);

void atencionDePedidos(const char*nombArch, char ***libros, int **stock,
        int **&pedidosClientes, char ***&pedidosLibros, bool**&pedidosAtendidos);

void ordenarPedidosClientes(int **&pedidosClientes);
void reporteDeEntregaDePedidos(const char*nombArch, int **pedidosClientes,
        char ***pedidosLibros, bool**pedidosAtendidos);

#endif /* METODOINCREMETALDEMEMORIA_H */
