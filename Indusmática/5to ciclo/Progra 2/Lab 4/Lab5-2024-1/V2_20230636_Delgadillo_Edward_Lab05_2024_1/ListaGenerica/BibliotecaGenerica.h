/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: 00123
 *
 * Created on 8 de mayo de 2025, 08:55 AM
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void crealista(void*&peds,void*(*leer)(ifstream &),const char*nombArch);
bool listaVacia(void*peds);
void insertarLista(void*dato,void*peds);
void imprimelista(void*peds,void(*imprimir)(const void*,ofstream &),
        const char*nombArch);

void combinalista(void*peds1,void*peds2,void*&pedsFinal,
        int(*comparar)(const void*,const void*));
void fusionGeneral(void**lis1,void**lis2,void**lisFinal,
        int(*comparar)(const void*,const void*));
void avanzar(void**&ini,void**&p,void**nodo1,void*&lis1Cab);
void fusionRapida(void**cabeza,void**cola,void**pedidosFinal);
void*quitaLista(void**lista);

#endif /* BIBLIOTECAGENERICA_H */
