/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistro.cpp
 * Author: 00123
 * 
 * Created on 8 de mayo de 2025, 04:54 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaConRegistro.h"

using namespace std;
#define LINEA 90

void*leeregistro(ifstream &arch){
    
    int licencia;
    arch>>licencia;
    if(arch.eof())return nullptr;
    arch.get();
    int*ptrLice=new int(licencia);
    char*placa=new char[8],c;
    arch.getline(placa,8,',');
    int dd,mm,aa;
    int *numero=new int,*fecha=new int;
    arch>>dd>>c>>mm>>c>>aa>>c>>*numero;
    *fecha=aa*10000+mm*100+dd;
    
    void**registro=new void*[4]{};
    registro[0]=ptrLice;
    registro[1]=placa;
    registro[2]=fecha;
    registro[3]=numero;
    return registro;
}

int cmpregistro(const void*a,const void*b){
    
    void**ai=(void**)a,**bi=(void**)b;
    int*fechaA=(int*)ai[2],*fechaB=(int*)bi[2];
    return *fechaA-*fechaB;
}

void imprimeregistro(const void*reg,ofstream &archOut){
    
    
    void**registro=(void**)reg;
    //    35912665,O2Z-308,22/07/2019,156
    int*licencia=(int*)registro[0];
    char*placa=(char*)registro[1];
    int fecha=*(int*)registro[2];
    int*falta=(int*)registro[3];
    
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    
    static int i=0;
    static int mesGuardado=mm;
    
    if(i==0 or mesGuardado!=mm){
        archOut<<endl<<"Año: "<<aa<<"  Mes: "<<right<<setfill('0')<<setw(2)<<mm<<endl<<
                setfill(' ');
        archOut<<left<<setw(10)<<"FECHA"<<"  "<<"LICENCIA  "<<setw(60)<<
                "         NOMBRE"<<"  FALTA"<<endl;
        imprimeLinea(archOut,LINEA,'=');
        mesGuardado=mm;
    }
    i++;
    ifstream archIn("Conductores.csv",ios::in);
    if(not archIn.is_open()){
        cout<<"Error en "<<"Conductores.csv"; exit(1);
    }

    char*nombre=buscarNombre(*licencia,archIn);
    
    if(nombre){
        archOut<<aa<<'/'<<right<<setfill('0')<<setw(2)<<mm<<'/'<<setw(2)<<dd<<"  "<<
                setfill(' ')<<*licencia<<"  "<<left<<setw(60)<<nombre<<"  "<<*falta<<endl;
    }
}

void imprimeLinea(ofstream &arch,int n,char c){
    
    for (int i = 0; i < n; i++) {
        arch<<c;
    }
    arch<<endl;
}

char*buscarNombre(int buscado,ifstream &arch){
    
    int licencia;    
    char nombre[60],*p;
    while(true){
        arch>>licencia;
        if(arch.eof())break;
        arch.get();
        arch.getline(nombre,60);
        if(licencia==buscado){
            p=new char[strlen(nombre)+1];
            strcpy(p,nombre);
            return p;
        }
    }
    return nullptr;
}
