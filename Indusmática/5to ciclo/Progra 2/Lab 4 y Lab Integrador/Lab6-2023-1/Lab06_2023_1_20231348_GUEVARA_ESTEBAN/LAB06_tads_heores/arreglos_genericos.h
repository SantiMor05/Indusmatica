/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arreglos_genericos.h
 * Author: esteban
 *
 * Created on 15 de mayo de 2025, 09:54
 */

#ifndef ARREGLOS_GENERICOS_H
#define ARREGLOS_GENERICOS_H


void llenar_arreglo_heroes(void *& arreglo_heroes,int& cantidad_total_heroes,
            const char* nombreArch);
void *lectura(ifstream &archLee);
char * lecturaExacta(ifstream &archLee,char delim);
void aumentarEspacioArr(void** &arrHeroes,int &cap,int &numDat);
int cmp_multicriterio_void( const void*, const void*);

#endif /* ARREGLOS_GENERICOS_H */
