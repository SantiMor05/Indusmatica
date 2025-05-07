/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaconEnteros.h
 * Author: santi
 *
 * Created on 5 de mayo de 2025, 19:23
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

#include <fstream>
using namespace std;

void *leenumeros(ifstream &arch);
int compruebanumeros(const void *num1, const void *num2);
void *leeregnumeros(ifstream &arch);
void imprimenumeros(const void *dupla, ofstream &arch);

#endif /* LISTACONENTEROS_H */
