/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 6 de octubre de 2024, 11:48
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
using namespace std;

void leerStock(int &cant_prod, int *cod_prod, int *codigo_almacen, int *stock, 
        const char *nombStock);
void probarDatos(int cant_prod, int *cod_prod, int *codigo_almacen, int *stock, 
        const char *nombPrueba);
void imprimirCaracter(char car , int n, ofstream &archSalida);
void pedirDatos(int &fecha_ini, int &fecha_fin);

#endif /* FUNCIONESAUXILIARES_H */

