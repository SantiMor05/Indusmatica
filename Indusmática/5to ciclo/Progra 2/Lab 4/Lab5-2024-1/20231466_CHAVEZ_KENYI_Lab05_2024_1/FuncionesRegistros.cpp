/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesRegistros.cpp
 * Author: kenyi
 * 
 * Created on 7 de mayo de 2025, 08:28 PM
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
#include "FuncionesRegistros.h"


void *leeregistro(ifstream &arch){
    void **reg;
    int num,dni;
    char *cod;
    
    arch>>num;
    if(arch.eof())return nullptr;
    arch.get();
    arch>>dni;
    arch.get();
    reg=new void*[3]{};
    reg[0]=new int{num};
    reg[1]=new int{dni};
    reg[2]=leerExacto(arch,8,'\n');
    return reg;
}

char *leerExacto(ifstream &arch,int max,char del){
    char buff[max],*cad;
    arch.getline(buff,max,del);
    if(arch.eof())return nullptr;
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void imprimeregistro(const void*dato,ofstream &arch){
    void **reg=(void **)dato;
    int *num=(int *)reg[0];
    int *dni=(int *)reg[1];
    char *cod=(char *)reg[2];
    
    arch<<setw(2)<<*num<<setw(18)<<*dni<<setw(12)<<cod<<endl;
}

int cmpregistro(const void *dato1,const void *dato2){
    void **dupla1=(void**)dato1;
    void **dupla2=(void**)dato2;
    void **tripleta1=(void**)dupla1[0];
    void **tripleta2=(void**)dupla2[0];
    int *num1=(int*)tripleta1[0];
    int *num2=(int*)tripleta2[0];
    return *num1-*num2;
}