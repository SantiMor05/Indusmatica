/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Cafeteria.h
 * Author: Lenovo
 *
 * Created on 30 de abril de 2025, 06:26 PM
 */

#ifndef CAFETERIA_H
#define CAFETERIA_H

#include <fstream>
using namespace std;


//COmunes
void verificar_Apertura_I(ifstream &arch, const char*nombArch);
void verificar_Apertura_O(ofstream &arch, const char*nombArch);
char *leerCadenaExacta(ifstream &arch, char delimitador = '\n');
void imprimir_Linea(ofstream &arch, char linea);
void incrementarEspacios(void **&puntGenerico, int &numDat, int &cap);

//Carga inventario
void cargarInventario(const char*nombArch, void  *&inv);
void *leerRegistro(ifstream &arch);
void imprimirInventario(const char*nombArch, void *&inv);
void imprimeUnInventario(ofstream &arch, void *inv);
    
//Carga menu
void cargarMenu(const char*nombArch, void *&men);
void *leerMenu(ifstream &arch);
void *asignarValoresReg(char *cod, char *nom, char *des, char *tipo, bool *disp, double *pre, int *cantVenESt);

//Actualizar menu
void actualizarMenu(const char*nombArch, void *inv, void *men);
int buscarMenu(char *codMenu, void **menu);
int buscarInv(char *codInv, void **inventario);
bool sonIgualesMen(char *codMenu, void *men);
bool sonIgualesInv(char *codInv, void *inv);
void actualizarUnMenu(void *inv, void *&men, double cantidad, char uniMed, int &nd, int &cap);
void *actualizarInsumo(void **inventario, double cantidad, char uniMed, void **menu);
void actualizarInventario(void **inventario, int cantidad, char uniMed, void **menu);

//Reporte
void reporteMenu(const char*nombArch, void *men);
void imprimirEncabezado(ofstream &arch);
void imprimirUnMenu(ofstream &arch, void *men);

#endif /* CAFETERIA_H */
