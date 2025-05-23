/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.cpp
 * Author: esteban
 * 
 * Created on 22 de mayo de 2025, 16:21
 */

#include "funcionesAux.h"

int cmpID(const void* datA, const void* datB){
    void ** datoA= (void**)datA;
    void ** datoB= (void**)datB;
    int *ptIdA= (int*)datoA[0];
    int *ptIdB= (int*)datoB[0];
    
    
    return *ptIdA-*ptIdB;
    
}

int cmpImpacto(const void* datA, const void* datB){
    void ** datoA= (void**)datA;
    void ** datoB= (void**)datB;
    int *ptA= (int*)datoA[1];
    int *ptB= (int*)datoB[1];
    
    
    return *ptA-*ptB;
    
}


int cmpRiesgo(const void* datA, const void* datB){
    void ** datoA= (void**)datA;
    void ** datoB= (void**)datB;
    int *ptA= (int*)datoA[2];
    int *ptB= (int*)datoB[2];
    
    
    return *ptA-*ptB;
    
}