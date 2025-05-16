/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arreglos_genericos.cpp
 * Author: esteban
 * 
 * Created on 15 de mayo de 2025, 09:54
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "arreglos_genericos.h"
#define INCREMENTO 5

enum registro{COD,NOMBRE,ROL,CATEG,PUNTAJE};

void llenar_arreglo_heroes(void *& arreglo_heroes,int& cantidad_total_heroes,
            const char* nombreArch){
    
    ifstream archLee(nombreArch,ios::in);
    if(not archLee.is_open()){
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    int cap=0;
    void * registro, **arrHeroes= (void**) arreglo_heroes;
    cantidad_total_heroes=0;
    arrHeroes= nullptr;
    
    while (true) {
        
        registro= lectura(archLee);
        
        if(archLee.eof()) break;
        
        if(cantidad_total_heroes==cap) 
            aumentarEspacioArr(arrHeroes,cap,cantidad_total_heroes);
        
        arrHeroes[cantidad_total_heroes-1]= registro;
        
        cantidad_total_heroes++;
    }
    // eliminamos el 0
    cantidad_total_heroes--;
    
    arreglo_heroes = arrHeroes;
    
}
//  
//133,Malzahar,MID,A,53.65
//195,Akali,TOP,B,41.14
void *lectura(ifstream &archLee){
    int* ptCodigo= new int ;
    char * ptNombre,* ptRol, *ptCategoria;
    double *ptPuntaje;
    
    archLee>>*ptCodigo;
    if(archLee.eof()) return nullptr;
    
    
    archLee.get();
    ptNombre= lecturaExacta(archLee,',');
    ptRol= lecturaExacta(archLee,',');
    ptCategoria= lecturaExacta(archLee,',');
    
//    ptCategoria= new char;
//    archLee>>*ptCategoria;
//    archLee.get();
//    
    ptPuntaje= new double;
    archLee>>*ptPuntaje;
            
    void** registro= new void*[5]{};
    
    registro[COD]= ptCodigo;
    registro[NOMBRE]= ptNombre;
    registro[ROL]= ptRol;
    registro[CATEG]= ptCategoria;
    registro[PUNTAJE]= ptPuntaje;
    
    return registro;
    
}

char * lecturaExacta(ifstream &archLee,char delim){
    char *ptCad, buffer[100];
    int cantCad;
    archLee.getline(buffer,100,delim);
    if(archLee.eof()) return nullptr;
    cantCad= strlen(buffer);

    ptCad= new char[cantCad+1];
    strcpy(ptCad,buffer);
    return ptCad;
}


void aumentarEspacioArr(void** &arrHeroes,int &cap,int &numDat){
    

    void** arrAux;
    
    cap+= INCREMENTO;
    
    if(arrHeroes== nullptr){
        arrHeroes= new void*[cap]{};
        numDat=1;
    }else{
        arrAux= new void*[cap]{};
        
        for (int i = 0; arrHeroes[i]; i++) {
            arrAux[i]= arrHeroes[i];
        }

        delete arrHeroes;
        arrHeroes= arrAux;
    }

}

int cmp_multicriterio_void( const void* datoA, const void* datoB){
    void** datA= (void**) datoA, ** datB=(void**) datoB;
    void** regDatA=(void**) datA[0],**regDatB =(void**) datB[0];
    char* ptNomA= (char*) regDatA[NOMBRE], *ptNomB= (char*) regDatB[NOMBRE];
    double *ptPunA = (double*) regDatA[PUNTAJE], 
            *ptPunB= (double*) regDatB[PUNTAJE];
    int cmp = strcmp(ptNomA,ptNomB);
    
    if(cmp==0)
        return *ptPunB-*ptPunA;
    return cmp;
        
}

