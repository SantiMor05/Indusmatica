/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: santi
 *
 * Created on 1 de mayo de 2025, 11:45
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

void cargaproductos(void *&productos);
void *leerProducto(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char deli);
void cargaclientes(void *&clientes);
void *leerCliente(ifstream &arch);

void cargapedidos(void *productos,void *clientes);
void disminuirEspacios(void *clientes, int *nd);
void ajustarEspacios(void *&pedidos,int nd);
int agregarPedido(void *cliente, void *producto,int cant, int &nd, char *cod);
char *asignarCadena(char *cadena);
void asignarEspacio(void *&Listapedidos);
int buscarProducto(char *cod, void *productos);
int buscarCliente(int dni, void *clientes);

#endif /* PUNTEROSGENERICOS_H */
