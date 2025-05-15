/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arreglos_genericos.h
 * Author: santi
 *
 * Created on 15 de mayo de 2025, 10:37
 */

#ifndef ARREGLOS_GENERICOS_H
#define ARREGLOS_GENERICOS_H

#include <fstream>
using namespace std;

void llenar_arreglo_heroes(void *&arreglo_heroes, int &cant, 
            const char *nombArch);
void *leerHeroe(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char deli);
int cmp_multicriterio_void(const void *dato1, const void *dato2);
void *leer_registro_heroe(void *heroe);
void imprimir_registro_heroe(const void *dato, ofstream &arch);
bool eliminar_registro(const void *datoAnt, void *dato);

#endif /* ARREGLOS_GENERICOS_H */
