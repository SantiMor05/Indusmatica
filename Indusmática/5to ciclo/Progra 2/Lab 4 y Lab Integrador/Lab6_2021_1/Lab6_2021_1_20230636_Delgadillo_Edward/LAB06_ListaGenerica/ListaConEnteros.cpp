/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.cpp
 * Author: 00123
 * 
 * Created on 8 de mayo de 2025, 04:54 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaConEnteros.h"

using namespace std;

void*leenum(ifstream &arch){
    
//    35912665,O2Z-308,22/07/2019,156
    int num;
    arch>>num;
    if(arch.eof())return nullptr;
    char c,aux[20];
    arch.get();
    arch.getline(aux,20,',');
    int *dd=new int,*mm=new int,*aa=new int;
    arch>>*dd>>c>>*mm>>c>>*aa>>c>>num;
    int fecha=(*aa)*10000+(*mm)*100+(*dd);
    return new int(fecha);
}

int cmpnum(const void*a,const void*b){
    
    int*ai=(int*)a,*bi=(int*)b;
    return *ai-*bi;
}

void imprimenum(const void*a,ofstream &arch){
    
    int*ai=(int*)a;
    arch<<*ai<<endl;
}

