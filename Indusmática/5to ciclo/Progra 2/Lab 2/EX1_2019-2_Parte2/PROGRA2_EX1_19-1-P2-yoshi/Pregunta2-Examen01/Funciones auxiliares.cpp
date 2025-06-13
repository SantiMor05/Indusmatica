/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones auxiliares.cpp
 * Author: alulab14
 * 
 * Created on 23 de abril de 2025, 07:11 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Funciones auxiliares.h"
#define INCREMENTO 5
#define INCRE_PLAC 3
#define MAX_CAR_LINEA 100

void leer_conductores(int *&dni, char **&conductor, char ***&placas){
    char nomArch[] = "Conductores.csv";
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"EROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    int NumDat=0, cap=0, DNI, nd[120]{}, capi[120]{}, telf;
    char *nombre, *placa, **auxPlac;
    while(true){
        arch>>DNI;
        if (arch.eof()) break;
        arch.get();
        nombre = leer_cadena(arch,',');
        arch.get();
        arch>>telf;
        if (NumDat==cap) incrementar_espacios(dni,conductor,placas,NumDat,cap);
        dni[NumDat-1] = DNI;
        conductor[NumDat-1] = nombre;
        while(true){
            if (arch.get()=='\n') break;
            if (nd[NumDat-1]==capi[NumDat-1]) incrementar_placas(placas[NumDat-1],nd[NumDat-1],capi[NumDat-1]);
            auxPlac = placas[NumDat-1];
            placa = leer_cadena(arch,',',8);
            auxPlac[nd[NumDat-1]-1] = placa;
            nd[NumDat-1]++;
        }
        NumDat++;
    }
}

void leer_multas(double *&multas){
    char nomArch[] = "Infracciones.csv";
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"EROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    int nd=300, cod, ultimo;
    double bufferMonto[nd]{}, monto;
    while(true){
        arch>>cod;
        if (arch.eof()) break;
        arch.get();
        while(arch.get()!=',');
        while(arch.get()!=',');
        arch>>monto;
        bufferMonto[cod-101] = monto;
    }
    for (int i = 0; i < nd; i++)
        if (bufferMonto[i]) ultimo = i;
    multas = new double[ultimo+2]{};
    for (int i = 0; i < ultimo+1; i++){
        if (bufferMonto[i]!=0) multas[i] = bufferMonto[i];
        else multas[i] = 0.001;
    }
}

void leer_infracciones_cometidas(int *dni, char ***placas, double *multas, double ***&montoXmultas){
    char nomArch[] = "Registro_de_Faltas.csv";
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"EROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    int DNI, posConductor, codMulta, numDat=0;
    char placa[8];
    while(dni[numDat]) numDat++;
    montoXmultas = new double**[numDat+1]{};
    for (int i = 0; i < numDat; i++)
        espacios_exacto(montoXmultas[i],placas[i]);
    while(true){
        arch>>DNI;
        if (arch.eof()) break;
        arch.get();
        arch.getline(placa,8,',');
        arch>>codMulta;
        posConductor = buscar_conductor(DNI,dni);
        if (posConductor!=-1){
            llenar_montos(montoXmultas[posConductor],placa,placas[posConductor],codMulta,multas);
        }
    }
}

void espacios_exacto(double **&montoXmultas, char **placas){
    int nd=0;
    while(placas[nd]) nd++;
    montoXmultas = new double*[2];
    montoXmultas[0] = new double[nd+1]{};
    montoXmultas[1] = new double;
    *montoXmultas[1] = 0;
}

void llenar_montos(double **montoXmultas, char *placa,char **placas, int codMulta, double *multas){
    int posPlaca, posMulta;
    double *monto;
    posPlaca = buscar_placa(placa,placas);
    if (posPlaca!=-1){
        monto = montoXmultas[0];
        posMulta = buscar_multa(codMulta,multas);
        if (posMulta!=-1){
            monto[posPlaca] += multas[posMulta];
            *montoXmultas[1] += multas[posMulta];
        }
    }
}

int buscar_multa(int codMulta, double *multas){
    for (int i = 0; multas[i]; i++)
        if (codMulta==(i+101)) return i;
    return -1;
}

int buscar_placa(char *placa, char **placas){
    for (int i = 0; placas[i]; i++)
        if (strcmp(placa,placas[i])==0) return i;
    return -1;
}

int buscar_conductor(int DNI, int *dni){
    for (int i = 0; dni[i]; i++)
        if (DNI==dni[i]) return i;
    return -1;
}

void imprimir_multas(double *multas){
    char nomArch[] = "PruebaMultas.txt";
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"EROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    arch<<setw(50)<<"MULTAS POR INFRACCION DE TRANSITO"<<endl;
    imprimir_linea(arch,MAX_CAR_LINEA,'=');
    arch<<setw(10)<<"CODIGO"<<setw(12)<<"MULTA"<<endl;
    imprimir_linea(arch,MAX_CAR_LINEA,'-');
    for (int i = 0; multas[i]; i++)
        arch<<setfill('0')<<setw(3)<<i+1<<")"<<setfill(' ')<<setw(6)<<i+101<<
                setw(12)<<multas[i]<<endl;
    imprimir_linea(arch,MAX_CAR_LINEA,'=');
}

