/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: 00123
 *
 * Created on 4 de abril de 2025, 07:29 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargaBin(int*cromo,int n,int base,int num);
bool cumplePesos(int*cromo,int n,int*paquetes,int*capacidades);
bool fijarmeCamion(int *cromo,int n,int camion,int*paquetes,int*capacidades);
int hallarDif(int*cromo,int n,int*paquetes,int*capacidades);
int fijarmeDif(int *cromo,int n,int camion,int*paquetes,int*capacidades);
void copiarCromo(int*cromoWin,int*cromo,int n);
void imprimirWin(int*cromoWin,int n,int difMin);


#endif /* FUNCIONES_H */

