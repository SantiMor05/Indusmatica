/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesRegistros.cpp
 * Author: esteban
 * 
 * Created on 8 de mayo de 2025, 13:34
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesRegistros.h"
//2,14268463,BHD6079
//7,42302422,RWW7975
void* leeregistro(ifstream &archLeer){
    
    int *ptPedido= new int,*ptDni= new int;
    char* ptLibro;
    archLeer>>*ptPedido;
    if(archLeer.eof()) return nullptr;
    archLeer.get();
    archLeer>>*ptDni;
    archLeer.get();
    ptLibro= lecturaExacta(archLeer);
    
    
    // inicializamos
    void** registro= new void*[3]{};
    registro[0]= ptPedido;
    registro[1]= ptDni;
    registro[2]= ptLibro;
    
    return registro;
}

char * lecturaExacta(ifstream &archLeer){
    char* ptCad, buffer[100];
    int cantCar;
    
    archLeer.getline(buffer,100);
    if(archLeer.eof()) return nullptr;
    cantCar= strlen(buffer);
    ptCad= new char[cantCar+1];
    strcpy(ptCad,buffer);
    return ptCad;
    
}

void imprimeregistro(void* reg, ofstream& archReporte){
    void** registro= (void**) reg;
    int* ptPedido= (int*)registro[0],* ptDni= (int*)registro[1];
    char* ptLibro= (char*) registro[2];
    
    archReporte<<setw(10)<<*ptPedido<<setw(10)<<*ptDni<<setw(10)<<ptLibro<<endl;
    
    
}

int cmpregistro(const void* regLst1,const void* regLst2){
    void**registroLista1= (void**)regLst1;
    void**registroLista2= (void**)regLst2;
    int * ptPedido1= (int*) registroLista1[0];
    int * ptPedido2= (int*) registroLista2[0];
    
    return *ptPedido1-*ptPedido2;
   
    
    
}