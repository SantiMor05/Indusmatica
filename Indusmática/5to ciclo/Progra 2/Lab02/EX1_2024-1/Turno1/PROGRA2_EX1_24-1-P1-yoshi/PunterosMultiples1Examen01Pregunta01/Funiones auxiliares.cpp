/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Funciones auxiliares.h"
#define INCREMENTO 5

void cargar_vemtas(char **&ventasLibroCodigo,int **&ventasDNIFechaPuntaje,const char *nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    char *codLib;
    int dni, puntaje, fecha, dd, mm, aa, numDat=0, cap=0;
    while(true){
        codLib = leer_cadena(arch,',');
        if (arch.eof()) break;
        arch>>dni;
        arch.get();
        arch>>dd;
        arch.get();
        arch>>mm;
        arch.get();
        arch>>aa;
        fecha = llenar_fecha(dd,mm,aa);
        arch.get();
        arch>>puntaje;
        arch.get();
        if (numDat==cap) incrementar_espacios(ventasLibroCodigo,ventasDNIFechaPuntaje,numDat,cap);
        ventasLibroCodigo[numDat-1] = codLib;
        ventasDNIFechaPuntaje[numDat-1] = new int[3]{};
        llenarInt(ventasDNIFechaPuntaje[numDat-1],dni,fecha,puntaje);
        numDat++;
    }
}

void cargaLibros(char ***&libro, const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    int numDat=0, cap=0;
    char* codigo, *nombre, *autor, **datos;
    while(true){
        codigo = leer_cadena(arch,',');
        if (arch.eof()) break;
        nombre = leer_cadena(arch,',');
        autor = leer_cadena(arch);
        if (numDat==cap) incrementar_espacios(libro,numDat,cap);
        libro[numDat-1] = new char*[3]{};
        llenar_char(libro[numDat-1],codigo,nombre,autor);
        numDat++;
    }
}

void pruebaCargaLibros(char ***libro, const char* nomArch){
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch<<"CODIGO"<<setw(50)<<"NOMBRE"<<setw(30)<<"AUTOR"<<endl;
    char **lib;
    for (int i = 0; libro[i]; i++) {
        lib = libro[i];
        arch<<lib[0]<<setw(60)<<lib[1]<<setw(30)<<lib[2]<<endl;
    }
}

void incrementar_espacios(char ***&libro,int &numDat,int &cap){
    cap += INCREMENTO;
    if (numDat==0){
        libro = new char**[cap]{};
        numDat = 1;
    }else{
        char***auxLib = new char**[cap]{};
        for (int i = 0; i < numDat; i++) {
            auxLib[i] = libro[i];
        }
        delete libro;
        libro = auxLib;
    }
}

void llenar_char(char **libro, char *codigo, char *nombre, char*autor){
    libro[0] = codigo;
    libro[1] = nombre;
    libro[2] = autor;
}

void llenarInt(int *ventasDNIFechaPuntaje,int dni, int fecha, int puntaje){
    ventasDNIFechaPuntaje[0] = dni;
    ventasDNIFechaPuntaje[1] = fecha;
    ventasDNIFechaPuntaje[2] = puntaje;
}

int llenar_fecha(int dd, int mm, int aa){
    return aa*10000 + mm*100 + dd;
}

char* leer_cadena(ifstream &arch,char flag){
    char *cad, buffer[100];
    arch.getline(buffer,100,flag);
    if (arch.eof()) return nullptr;
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void incrementar_espacios(char **&ventasLibroCodigo, int **&ventasDNIFechaPuntaje,int &numDat, int &cap){
    cap += INCREMENTO;
    if (numDat==0){
        ventasLibroCodigo = new char*[cap]{};
        ventasDNIFechaPuntaje = new int*[cap]{};
        numDat = 1;
    }else{
        char **buffventasLibroCodigo = new char*[cap]{};
        int **buffventasDNIFechaPuntaje = new int*[cap]{};
        for (int i = 0; i < numDat; i++) {
            buffventasLibroCodigo[i] = ventasLibroCodigo[i];
            buffventasDNIFechaPuntaje[i] = ventasDNIFechaPuntaje[i];
        }
        delete ventasLibroCodigo;
        delete ventasDNIFechaPuntaje;
        ventasLibroCodigo = buffventasLibroCodigo;
        ventasDNIFechaPuntaje = buffventasDNIFechaPuntaje;
    }
}

void pruebaCargaVentas(char **ventasLibroCodigo,int **ventasDNIFechaPuntaje,const char *nomArch){
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    int *enteros;
    arch<<"CODIGO"<<setw(10)<<"DNI"<<setw(20)<<"FECHA DE VENTA"<<setw(12)<<"PUNTAJE"<<endl;
    for (int i = 0; ventasLibroCodigo[i]; i++) {
        arch<<ventasLibroCodigo[i];
        enteros = ventasDNIFechaPuntaje[i];
        arch<<setw(12)<<enteros[0]<<setw(20)<<enteros[1]<<setw(10)<<enteros[2]<<endl;
    }
}
