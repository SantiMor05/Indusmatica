/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesEnteras.cpp
 * Author: Usuario
 * 
 * Created on 8 de mayo de 2025, 10:31
 */

#include <fstream>
using namespace std;
#include "FuncionesEnteras.h"

void* leenum(ifstream &arch){
    void* registro;
    int *numero, num;
    arch>>num;
    if (arch.eof()) return nullptr;
    numero = new int;
    *numero = num;
    registro = numero;
    return registro;
}

void imprimenum(ofstream &arch, void* dato){
    int* numero = (int*)dato;
    arch<<*numero<<endl;
}

int cmpnum(const void* a, const void* b){
    int* numA = (int*)a, *numB = (int*)b;
    return *numA - *numB;
}