/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaconRegistros.h
 * Author: alulab14
 *
 * Created on 7 de mayo de 2025, 10:49 AM
 */

#ifndef LISTACONREGISTROS_H
#define LISTACONREGISTROS_H

void*leeregistros(ifstream &arch);
char*leeCadena(ifstream &arch,char deli);
void* leeordenes(ifstream &arch);
int compruebaregistro(const void*a,const void*b);
void imprimeregistros(const void*dup,ofstream &arch);


#endif /* LISTACONREGISTROS_H */
