/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesAux.h
 * Author: kenyi
 *
 * Created on 1 de mayo de 2025, 11:27 AM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
void cargarInventario(const char*nombArch, void *&inventario);


char *leerExacto(ifstream &arch, int max, char del);

void *leerRegistro(ifstream &arch);

void incrementarEspacios(void **&inventario, int &nd, int &cap);

void cargarMenu(const char*nombArch, void *&menu);


void *leerRegMenu(ifstream &arch);


void reporte(const char *nombArch, void *men);

void imprimirReg(void *menu,ofstream &arch);


void verificarDisponible(void *inv, void *men, double*cantidad,
        char *uni, int& ndIns, int &cpIns);

int buscar(void **reg,char *cod);

void actualizarMenu(const char*nombArch, void *inventario, void *&menu);
void reporte(const char*nombArch, void *menu);

#endif /* FUNCIONESAUX_H */
