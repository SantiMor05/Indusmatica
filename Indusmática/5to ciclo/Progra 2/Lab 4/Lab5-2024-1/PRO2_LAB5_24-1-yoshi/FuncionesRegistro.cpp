/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesRegistro.cpp
 * Author: Usuario
 * 
 * Created on 8 de mayo de 2025, 11:23
 */

#include <cstring>
#include <cstddef>
using namespace std;
#include "FuncionesRegistro.h"
enum REG {NUM,DNI,COD};

void* leeReg(ifstream &arch){
    void**registro;
    int *numero, *dni, num;
    char* codigo;
    arch>>num;
    if (arch.eof()) return nullptr;
    numero = new int;
    *numero = num;
    arch.get();
    dni = new int;
    arch>>*dni;
    arch.get();
    codigo = leer_cadena(arch);
    registro = new void*[3];
    registro[NUM] = numero;
    registro[DNI] = dni;
    registro[COD] = codigo;
    return registro;
}

char* leer_cadena(ifstream &arch, char flag){
    char *cad, buffer[100]{};
    arch.getline(buffer,100,flag);
    cad = new char[strlen(buffer)+1]{};
    strcpy(cad,buffer);
    return cad;
}

void imprimeReg(ofstream &arch, void* dato){
    void** registro = (void**)dato;
    int* numero = (int*)registro[NUM], *dni = (int*)registro[DNI];
    char* codigo = (char*)registro[COD];
    arch<<*numero<<"   "<<*dni<<"    "<<codigo<<endl;
}

int cmpReg(const void* a, const void* b){
    void** regA = (void**)a, **regB = (void**)b;
    int* numA = (int*)regA[NUM], *numB = (int*)regB[NUM];
    return *numA - *numB;
}