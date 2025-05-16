/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesRegistros.cpp
 * Author: 00123
 * 
 * Created on 8 de mayo de 2025, 08:56 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesRegistros.h"
using namespace std;

//2,14268463,BHD6079

void*leeregistro(ifstream &arch){

    int num;
    arch>>num;
    if(arch.eof())return nullptr;
    int *ptrNum=new int(num),*dni=new int;
    char aux[8],*codigo,c;
    arch>>c>>*dni>>c>>aux;
    codigo=new char[strlen(aux)+1];
    strcpy(codigo,aux);
    void**registro=new void*[3]{};
    registro[0]=ptrNum;
    registro[1]=dni;
    registro[2]=codigo;
    return registro;
}

int cmpregistro(const void*a,const void*b){
    
    void**ai=(void**)a,**bi=(void**)b;
    int*numA=(int*)ai[0],*numB=(int*)bi[0];
    return *numA-*numB;
}

void imprimeregistro(const void*reg,ofstream &arch){
    
    void**registro=(void**)reg;
    int*num=(int*)registro[0];
    int*dni=(int*)registro[1];
    char*codigo=(char*)registro[2];
    arch<<left<<setw(3)<<*num<<"  "<<*dni<<"  "<<codigo<<endl;
}
        