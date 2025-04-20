/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: kenyi
 *
 * Created on 19 de abril de 2025, 01:12 PM
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H
void lecturaDeLibros(const char*nombArch, char ***&libros, int **&stock);


char **leerLibro(ifstream &archLib);

int *leerStock(ifstream &archLib);

char *leerExacto(ifstream &archLib, int max, char del);

void pruebaDeLecturaDeLibros(const char*nombArch, char ***libros, int **stock);

void imprimirLibroPrueba(ofstream &arch, char**lib);

void atencionDePedidos(const char*nombArch, char ***libros, int **stock,
        int **&pedidosClientes, char ***&pedidosLibros,
        bool **&pedidosAtendidos);

int buscarCliente(int **buffPedCli, int dni);

void insertarPedido(int *buffPedCli, int numPed);

void agregarCliente(int *&buffPedCli, int dni, int &cantCli, int &posC);

void leerPedido(ifstream &archPed, char ***libros, int **stock, char **&buffPedLib,
        bool *&buffPedAten, int &cant);

int buscarLibro(char ***libros, char *codLib);

void modificarAtendido(int *stock, bool &buffPedAten);

void cargarArreglos(int **&pedidosClientes, char ***&pedidosLibros,
        bool **&pedidosAtendidos, int **buffPedCli, char ***buffPedLib,
        bool **buffPedAten, int cantPed, int cantCli, int *cantPorPedido);

void cargaClienteInterno(int *pedidosClientes, int *buffPedCli);

void cargaPedidoInterno(char **pedidosLibros, bool *pedidosAtendidos,
        char **buffPedLib, bool *buffPedAten, int cant);

void reporteDeEntregaDePedidos(const char*nombArch, int **pedidosClientes,
        char ***pedidosLibros, bool **pedidosAtendidos);

void imprimirLinea(ofstream &archRep, int n, char c);

void imprimirTitulo(ofstream &archRep);

void imprimirEncabezado(ofstream &archRep);

void imprimirPed(ofstream &arch,char **pedidosLibros, bool *pedidosAtendidos);
#endif /* METODOEXACTODEMEMORIA_H */
