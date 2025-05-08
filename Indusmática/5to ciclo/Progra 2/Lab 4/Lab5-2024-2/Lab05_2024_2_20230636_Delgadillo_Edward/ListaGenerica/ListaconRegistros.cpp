/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaconRegistros.cpp
 * Author: alulab14
 * 
 * Created on 7 de mayo de 2025, 10:49 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"
#include "ListaconRegistros.h"

using namespace std;

void*leeregistros(ifstream &arch){
    
    char*codigo,*nombre,*vehi;
    codigo=leeCadena(arch,',');
    if(arch.eof())return nullptr;
    nombre=leeCadena(arch,',');
    vehi=leeCadena(arch,'\n');
    void**registro=new void*[3]{};
    registro[0]=codigo;
    registro[1]=nombre;
    registro[2]=vehi;
    return registro;
}

char*leeCadena(ifstream &arch,char deli){
    
    char aux[500],*p;
    arch.getline(aux,500,deli);
    if(arch.eof())return nullptr;
    p=new char[strlen(aux)+1];
    strcpy(p,aux);
    return p;
}

void* leeordenes(ifstream &arch){
    
//    12484697,2,AD-546,LAF361
    int dni;
    char*codigo,*repar,c;
    arch>>dni;
    if(arch.eof())return nullptr;
    int*ptrDni=new int(dni),*cant=new int;
    
    arch>>c>>*cant>>c;
    codigo=leeCadena(arch,',');
    repar=leeCadena(arch,'\n');
    void**linea=new void*[2]{};
    linea[0]=repar;
    void**cliente=new void*[3]{};
    cliente[0]=ptrDni;
    cliente[1]=cant;
    cliente[2]=codigo;
    linea[1]=cliente;
    return linea;
}

int compruebaregistro(const void*a,const void*b){
    
    void**bi=(void**)b;
    char*bii=(char*)bi[0],*aii=(char*)a;    
    return strcmp(bii,aii);
}
        
void imprimeregistros(const void*dup,ofstream &arch){
    
    void**dupla=(void**)dup;
    void**repar=(void**)dupla[0];
    char*codigo=(char*)repar[0],*nombre=(char*)repar[1];
    
    arch<<codigo<<"  "<<nombre<<endl<<"Ordenes:"<<endl;
    void**ordenes=(void**)dupla[1];
    if(ordenes){
        int*dni,*cant;
        char*producto;
        void**orden;
        for (int i = 0; ordenes[i]; i++) {
            orden=(void**)ordenes[i];
            dni=(int*)orden[0];
            cant=(int*)orden[1];
            producto=(char*)orden[2];
            arch<<*dni<<"  "<<*cant<<"  "<<producto<<endl;
//            arch<<*dni<<"  "<<*cant<<"  "<<producto<<endl;
        }
    }
    arch<<endl<<endl;

}