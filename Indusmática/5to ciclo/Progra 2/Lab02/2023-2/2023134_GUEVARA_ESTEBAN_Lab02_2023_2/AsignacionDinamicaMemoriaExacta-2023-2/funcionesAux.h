/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.h
 * Author: esteban
 *
 * Created on 19 de abril de 2025, 16:46
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
//P1
void lecturaDeProductos(const char* nombreArch,char*** &productos,int* &stock,double* &precios);
char** lecturaProducto(ifstream &archLee);
char* lecturaExacta(ifstream &archLee);
void pruebaDeLecturaDeProductos(const char* nombreArch,char*** productos,int* stock,double* precios);


//P2
void lecturaDePedidos(const char* nombreArch,int*& fechaPedidos,char***& codigosPedidos,int***& dniCantPedidos);
void pruebaDeLecturaDePedido(const char* nombreArch,int* fechaPedidos,char*** codigosPedidos,int*** dniCantPedidos);
int buscamosFecha(int *bufferFec,int fecha);
void aumentamosProductos(char** bufferCodPed,int&ndCod,char *producto);
void aumentamosDniCant(int **bufferDniCant,int &ndDniCant,int dni,int cant);
void asignar(int *bufferDniCant,int dni,int cant);
void asignamosMemoriaExactaCodPed(char**& codigosPedidos,char** bufferCodPed,int ndCod);
void asignamosMemoriaExactaDniCant(int **&dniCantPedidos,int** bufferDniCant,int ndDniCant);
void impresionProductos(char**codigosPedidos,int**dniCantPedidos,ofstream &archReport);
void impresionDni(int* dniCantPedidos,ofstream &archReport);


//P3
void reporteDeEnvioDePedidos(const char* nombreArch,char*** productos,int* stock,double* precios,
        int* fechaPedidos,char*** codigosPedidos,int*** dniCantPedidos);
void impresionLinea(ofstream &archReport,int cant,char car);


void impresionDatosYModiStock(char** codigosPedidos,int** dniCantPedidos,
                    char***productos,double *precios,int* stock,ofstream &archReport);
int buscarProd(char* codigo,char*** productos);
bool comparacion(char* codigo,char** productos);
void impresion(int num,double precios,int* dniCantPedidos,bool hayStock,double& totalIngreso,
                        double &totalPerdido,char**productos,ofstream &archReport);
    
void impresionProducto(char** productos,ofstream &archReport);

#endif /* FUNCIONESAUX_H */

