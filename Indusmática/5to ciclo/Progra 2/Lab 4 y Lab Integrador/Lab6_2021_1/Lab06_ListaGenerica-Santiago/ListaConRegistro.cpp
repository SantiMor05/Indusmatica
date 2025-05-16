/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistro.cpp
 * Author: santi
 * 
 * Created on 14 de mayo de 2025, 10:44
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaConRegistro.h"

using namespace std;

#define MAX_CAR 90

enum Registro{LIC,FECHA, FALTA};

void *leeregistro(ifstream &arch){
    int lic, *licencia, *falta, dd,mm,aa,*fecha;
    char buffer[10], car;
    void **registro;
    
    arch >> lic;
    if(arch.eof())return nullptr;
    licencia = new int{lic};
    falta = new int;
    fecha = new int;
    arch.get();
    arch.getline(buffer, 10, ',');
    arch >> dd >> car >> mm >> car >> aa >> car >> *falta;
    *fecha = aa * 10000 + mm * 100 + dd;
    
    registro = new void*[3];
    registro[LIC] = licencia;
    registro[FECHA] = fecha;
    registro[FALTA] = falta;
    return registro;
}


int cmpregistro(const void *dato1, const void *dato2){
    
    void **registro1 = (void **)dato1;
    void **registro2 = (void **)dato2;
    
    int *fecha1 = (int *)registro1[FECHA];
    int *fecha2 = (int *)registro2[FECHA];
    
    return *fecha1 - *fecha2;
}

void imprimeregistro(const void *dato, ofstream &arch){
    
    ifstream archConductores("Conductores.csv", ios::in);
    if(!archConductores){
        cout << "ERROR: No se pudo abrir el archivo Conductores" << endl;
        exit(1);
    }
    
    static int ant = 1;
    void **registro = (void **)dato;    
    int *fecha = (int *)registro[FECHA], dd, mm, aa, aux;
    int *licencia = (int *)registro[LIC], *falta = (int *)registro[FALTA];
    dd = *fecha % 100;
    aux = (*fecha) / 100;
    mm = aux % 100;
    aa = aux / 100;
    
    if(aux != ant){
        if(ant != 1)
             imprimirLinea(arch, MAX_CAR, '=');
        arch << "Año:" << setw(6) << aa << setw(8) << "Mes:" << setw(3) <<
                " " << setfill('0') << setw(2) << mm << setfill(' ') << endl;
        arch << "FECHA" << setw(12) << "LICENCIA" << setw(20) << "NOMBRE" << 
                setw(20) << "FALTA" << endl;
        imprimirLinea(arch, MAX_CAR, '=');
        ant = (*fecha/100);
    }
    arch << setfill('0') << setw(4) << aa << "/" << setw(2) << mm << "/" 
            <<setw(2) << dd << setfill(' ') << setw(10) << *licencia << setw(4) 
            << " ";
    buscarEImprimirNombre(*licencia, archConductores, arch);
    arch << setw(4) << *falta << endl;
}

void imprimirLinea(ofstream &arch, int n, char car){
    for(int i = 0; i < n; i++)
        arch.put(car);
    arch << endl;
}

void buscarEImprimirNombre(int licencia, ifstream &archConductores, 
        ofstream &arch){
    
    archConductores.seekg(0,ios::beg);
    int lic;
    char buffer[100];
    while(true){
        archConductores >> lic;
        if(archConductores.eof())break;
        archConductores.get();
        archConductores.getline(buffer, 100, '\n');
        if(lic == licencia){
            arch << left << setw(40) <<  buffer << right;
            return;
        }
    }
    arch << left << setw(40) << "NO ENCONTRADO" << right;
}