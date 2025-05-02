/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: Usuario
 *
 * Created on 1 de mayo de 2025, 08:19 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#endif /* PUNTEROSGENERICOS_H */

//Leer Productos
void cargaproductos(void *&productos);
void *leerRegProd(ifstream &arch);
char *leerExacto(ifstream &arch, int max,char del);
void incrementarCap(void **&producto,int & nd,int &cap);

//Leer Clientes 
void cargaclientes(void *&clientes);
void *leerRegCli(ifstream &arch);
void aumentarEspacioCliente(void *cli);
void volverCuarteta(void *&cli);

//Leer Pedidos
void cargapedidos(void *producto, void *clientes);
int buscarCli(void*cli, int dni);
int buscarProd(void*pro, char* cod);
void agregarPedido(void *prod,void *cli,int cant,int &ndP);
void* asignarMemoria();
void AcotarPedidos(void *cli,int *ndP);
void cortarEspacio(void *cli,int nd);

//Imprimir Clientes
void imprimereporte(void *clientes);


