/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesEnteras.cpp
 * Author: kenyi
 * 
 * Created on 7 de mayo de 2025, 08:27 PM
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
#include "FuncionesEnteras.h"

void *leenum(ifstream &arch){
    
    
    int *num,d;
    arch>>d;
    if(arch.eof())return nullptr;
    num=new int{d};
    
    return num;
}


void imprimenum(const void*dato,ofstream &arch){
    int *num=(int *)dato;
    
    arch<<*num<<endl;
}

int cmpnum(const void*dato1,const void*dato2){
    void **reg1=(void**)dato1;
    void **reg2=(void**)dato2;
    int *num1=(int *)reg1[0];
    int *num2=(int *)reg2[0];
    
    return *num1-*num2;
}