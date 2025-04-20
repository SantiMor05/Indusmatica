/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Usuario
 *
 * Created on 19 de abril de 2025, 16:25
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void lecturaDeProductos(const char* momArch, char ***&productos, int *&stock, double *&precios);
char* leer_cadena(ifstream &arch);
void llenar_buffPRod(char **&buffProd, char *cod, char *nombre);
void pruebaLecturaDeProductos(const char* momArch, char ***productos, int *stock, double *precios);
void imprimir_prod(char **productos, ofstream &arch);
void lecturaDePedidos(const char* nomArch, int *&fechaPedidos, char ***&CodigoPedidos, int ***&dniCantPedidos);
int leer_fecha(ifstream &arch);
int buscar_fecha(int fecha, int *buffFecha,int numDat);
void colocar_cod(char *cod, char **buffCodPed, int &nd);
void colocar_dni_cant(int dni,int cant,int **&buffDniCant, int &nd);
void exacto_pedidos(char **&CodigoPedidos, char**&buffCodPed, int nd);
void pruebaDeLecutraDePedidos(const char* nomArch, int *&fechaPedidos, char ***&CodigoPedidos, int ***&dniCantPedidos);
void coloc(int *&buffDniCant,int dni,int cant);
void exacto_dni_cant(int **&dniCantPedidos, int **buffDniCant,int nd);
void imprimir_fecha(ofstream &arch, int fechaPedidos);
void imprimir_pedidos(char **CodigoPedidos, int **dniCantPedidos, ofstream &arch);
void imprimir_dni_cant(ofstream &arch, int *dniCantPedidos);
void reporteDeEnvioDePedidos(const char* nomArch, char ***productos,int *stock,
        double *precios, int *fechaPedidos, char ***CodigoPedidos, int ***dniCantPedidos);
void imprimir_linea(ofstream &arch,char c, int n);
void imprimir_ped(int **dniCantPedidos, char ***productos, int *&stock, double *precios,
        char **CodigoPedidos, double &totFaltaStock, double &totIngresado, ofstream &arch);
void imprimir_dniOcant(int *dniCantPedidos, ofstream &arch, int n);
int buscar_cod(char *CodigoPedido, char ***productos, ofstream &arch);
bool comparar(char *CodigoPedido, char **producto);
void imprimir_nombre(char **productos, ofstream &arch);
int cant(int *dniCantPedido);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

