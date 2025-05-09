/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.cpp
 * Author: esteban
 * 
 * Created on 8 de mayo de 2025, 17:17
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "ListaConEnteros.h"
//35912665,O2Z-308,22/07/2019,156
void* leenum(ifstream &archLee){
    int *ptFecha= new int,dni,dd,mm,aa,aux;
    char buffer[8],c;
    archLee>>dni;
    if(archLee.eof()) return nullptr;
    archLee.get();
    archLee.getline(buffer,8,',');
    archLee>>dd>>c>>mm>>c>>aa>>c>>aux;
    
    
    *ptFecha= aa*10000+mm*100+dd;
    
    return  ptFecha;
    
    
}

int cmpnum(const void* datLst,const void* dato){
    int* ptDato=(int*)dato, *ptDatoLista=(int*)datLst;
    
    return *ptDatoLista-*ptDato;
    
}

int obtenernum(void* dato){
    int* ptFecha=(int*)dato;
    
    return *ptFecha;
}

void imprimenum(void* datoAnterior,void* datoActual,ofstream & archReport){
    
    int* ptFechaAct= (int*) datoActual,*ptFechaAnt;
    
    if(datoAnterior==nullptr) archReport<<*ptFechaAct<<endl;
    else{
        ptFechaAnt= (int*)datoAnterior;
        if(*ptFechaAct!=*ptFechaAnt) archReport<<*ptFechaAct<<endl;
    }
    
}