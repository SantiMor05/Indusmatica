/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: Lenovo
 *
 * Created on 1 de mayo de 2025, 09:33 PM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

//COmunes
void verificar_Apertura_I(ifstream &arch, const char*nombArch);
void verificar_Apertura_O(ofstream &arch, const char*nombArch);
char *leerCadenaExacta(ifstream &arch, char delimitador = '\n');
void incrementarEspacios(void **&puntGen, int &numDat, int &cap);
void imprimir_Linea(ofstream &arch, char linea);

//Cargar productos
void cargarProductos(const char*nombArch, void *&pro);
void *leerRegistroProd(ifstream &arch);

//Cargar clientes
void cargaCliente(const char*nombArch, void *&cli);
void *leerRegistroCli(ifstream &arch);

//Cargar pedidos
void cargaPedidos(const char*nombArch, void *pro, void *cli);
int buscarPosProd(char *codPro, void **productos);
int buscarPosCLiente(int dniCLi, void **clientes);
bool sonIguales(char *codPro, void *pro);
bool sonIguales(int dniCLi, void *cli);
void actualizarPedido(void *pro, void *cli, int &nd, int &cap, int cantidad);
void *ponerPedido(void *codProducto, int cantidad, double totalPed);

//Imprimir reporte
void imprimirReporte(const char*nombArch, void *cli);
void imprimirCliente(ofstream &arch, void *cli);
void imprimirPedidos(ofstream &arch, void *ped);
void imprimir_Encabezado(ofstream &arch,int tipo);

#endif /* PUNTEROSGENERICOS_H */
