/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: kenyi
 *
 * Created on 1 de mayo de 2025, 08:14 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
void cargaproductos(void *&productos);

char *leerExacto(ifstream &archProd, int max, char del);

void *leerRegPro(ifstream &archProd);

void incrementarEspacio(void **&pt, int &nd, int &cap);

void cargaclientes(void *&clientes);

void *leerRegCli(ifstream &archCli);

void cargapedidos(void *productos, void *&clientes);

void colocarPedido(void *clientes, void *productos, int &numProEnCli,
        int cant, int ndPro);

int buscarCliente(int dni, void **regCli);

int buscarProducto(char *cod, void **regPro);

void *colocarProd(char *cod,int cant,double *total);

void eliminarEspacios(void *clientes,int *numProEnCli);

void disminuirPedidos(void *&ped, int numPro);

void imprimereporte(void *clientes);
#endif /* PUNTEROSGENERICOS_H */
