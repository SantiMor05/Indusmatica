/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesComunes.cpp
 * Author: Lenovo
 * 
 * Created on 6 de mayo de 2025, 06:36 PM 11:48 pm
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesComunes.h"
#define MAX_LINEA 120
using namespace std;

void verificar_Apertura_I(ifstream &arch, const char*nombArch){
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}

void verificar_Apertura_O(ofstream &arch, const char*nombArch){
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}

char *leerCadenaExacta(ifstream &arch, char delimitador){
    char buffer[100], *cad;
    arch.getline(buffer, 100, delimitador);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}

void imprimirLinea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++)arch.put(linea);
    arch<<endl;
}