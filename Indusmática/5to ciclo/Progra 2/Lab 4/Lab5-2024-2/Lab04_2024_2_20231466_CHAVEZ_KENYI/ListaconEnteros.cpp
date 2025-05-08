/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaconEnteros.cpp
 * Author: kenyi
 * 
 * Created on 8 de mayo de 2025, 12:07 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "ListaconEnteros.h"


void* leenumeros(ifstream &arch){
    int *num,n;
    arch>>n;
    if(arch.eof())return nullptr;
    num=new int{n};
    return num;
}

int compruebanumero(const void *dato1,const void*dato2){
    int *num1=(int *)dato1;
    int *num2=(int *)dato2;
    
    return *num1-*num2;
}

void* leeregnumeros(ifstream &arch){
    void **dupla;
    int *num,dato;
    arch>>dato;
    if(arch.eof())return nullptr;
    dupla=new void*[2]{};
    dupla[0]=new int{dato};
    arch>>dato;
    dupla[1]=new int{dato};
    return dupla;
}


void imprimenumeros(const void *dato,ofstream &arch){
    void **dupla=(void**)dato;
    void **arr=(void**)dupla[1];
    int *num=(int*)dupla[0];
    
    arch<<*num<<endl;
    for(int i=0;arr[i];i++){
        num=(int *)arr[i];
        arch<<setw(3)<<left<<*num;
    }
    arch<<endl;
}