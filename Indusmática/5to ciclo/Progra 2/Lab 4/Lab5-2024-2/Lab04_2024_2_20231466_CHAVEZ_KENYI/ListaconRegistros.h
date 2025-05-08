/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaconRegistros.h
 * Author: kenyi
 *
 * Created on 8 de mayo de 2025, 12:51 PM
 */

#ifndef LISTACONREGISTROS_H
#define LISTACONREGISTROS_H


char *leerExacto(ifstream &arch, int max, char del);

int compruebaregistro(const void*dato1, const void*dato2);

void* leeregistro(ifstream &arch);


void *leeordenes(ifstream &arch);

void imprimeregistros(const void *dato, ofstream &arch);
#endif /* LISTACONREGISTROS_H */
