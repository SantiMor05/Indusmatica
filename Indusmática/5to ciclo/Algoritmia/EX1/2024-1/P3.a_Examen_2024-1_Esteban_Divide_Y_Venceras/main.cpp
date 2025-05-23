/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 22 de mayo de 2025, 16:01
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funcionesAux.h"

/*
 * 
 */

enum reg{ID,IMPACTO,RIESGO};

void *lee(ifstream &archLee){
    int *ptId= new int,*ptImpacto= new int,*ptRiesgo=new int;
    archLee>>*ptId;
    if(archLee.eof()) return nullptr;
    archLee>>*ptImpacto>>*ptRiesgo;
    
    void** reg = new void*[3];
    reg[ID]= ptId;
    reg[IMPACTO]= ptImpacto;
    reg[RIESGO]= ptRiesgo;

    return reg;
    
}

void cambiarPos(void *&datA,void* &datB){
    
    void * aux;
    aux= datA;
    datA = datB;
    datB = aux;
    
    
}

void qsort(void** arrDatos,int izq,int der,int(*cmp)(const void*,const void*)){
    int limite=izq;
    if(izq>=der) return;
    
    cambiarPos(arrDatos[izq],arrDatos[(izq+der)/2]);
    
    for (int i = izq+1; i <= der; i++) {
        if(cmp(arrDatos[izq],arrDatos[i])>0){
            cambiarPos(arrDatos[++limite],arrDatos[i]);
        }

    }

    cambiarPos(arrDatos[izq],arrDatos[limite]);
    qsort(arrDatos,izq,limite-1,cmp);
    qsort(arrDatos,limite+1,der,cmp);
    
    
}

void imprimir(void** arrDatos,int numDat){
    int *ptId,*ptImpacto,*ptRiesgo;
    void **reg;
        
    for (int i = 0; i < numDat; i++) {
        reg= (void**)arrDatos[i];
        int *ptId= (int*)reg[0];
        int *ptImpacto= (int*)reg[1];
        int *ptRiesgo= (int*)reg[2];
        
        cout<<*ptId<<" "<<*ptImpacto<<" "<<*ptRiesgo<<"    ";
    }
    cout<<endl;
    

    
    
}

int main(int argc, char** argv) {

    int cantDatos=7;
    void** arrDatos= new void*[cantDatos]{};
    
    ifstream archLee("Datos.txt",ios::in);
    if (not archLee.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo"<<endl;
        exit(1);
    }
    
    
    int numDat=0;
    void*reg; 
    while (true) {
        reg= lee(archLee);
        if(archLee.eof()) break;
        arrDatos[numDat]= reg;
        numDat++;
    }
    cout<< "Lista de riesgos: (ID - Impacto - Nivel de Riesgo)"<<endl;
    imprimir(arrDatos,numDat);
    
    cout<< "Por Riesgo"<<endl;
    qsort(arrDatos,0,numDat-1,cmpRiesgo);
    imprimir(arrDatos,numDat);
        
    cout<< "Por Impacto"<<endl;
    qsort(arrDatos,0,numDat-1,cmpImpacto);
    imprimir(arrDatos,numDat);
    
    cout<< "Por ID"<<endl;
    qsort(arrDatos,0,numDat-1,cmpID);
    imprimir(arrDatos,numDat);
    
    
    
    
    
    return 0;
}



