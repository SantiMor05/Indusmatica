/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEnteras.cpp
 * Author: 00123
 * 
 * Created on 8 de mayo de 2025, 08:55 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesEnteras.h"
using namespace std;


void*leenum(ifstream &arch){
    
    int num;
    arch>>num;
    if(arch.eof())return nullptr;
    return new int(num);
}

void imprimenum(const void*a,ofstream &arch){
    
    int*ai=(int*)a;
    arch<<*ai<<endl;
}

int cmpnum(const void*a,const void*b){
    
    int*ai=(int*)a,*bi=(int*)b;
    return *ai-*bi;
}