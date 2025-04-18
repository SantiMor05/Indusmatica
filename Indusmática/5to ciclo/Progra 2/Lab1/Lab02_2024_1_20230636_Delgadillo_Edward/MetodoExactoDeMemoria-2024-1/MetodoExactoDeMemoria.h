/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: 00123
 *
 * Created on 17 de abril de 2025, 10:37 AM
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

#include <fstream>
using namespace std;


void lecturaDeLibros(const char*nombArch,char***&libros,int**&stock);
void apertura(bool abierto,const char*nombArch);
char**leerLibro(ifstream &arch);
char*leerCadena(ifstream &arch,char deli);
int*leerStock(ifstream &arch);
void pasarInfo(char***&libros,int**&stock,char***buffLibros,int**buffStock,
        int nd);
void pruebaDeLecturaDeLibros(const char*nombArch,char***libros,int**stock);
void imprimirLibro(ofstream &arch,char**libro);
void imprimirStock(ofstream &arch,int*stock);
void atencionDePedidos(const char*nombArch,char***libros,int**stock,
        int**&pedidosClientes,char***&pedidosLibros,bool**&pedidosAtendidos);
bool*contrastarPedido(char**pedido,char***libros,int**stock);
int buscarLibro(char***libros,char*codigo);
bool cumple(char*codigo,char**libro);
bool verificarStock(int*stock);
char** leerPedido(ifstream &arch);
int buscarCli(int**buffCli,int dni);
bool iguales(int dni,int*cliente);
void crearCliente(int*&cliente,int dni,int numPed);
void modificarCliente(int*cliente,int numPed);
void pasarInfo(int**&pedidosClientes,char***&pedidosLibros,bool**&pedidosAtendidos,
        int**buffCli,char***buffPedi,bool**buffAten,int cantCli,int cantPed);
void acortarEspacioCliente(int*&cliente);
void reporteDeEntregaDePedidos(const char*nombArch,int**pedidosClientes,
        char***pedidosLibros,bool**pedidosAtendidos);
void imprimirCliente(ofstream &arch,int*cliente,char***pedidosLibros,
        bool**pedidosAtendidos);
void imprimeLinea(ofstream &arch,int n,char c);
void imprimirPedido(ofstream &arch,int numPedi,char**pedido, bool*atendidos);
void imprimirLibroPedido(ofstream &arch,char*libro,bool atendido);

#endif /* METODOEXACTODEMEMORIA_H */

