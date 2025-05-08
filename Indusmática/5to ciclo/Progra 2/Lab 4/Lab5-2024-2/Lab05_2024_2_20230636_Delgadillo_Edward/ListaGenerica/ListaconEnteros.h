/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaconEnteros.h
 * Author: alulab14
 *
 * Created on 7 de mayo de 2025, 10:49 AM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void*leenumeros(ifstream &arch);
void*leeregnumeros(ifstream &arch);
int compruebanumero(const void*a,const void*b);
void imprimenumeros(const void*dup,ofstream &arch);
#endif /* LISTACONENTEROS_H */
