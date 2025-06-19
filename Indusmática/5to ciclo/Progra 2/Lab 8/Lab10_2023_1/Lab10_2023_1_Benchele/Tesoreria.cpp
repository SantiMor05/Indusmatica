/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Lenovo
 * 
 * Created on 18 de junio de 2025, 03:06 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Tesoreria.h"
#include "Arbol.h"
#define MAX_LINEA 120
using namespace std;

void Tesoreria::cargaAlumnos(const char*nombArch){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    aBoleta.crear(arch);     
}

void Tesoreria::actualiza(const char*nombArch){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    aBoleta.cargarEscalas(arch);
    aBoleta.actualizaBoleta();
}

void Tesoreria::imprimirBoleta(const char*nombArch){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    aBoleta.mostrarEnOrden(arch); 
}

