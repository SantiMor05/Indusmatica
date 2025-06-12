/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Restaurante.cpp
 * Author: YOSHI
 * 
 * Created on 12 de junio de 2025, 08:22
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Restaurante.h"
#define MAX_NUM_LINEA 120

Restaurante::Restaurante() {
    cantidad_comandas = 0;
}

void Restaurante::cargar_comandas(){
    char nomArch[] = "atenciones.csv";
    leerAtenciones(nomArch);
    char nomArch2[] = "comandas.csv";
    leerComandas(nomArch2);
}

void Restaurante::leerAtenciones(const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No e pudo abrir el archivo "<<nomArch<<endl;
        exit(11);
    }
    int id, horaI, minI, horaF, minF, tempI, tempF;
    while(true){
        arch>>id;
        if (arch.eof()) break;
        arch.get();
        arch>>horaI;
        arch.get();
        arch>>minI;
        arch.get();
        arch>>horaF;
        arch.get();
        arch>>minF;
        tempI = formarTemp(horaI,minI);
        tempF = formarTemp(horaF,minF);
        comandas[cantidad_comandas].llenarDatos1(id,tempI,tempF);
        cantidad_comandas++;
     }
}

int Restaurante::formarTemp(int horaI,int minI){
    return horaI*100 + minI;
}

void Restaurante::leerComandas(const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No e pudo abrir el archivo "<<nomArch<<endl;
        exit(11);
    }
    int id, pos;
    char tipo;
    while(true){
        arch>>id;
        if (arch.eof()) break;
        arch.get();
        arch>>tipo;
        arch.get();
        pos = buscarProd(comandas,id);
        if (pos!=-1) comandas[pos].LeerProducto(arch,tipo);
    }
}

int Restaurante::buscarProd(Comanda *comandas,int id){
    for (int i = 0; i < cantidad_comandas; i++)
        if (id==comandas[i].GetId()) return i;
    return -1;
}

void Restaurante::imprimirComandas(){
    char nomArch[] = "Reporte.txt";
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No e pudo abrir el archivo "<<nomArch<<endl;
        exit(11);
    }
    arch.precision(2);
    arch<<fixed;
    arch<<setw(80)<<"Reporte de Comandas Pollos Tikos S.A."<<endl;
    imprimirLinea(arch,'=',MAX_NUM_LINEA);
    for (int i = 0; i < cantidad_comandas; i++) {
        comandas[i].imprimirComanda(arch);
        imprimirLinea(arch,'=',MAX_NUM_LINEA);
    }
}

void Restaurante::imprimirLinea(ofstream &arch,char c,int n){
    for (int i = 0; i < n; i++) arch.put(c);
    arch<<endl;
}

void Restaurante::actualizaComandas(){
    for (int i = 0; i < cantidad_comandas; i++)
        comandas[i].actualiza();
}