/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: 00123
 *
 * Created on 30 de marzo de 2025, 11:16 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

char* copiarDinamico(const char*cad1);

void convertirCromo(int*cromo,int n,int num);
     
void convertirApalabra(char*formada,int &cantFormada,const int*cromo,
            const char*letras,int cantLetras);
     
void actualizarContadores(int*contadores,char**palabras,int cantPalabras,
        const char*formada,int cantFormada);

void agregarAlFinal(char*formada,int cantFormada,char letra);

bool comparar(const char*formada,int cantFormada,const char*palabra);

#endif /* FUNCIONES_H */

