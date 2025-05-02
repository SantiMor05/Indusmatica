/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: santi
 *
 * Created on 1 de mayo de 2025, 21:52
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

void cargaproductos(void *&productos);
void *leerProducto(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char deli);
void cargapedidos(void *&pedidos);
void *leerPedido(ifstream &arch);

void procesaclientes(void *productos, void *pedidos, void *&clientes);
void *leerCliente(ifstream &arch, void *pedidos);
void agregarPedidos(int dni, void *&listaPedidos, void *pedidos);
void agregarPedidos(void *&pedCliente, void *pedido);
char *asignarCadena(char *cadena);
void incrementarEspacios(void *&pedidos, int &numDat, int &cap);
void actualizarEstadosProductos(void *productos, void *pedidos);
void verificarEstado(void *pedido, void *producto, int cant);
int buscarProducto(int codigo, void *productos);
void imprimeReporte(void *clientes);
void imprimirPedidos(void *pedidos, ofstream &arch);
void imprimirCaracter(ofstream &arch, int n, char car);


#endif /* PUNTEROSGENERICOS_H */
