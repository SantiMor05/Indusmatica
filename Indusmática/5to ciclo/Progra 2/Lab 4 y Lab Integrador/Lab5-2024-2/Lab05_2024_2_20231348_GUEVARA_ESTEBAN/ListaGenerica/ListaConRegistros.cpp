/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistros.cpp
 * Author: esteban
 * 
 * Created on 7 de mayo de 2025, 23:46
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaConRegistros.h"

//JNV387,Justino Norabuena Virginia Karina,Motocicleta
void* leeregistros(ifstream &archLee){
    
    char* ptCodigo,*ptNombre,*ptUnidad;
    
    ptCodigo= lecturaExacta(archLee,',');
    if(archLee.eof()) return nullptr;
    ptNombre= lecturaExacta(archLee,',');
    ptUnidad= lecturaExacta(archLee);
    
    void** registro= new void*[3]{};
    
    registro[0]=ptCodigo;
    registro[1]=ptNombre;
    registro[2]=ptUnidad;
    
    return registro;
    
}


char* lecturaExacta(ifstream &archLee,char delim){
    char* ptCad, buffer[200];
    int cantCad;
    
    archLee.getline(buffer,200,delim);
    if(archLee.eof()) return nullptr;
    cantCad= strlen(buffer);
    ptCad= new char[cantCad+1];
    strcpy(ptCad,buffer);
    
    return ptCad;   
}
//
//12484697,2,AD-546,LAF361
//12484697,1,PO-751,LAF361
void * leeordenes(ifstream &archLee){
    char *ptPlato,*ptRepartidor;
    int* ptDni= new int,*ptCantidad=new int;
    archLee>>*ptDni;
    if(archLee.eof()) return nullptr;
    archLee.get();
    archLee>>*ptCantidad;
    archLee.get();
    ptPlato= lecturaExacta(archLee,',');
    ptRepartidor= lecturaExacta(archLee);
    
    void** datos= new void*[3]{};
    datos[0]= ptDni;
    datos[1]= ptCantidad;
    datos[2]= ptPlato;
    
    void** registro= new void*[2]{};
    registro[0]= ptRepartidor;
    registro[1]= datos;
    
    return registro;
}

int compruebaregistro(const void* datoNodo,const void*datoRegistro){
    void** duplaNodo=(void**) datoNodo;
    void** datosRep=(void**) duplaNodo[0];
    char* ptCodNodo= (char*) datosRep[0],*ptCodDato=(char*)datoRegistro;
    
    return strcmp(ptCodDato,ptCodNodo);
}

void imprimeregistros(void* dup,ofstream &archReport){
    void** dupla =(void**) dup,**arreglo,**datosRep;
    
    datosRep = (void**)dupla[0];
    arreglo= (void**) dupla[1];
    char* ptRepartidor= (char*)datosRep[0];
    char* ptNombre= (char*)datosRep[1];
    
    archReport<<left<<setw(15)<<ptRepartidor<<setw(60)<<ptNombre<<endl;
    archReport<<"Ordenes: "<<endl;
    // emprime solo si hay algo en el arreglo
    if(arreglo) impremePedidos(arreglo,archReport);
    
    
    
    
    
}

void impremePedidos(void** arreglo,ofstream &archReport){
    
    void **datosPed;
    char* ptPlato;
    int* ptCantidad,*ptDni;
    for (int i = 0; arreglo[i]; i++) {
        datosPed= (void**) arreglo[i];
        ptPlato= (char*) datosPed[2];
        ptCantidad= (int*) datosPed[1];
        ptDni= (int*) datosPed[0];
        
//        
      archReport<<setw(15)<<*ptDni<<setw(15)<<*ptCantidad<<setw(15)<<
                ptPlato<<endl;
    }
    
}