/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesRegistro.cpp
 * Author: Lenovo
 * 
 * Created on 7 de mayo de 2025, 10:10 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesComunes.h"
#include "FuncionesRegistro.h"
using namespace std;

enum REG{NUMPED, DNI, CODLIB};

/*
 1,69200503,ZQY9966
 3,81082011,QRH6838
 2,14268463,BHD6079
 7,42302422,RWW7975
 //REG{NUMPED, DNI, CODLIB};
 */
void *leeRegistro(ifstream &arch){
    void **reg;
    
    int *numPed, auxPed, *dni;
    char *codLib, c;
    arch>>auxPed;
    if(arch.eof())return nullptr;
    numPed = new int;
    *numPed = auxPed;
    dni = new int;
    arch>>c>>*dni>>c;
    codLib = leerCadenaExacta(arch);
    
    //REG{NUMPED, DNI, CODLIB};
    reg = new void*[3]{};
    
    reg[NUMPED] = numPed;
    reg[DNI] = dni;
    reg[CODLIB] = codLib;

    return reg;
}

int cmpReg(const void*a, const void*b){
    void **ai = (void **)a, **bi = (void **)b;
    int *numPedA = (int *)ai[NUMPED],
        *numPedB = (int *)bi[NUMPED];
    return *numPedA - *numPedB;
}

void imprimeRegistro(ofstream &arch, void *dato){
    //REG{NUMPED, DNI, CODLIB};
    void **registro = (void **)dato;
    int *numPed = (int *)registro[NUMPED],
        *dni = (int *)registro[DNI];
    char *codLib = (char *)registro[CODLIB];
    
    arch<<left<<setw(18)<<*numPed<<*dni<<setw(4)<<"  "<<setw(12)<<codLib<<endl;
}