void imprimir_conductores(int *dni, char **conductor, char ***placas){
    char nomArch[] = "PruebaConductores.txt";
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"EROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch<<setw(60)<<"REGISTRO CONDUCOTRES"<<endl;
    imprimir_linea(arch,MAX_CAR_LINEA,'=');
    arch<<"DNI"<<setw(40)<<"CONDUCTOR"<<setw(40)<<"AUTOS"<<endl;
    imprimir_linea(arch,MAX_CAR_LINEA,'=');
    for (int i = 0; dni[i]; i++) {
        arch<<setfill('0')<<setw(3)<<i+1<<")"<<setfill(' ')<<dni[i]<<left<<"   "<<
                setw(50)<<conductor[i]<<right;
        imprimir_placas(arch,placas[i]);
        imprimir_linea(arch,MAX_CAR_LINEA,'-');
    }
    imprimir_linea(arch,MAX_CAR_LINEA,'=');
}

void imprimir_placas(ofstream &arch,char **placas){
    for (int i = 0; placas[i]; i++) {
        if (i==0){
            arch<<setw(6)<<i+1<<")"<<setw(12)<<placas[i]<<endl;
        }else{
            arch<<setw(71)<<i+1<<")"<<setw(12)<<placas[i]<<endl;
        }
    }
}

void imprimir_linea(ofstream &arch,int n,char c){
    for (int i = 0; i < n; i++) arch.put(c);
    arch<<endl;
}

void incrementar_placas(char **&placas,int &nd, int &capi){
    capi += INCRE_PLAC;
    if (nd==0){
        placas = new char*[capi]{};
        nd = 1;
    }else{
        char **buffPlacas = new char*[capi]{};
        for (int i = 0; i < nd; i++) {
            buffPlacas[i] = placas[i];
        }
        delete placas;
        placas = buffPlacas;
    }
}

char* leer_cadena(ifstream &arch,char flag, int n){
    char *cad, buffer[200];
    arch.get(buffer,n,flag);
    cad = new char[strlen(buffer)+1]{};
    strcpy(cad,buffer);
    return cad;
}

void incrementar_espacios(int *&dni, char **&conductor, char ***&placas, int &NumDat, int &cap){
    cap += INCREMENTO;
    if (NumDat==0){
        dni = new int[cap]{};
        conductor = new char*[cap]{};
        placas = new char**[cap]{};
        NumDat = 1;
    }else{
        int *buffDni = new int[cap]{};
        char **buffConductor = new char*[cap]{};
        char ***buffPlacas = new char**[cap]{};
        for (int i = 0; i < NumDat; i++) {
            buffDni[i] = dni[i];
            buffConductor[i] = conductor[i];
            buffPlacas[i] = placas[i];
        }
        delete dni;
        delete conductor;
        delete placas;
        dni = buffDni;
        conductor = buffConductor;
        placas = buffPlacas;
    }
}

void imprimir_infracciones_cometidas(int *dni, char **conductor, char ***placas, double ***montoXmultas){
    char nomArch[] = "reporteInfracciones.txt";
    ofstream arch(nomArch,ios::out);
    arch.precision(2);
    arch<<fixed;
    if (not arch.is_open()){
        cout<<"EROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch<<setw(60)<<"REGISTRO CONDUCTORES"<<endl;
    imprimir_linea(arch,MAX_CAR_LINEA,'=');
    arch<<"DNI"<<setw(40)<<"CONDUCTOR"<<setw(40)<<"AUTOS"<<setw(12)<<"MULTAS"<<endl;
    imprimir_linea(arch,MAX_CAR_LINEA,'=');
    for (int i = 0; dni[i]; i++) {
        arch<<setfill('0')<<setw(3)<<i+1<<")"<<setfill(' ')<<dni[i]<<left<<"   "<<
                setw(50)<<conductor[i]<<right;
        imprimir_placas_infracciones(arch,placas[i],montoXmultas[i]);
        imprimir_linea(arch,MAX_CAR_LINEA,'-');
    }
    imprimir_linea(arch,MAX_CAR_LINEA,'=');
}

void imprimir_placas_infracciones(ofstream &arch,char **placas, double **montoXmultas){
    double *monto = montoXmultas[0];
    for (int i = 0; placas[i]; i++) {
        if (i==0){
            arch<<setw(6)<<i+1<<")"<<setw(12)<<placas[i]<<setw(12)<<monto[i]<<endl;
        }else{
            arch<<setw(71)<<i+1<<")"<<setw(12)<<placas[i]<<setw(12)<<monto[i]<<endl;
        }
    }
    arch<<setw(89)<<"Total: "<<*montoXmultas[1]<<endl;
}