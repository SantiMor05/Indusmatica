/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Lenovo
 * 
 * Created on 26 de junio de 2025, 05:26 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Biblioteca.h"
#define MAX_LINEA 120
using namespace std;

void Biblioteca::carga(const char*nombArchLibro, const char*nombArchEstante){
    ifstream archLibro(nombArchLibro, ios::in);
    if(not archLibro.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    
    ifstream archEstante(nombArchEstante, ios::in);
    if(not archEstante.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    
    AEstante.carga(archEstante, archLibro);
}

void Biblioteca::imprime(const char*nombArch){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    
    arch<<setw((MAX_LINEA + 18)/2)<<"REPORTE BIBLIOTECA"<<endl;
    
    imprimirLinea(arch, '=');
    
    AEstante.imprimir(arch);
}

void Biblioteca::imprimirLinea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++)arch.put(linea);
    arch<<endl;
}

//Prueba
void Biblioteca::prueba(const char*nombArch, double peso){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    
    arch<<setw((MAX_LINEA + 18)/2)<<"ESTANTE ASIGNADO"<<endl;
    imprimirLinea(arch, '=');
    
    AEstante.esAsignado(arch, peso);
}