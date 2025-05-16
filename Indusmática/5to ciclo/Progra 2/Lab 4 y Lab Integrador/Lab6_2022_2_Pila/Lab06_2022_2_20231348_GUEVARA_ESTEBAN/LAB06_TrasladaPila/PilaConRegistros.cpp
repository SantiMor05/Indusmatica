/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaConRegistros.cpp
 * Author: esteban
 * 
 * Created on 15 de mayo de 2025, 22:36
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConRegistros.h"

enum registro{COD,NOMBRE,PESO};
void* leeregistro(ifstream& archLee){
    int *ptCod=new int;
    char*ptNombre;
    double *ptPeso;
    
    archLee>>*ptCod;
    
    if(archLee.eof()) return nullptr;
    
    archLee.get();
    ptNombre= lecturaExacta(archLee,',');
    
    ptPeso= new double;
    archLee>>*ptPeso;
    
    void** registro= new void*[3]{};
    
    registro[COD]= ptCod;
    registro[NOMBRE]= ptNombre;
    registro[PESO]= ptPeso;
    
    return registro;
    
}

char* lecturaExacta(ifstream &archLee,char delim){
    char *ptCad, buffer[100];
    int cantCad;
    archLee.getline(buffer,100,delim);
    if(archLee.eof()) return nullptr;
    cantCad= strlen(buffer);

    ptCad= new char[cantCad+1];
    strcpy(ptCad,buffer);
    return ptCad;
}

int cmpregistro(const void* dA, const void* dB){
    void** datoA=(void**)dA,**datoB=(void**)dB;
    void** regA= (void**)datoA[0],** regB= (void**)datoB[0];
    double* ptPesoB= (double*)regB[PESO],*ptPesoA= (double*)regA[PESO];
    
    return *ptPesoB-*ptPesoA;
}

void imprimeregistro(void* reg,ofstream& archReporte){
    void** registro= (void**)reg;    
    int *ptCod=(int*) registro[COD];
    char*ptNombre=(char*)registro[NOMBRE];
    double *ptPeso=(double*) registro[PESO];
    
    static int i=0;
    if(i==0){
        archReporte<<left<<setw(15)<<"CODIGO"<<setw(60)<<"NOMBRE MEDICAMENTO"<<
                right<<setw(15)<<"PESO"<<endl;
        i++;
    }
    
    archReporte<<left<<setw(15)<<*ptCod<<setw(60)<<ptNombre<<
                right<<setw(15)<<*ptPeso<<endl;
}