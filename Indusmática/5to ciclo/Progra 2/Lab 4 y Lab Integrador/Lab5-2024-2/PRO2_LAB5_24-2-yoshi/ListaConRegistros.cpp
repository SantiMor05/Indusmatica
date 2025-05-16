/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaConRegistros.cpp
 * Author: Usuario
 * 
 * Created on 7 de mayo de 2025, 23:06
 */

#include <cstring>
using namespace std;
#include "ListaConRegistros.h"

void* leerRegistros(ifstream &arch){
    void**registro;
    char*codigo, *nombre, *unidad;
    codigo = leer_cadena(arch,',');
    if (arch.eof()) return nullptr;
    nombre = leer_cadena(arch,',');
    unidad = leer_cadena(arch); 
    registro = new void*[2];
    void** dupla = (void**)registro[0];
    dupla = new void*[3];
    dupla[0] = codigo;
    dupla[1] = nombre;
    dupla[2] = unidad;
    registro[0] = dupla;
    registro[1] = nullptr;
    return registro;
}


void imprimeReg(ofstream &arch, void* dato){
    void**dupla = (void**)dato;
    void**datos = (void**)dupla[0];
    void**arreglo = (void**)dupla[1];
    imprimir_datos0(arch,datos);
    if (arreglo!=nullptr){
        arch<<"Ordenes: "<<endl;
        for (int i = 0; arreglo[i]; i++) {
            imprimir_orden(arreglo[i],arch);
        }
        arch<<endl;
    }else arch<<"El repartidor no tiene órdenes asignadas"<<endl<<endl;
}

void imprimir_datos0(ofstream &arch,void **datos){
    char* codigo = (char*)datos[0], *nombre = (char*)datos[1],
            *unidad = (char*)datos[2];
    arch<<codigo<<"   "<<nombre<<"   "<<unidad<<endl;;
}

void imprimir_orden(void *arreglo, ofstream &arch){
    void**datos = (void**)arreglo;
    int*dni = (int*)datos[0], *cant = (int*)datos[1];
    char* codPla = (char*)datos[2];
    arch<<*dni<<"    "<<*cant<<"  "<<codPla<<endl;
}

bool compruebaRegistro(const void* dat, const void* b){
    void** datos = (void**)dat;
    char* codA = (char*)datos[0], *codB = (char*)b;
    if (strcmp(codA,codB)==0) return true;
    return false;
}

void *leerOrdenes(ifstream &arch){
    void** registro, **datos;
    char* codRep, *codPla;
    int *dni, *cant, num;
    arch>>num;
    if (arch.eof()) return nullptr;
    dni = new int;
    *dni = num;
    arch.get();
    cant = new int;
    arch>>*cant;
    arch.get();
    codPla = leer_cadena(arch,',');
    codRep = leer_cadena(arch);
    registro = new void*[2];
    registro[0] = codRep;
    datos = (void**)registro[1];
    datos = new void*[3];
    datos[0] = dni;
    datos[1] = cant;
    datos[2] = codPla;
    registro[1] = datos;
    return registro;
}

char* leer_cadena(ifstream &arch,char flag){
    char* cad, buffer[100];
    arch.getline(buffer,100,flag);
    if (arch.eof()) return nullptr;
    cad = new char[strlen(buffer)+1]{};
    strcpy(cad,buffer);
    return cad;
}