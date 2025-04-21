/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: 00123
 *
 * Created on 18 de abril de 2025, 09:35 PM
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

#include <fstream>
using namespace std;

void lecturaDeProductos(const char*nombArch,
        char***&productos,int*&stock,double*&precios);
void apertura(bool abierto,const char*nombArch);
char**leerProducto(ifstream &arch);
char*leerCadena(ifstream &arch,char deli);
void pasarInfo(char***&productos,int*&stock,double*&precios,
            char***bufPro,int*bufStock,double*bufPrecio,int nd);
void pruebaDeLecturaDeProductos(const char*nombArch,
        char***productos,int*stock,double*precios);
void imprimirProducto(ofstream &arch,char**producto,int stock,double precio);
void lecturaDePedidos(const char*nombArch,
        int*&fechaPedidos,char***&codigoPedidos,int***&dniCantPedidos);
void pruebaDeLecturaDePedidos(const char*nombArch,
        int*fechaPedidos,char***codigoPedidos,int***dniCantPedidos);
void reporteDeEnvioDePedidos(const char*nombArch,
        char***productos,int*stock,double*precios,
        int*fechaPedidos,char***codigoPedidos,int***dniCantPedidos);

void brindarInfo(int*&fechaPedidos,char***&codigoPedidos,int***&dniCantPedidos,
            int*bufFechaPed,char***bufCodPed,int***bufDniCantPed,int nd);
void hacerExacto(char***bufCodPed,int*numCodigosEnFechas,
        int***bufDniCantPed,int*numClientesEnFechas);
void ajustarCodigos(char**&codigos,int nd);
void ajustarClientes(int**&clientes,int nd);
void crearFecha(int fechaRefe,int&fecha,char**&codigos,int**&clientes);
int buscarFecha(int*bufFechaPed,int fecha);
void agregarCodigo(char**codigos,int pos,const char*codigo);
void agregarCliente(int**clientes,int pos,int dni,int cant);
void completarCliente(int*cliente,int dni,int cant);
void imprimirInfoFecha(ofstream &arch,int fecha,char**codigos,int**clientes);
void imprimirCliente(ofstream &arch,int*cliente);

void imprimirFecha(ofstream &arch,
        int fecha,char**codigos,int**clientes,
        char***productos,int*stock,double*precios);
void imprimeLinea(ofstream &arch,int n,char c);
void imprimirPedido(ofstream &arch,int i,int*cliente,char*producto,
        char***productos,int*stock,double*precios,
        double &totalIngresado,double &totalPerdido);
int buscarProducto(char***productos,char*producto);
bool iguales(char**producto,char*productoRefe);
char* darTitulo(char**producto);
bool verStock(int &stock,int cant);
void imprimirTotales(ofstream &arch,double totalIngresado,double totalPerdido);

void imprimirClientesEnFecha(ofstream &arch,int**clientes,char**codigos,
        char***productos,int*stock,double*precios);
int sacarDni(int*cliente);
void imprimirInfoCliente(ofstream &arch,int num,int dniRefe,
        int**clientes,char**codigos,
        char***productos,int*stock,double*precios);
int sacarCant(int*cliente);
void cambiarDni(int*cliente,int nuevoDni);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

