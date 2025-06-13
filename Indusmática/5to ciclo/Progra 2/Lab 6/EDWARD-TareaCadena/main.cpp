/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 1 de junio de 2025, 11:15 AM
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Cadena.h"

using namespace std;
#define INCRE 2

void incrementar(Cadena*&personas,int &nd,int &capa){
    
    capa+=INCRE;
    if(not personas){
        personas=new Cadena[capa];
        nd=1;
    }
    else{
        Cadena*aux=new Cadena[capa];
        int i;
        for (i = 0; i < nd-1; i++) {
            aux[i]=personas[i];
        }
        delete[]personas;
        personas=aux;
    }
}

void completar(Cadena*&personas,int &nd,const char*nombArch){
    
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch; exit(1);
    }
    personas=nullptr;
    nd=0;
    int capa=0;
    char cad[60];
    while(true){
        arch>>cad;
        if(arch.eof())break;
        if(nd==capa)incrementar(personas,nd,capa);
        personas[nd-1].append(cad);
        while(arch.get()!='\n'){
            personas[nd-1].append("/");
            arch>>ws>>cad;
            personas[nd-1].append(cad);
        }
        nd++;
    }
}
    
void imprimirPersona(Cadena&persona){
    
    persona.print();
}

void imprimir(Cadena*personas,const char*nombArch){
    
   
    for (int i = 0; personas[i].length(); i++) {
        imprimirPersona(personas[i]);
    }

}

int comparar(const void*a,const void*b){
    
//    void**ai=(void**)a,**bi=(void**)b;
//    Cadena cad1=(Cadena)*ai,cad2=(Cadena)*bi;
//    return cad1.compare(cad2);
    Cadena cad1=*(Cadena*)a,cad2=*(Cadena*)b;
    return cad1.compare(cad2);
    
}

int main(int argc, char** argv) {

    Cadena a,b;
    Cadena c;
//    
    a="Juan";
    b="Edward";
//    a.swap(b);
//    a.print();
//    b.print();
//    c=a+b;
////    aux llega ahi
//    c.print();
    
    c=a+b;
//    c.print();
    
    Cadena*personas;
    int nd;
    completar(personas,nd,"personas_ampliado.txt");
    qsort(personas,nd-1,sizeof(Cadena),comparar);
    imprimir(personas,"reporte.txt");
    
    return 0;
}

