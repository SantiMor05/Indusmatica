/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaConRegistro.h
 * Author: Lenovo
 *
 * Created on 6 de mayo de 2025, 11:49 PM
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H

#include <fstream>
using namespace std;

void *leeRegistros(ifstream &arch);
int compruebaRegistro(const void*a, const void*b);
void *leeOrdenes(ifstream &arch);
void imprimeRegistros(ofstream &arch, void *dato);

void imprimirRepartidor(ofstream &arch, void **repartidor);
void imprimirOrdenes(ofstream &arch, void **ordenes);
void imprimirOrden(ofstream &arch, void *ord);

#endif /* LISTACONREGISTRO_H */
