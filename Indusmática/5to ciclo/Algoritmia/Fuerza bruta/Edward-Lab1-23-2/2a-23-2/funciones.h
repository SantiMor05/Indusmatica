/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: 00123
 *
 * Created on 4 de abril de 2025, 05:16 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargaBin(int*cromo,int n,int base,int num);
bool validarRequi(int*cromo,int n,int requi[][3]);
bool cumpleRequi(int *cromo,int n,int posi,int*requi);
int hallarInver(int *cromo,int n,int*inversiones);
void imprimir(int*cromo,int n);

#endif /* FUNCIONES_H */

