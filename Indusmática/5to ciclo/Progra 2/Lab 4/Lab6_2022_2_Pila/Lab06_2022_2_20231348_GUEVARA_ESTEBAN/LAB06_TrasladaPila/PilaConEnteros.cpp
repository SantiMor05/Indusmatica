/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaConEnteros.cpp
 * Author: esteban
 * 
 * Created on 15 de mayo de 2025, 15:43
 */
#include <fstream>
using namespace std;
//
#include "PilaConEnteros.h"

int cmpnumero(const void* datA,const void* datB){
    void** datoA= (void**)datA, **datoB=(void**)datB;
    int * ptNumA= (int *) datoA[0], *ptNumB=(int*) datoB[0];
    
    return *ptNumB-*ptNumA;
 
}

void * leenumero(ifstream& archLee){
    int *ptNum= new int;
    
    archLee>>*ptNum;
    if(archLee.eof()) return nullptr;
    
    return ptNum;
    
}

void imprimenumero(void*dato,ofstream &archReport){
    
    int *ptNum=(int*)dato;
    
    archReport<<*ptNum<<endl;
    
    
}