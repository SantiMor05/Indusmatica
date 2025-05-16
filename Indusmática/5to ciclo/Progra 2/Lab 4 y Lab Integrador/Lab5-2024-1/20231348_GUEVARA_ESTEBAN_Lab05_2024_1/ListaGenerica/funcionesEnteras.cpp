/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesEnteras.cpp
 * Author: esteban
 * 
 * Created on 8 de mayo de 2025, 10:14
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funcionesEnteras.h"


void * leenum(ifstream& archLeer){
    int* ptNumero= new int;
    archLeer>>*ptNumero;
    if(archLeer.eof()) return nullptr;
    
    return ptNumero;
}

void imprimenum(void* reg,ofstream &archReport){
    
    int* ptNumero= (int*)reg;
    
    archReport<<*ptNumero<<endl;
    
}

int cmpnum (const void* datoLst1,const void* datoLst2){
    int *ptNumero1=(int*)datoLst1, *ptNumero2=(int*)datoLst2;
    
    return *ptNumero1-*ptNumero2;
    
    
}