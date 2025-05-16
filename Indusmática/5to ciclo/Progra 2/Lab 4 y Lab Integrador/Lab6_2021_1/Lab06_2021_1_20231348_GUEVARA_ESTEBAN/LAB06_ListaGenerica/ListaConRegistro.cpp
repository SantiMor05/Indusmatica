/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistro.cpp
 * Author: esteban
 * 
 * Created on 8 de mayo de 2025, 20:14
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaConRegistro.h"
// 81485316,E1N-544,31/08/2019,159

enum reg{LICENCIA,PLACA,FECHA,INFRACCION};

void* leeregistro(ifstream &archLee){
    int *ptLicencia= new int,dd,mm,aa,*ptInfraccion= new int,*ptFecha= new int;
    char *ptPlaca,c;
    archLee>>*ptLicencia;
    if(archLee.eof()) return nullptr;
    archLee.get();
    ptPlaca= lecturaExacta(archLee,',');
    archLee>>dd>>c>>mm>>c>>aa>>c>>*ptInfraccion;
    *ptFecha= aa*10000+mm*100+dd;
    //
    void** registro= new void*[4]{};
    registro[LICENCIA]= ptLicencia;
    registro[PLACA]= ptPlaca;
    registro[FECHA]= ptFecha;
    registro[INFRACCION]= ptInfraccion;


    return registro;
}


char* lecturaExacta(ifstream &archLee,char delim){
    char*ptCad,buffer[50];
    int cantCar;
    archLee.getline(buffer,50,delim);
    cantCar= strlen(buffer);
    ptCad= new char[cantCar+1];
    strcpy(ptCad,buffer);
    return ptCad;
}

int cmpregistro(const void* regLista,const void* reg){
    void**registroLista=(void**) regLista, **registro=(void**)reg;
    int* ptFechLista= (int*)registroLista[FECHA];
    int* ptFechReg= (int*)registro[FECHA];
    
    return *ptFechLista-*ptFechReg;
    
}


void imprimeregistro(void* regAnt,void* reg,ofstream& archReporte){
    void** regActual= (void**) reg, **regAnterior;
    int* ptFechaActual,fechEncaActual,fechaEncaAnterior,*ptFechaAnterior;
        ptFechaActual=(int*)regActual[FECHA];
        fechEncaActual= (*ptFechaActual)/100;
    if(regAnt==nullptr){
        imprimirEncabezado(archReporte,fechEncaActual);
        imprimir(archReporte,regActual);
    }else{
        regAnterior= (void**) regAnt;
        ptFechaAnterior= (int*)regAnterior[FECHA];
        fechaEncaAnterior= (*ptFechaAnterior)/100;
        if(fechaEncaAnterior!=fechEncaActual){
            imprimirEncabezado(archReporte,fechEncaActual);
        }
        imprimir(archReporte,regActual);
    }
    
    
}

void imprimirEncabezado(ofstream &archReporte,int fechEncaActual){
    
    archReporte<<"Año-Mes: "<<fechEncaActual<<endl;
    archReporte<<left<<setw(15)<<"FECHA"<<setw(15)<<"LICENCIA"<<setw(15)
            <<"LICENCIA"<<setw(15)<<"NOMBRE"<<setw(15)<<"FALTA"<<endl;
    impresionLinea(archReporte,'=');
    
}

void impresionLinea(ofstream &archReporte,char car ){
    for (int i = 0; i < 130; i++) {
        archReporte<<car;
    }
    archReporte<<endl;   
}

void imprimir(ofstream &archReporte,void** regActual){
    int* ptFecha= (int*)regActual[FECHA];
    char* ptPlaca= (char *)regActual[PLACA];
    int* ptLicencia= (int *)regActual[LICENCIA];
    int* ptInfraccion= (int *)regActual[INFRACCION];
    
        archReporte<<left<<setw(15)<<*ptFecha<<setw(15)<<*ptInfraccion<<setw(15)
            <<*ptLicencia<<setw(15)<<" "<<setw(15)<<ptPlaca<<endl;
    
}