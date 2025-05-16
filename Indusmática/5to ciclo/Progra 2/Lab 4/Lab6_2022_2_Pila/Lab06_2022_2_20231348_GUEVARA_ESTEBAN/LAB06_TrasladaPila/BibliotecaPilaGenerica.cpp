/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaPilaGenerica.cpp
 * Author: esteban
 * 
 * Created on 15 de mayo de 2025, 15:26
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "BibliotecaPilaGenerica.h"
#define INCREMENTO 5
enum nodo{DATO,SIG};
enum pila{CIMA,CANTIDAD};
void cargaarreglo(void* &arr,int (*cmp)(const void*,const void*),
        void* (*lee)(ifstream&),const char* nombreArch){
    
    ifstream archLee(nombreArch,ios::in);
    if (not archLee.is_open()) {
        cout<<"Error: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    
    void* reg;
    void** arrDatos;
    int cap=0,numDat=0;
    arrDatos= nullptr;
    while (true) {
        reg= lee(archLee);
        if(archLee.eof()) break;
        
        if(numDat==cap) incrementarEspacio(arrDatos,numDat,cap);
        
        //aisgnamos al arreglo en desorden
        arrDatos[numDat-1]= reg;
        numDat++;
    }
    
    // ordenamos el arreglo con qsort, Numdat -1 pq le qutamos el cero del arrelo;
    
    qsort(arrDatos,numDat-1,sizeof(void*),cmp);
    
    // guardamos el arreglo
    arr= arrDatos;

}


void  incrementarEspacio(void** &arrDatos,int &numDat,int &cap){
    
    void** arrAux;
    
    cap+= INCREMENTO;
    if(arrDatos==nullptr){
        arrDatos= new void*[cap]{};
        numDat=1;
    }else{
        arrAux= new void*[cap]{};
        for (int i = 0; arrDatos[i]; i++) {
            arrAux[i]=arrDatos[i];
        }
        delete arrDatos;
        arrDatos=arrAux; 
    }
   
}

void cargapila(void* &pl,void* arreglo){
    int numDat=0;
    void** arrDatos=(void**) arreglo;
    
    construirPila(pl);
    
    
    while (arrDatos[numDat]) numDat++;

    for (int i = 0; i < numDat; i++) {
        push(pl,arrDatos[i]);
   
    }
  
    
}

void construirPila(void* &pl){
    
    void** pila=(void**)pl;
    
    pila= new void*[2]{};
    int *ptLongitud=new int;
    *ptLongitud=0;
    pila[CANTIDAD]= ptLongitud;
    
    pl= pila;
}

void push(void* pl,void* reg){
    
    void** cima,**pila=(void**)pl;
    int* ptLongitud= (int*)pila[CANTIDAD];
    cima=(void**) pila[CIMA];
    
    //creamos un nuevo nodo;
    void** nuevoNodo= new void*[2]{};
    nuevoNodo[DATO]= reg;
    
    if(cima!=nullptr) nuevoNodo[SIG]= cima;
    pila[CIMA] = nuevoNodo;
    
    (*ptLongitud)++;
    
}

void muevepila(void* pilaini,void*&pilafin){
    void** pilaInicial =(void**)pilaini;
    void* pilaAux;
    construirPila(pilaAux);
    construirPila(pilafin);
    int * ptLongitud= (int*) pilaInicial[CANTIDAD];
    
    Hanoi(*ptLongitud,pilaini,pilaAux,pilafin);
    

}


void Hanoi(int n,void* pilaOrin,void* pilaAux,void*pilaDest){
    
    void* registro;   
    

    
    if(n==1){
        registro= pop(pilaOrin);
        push(pilaDest,registro); 
        return;
    }else{
        
        Hanoi(n-1,pilaOrin,pilaDest,pilaAux);
        
        push(pilaDest,pop(pilaOrin));
        
        Hanoi(n-1,pilaAux,pilaOrin,pilaDest);
//        
//        
    }
//    
}


 void* pop(void* pl){
    
    void** pila = (void**) pl;
    void** cima= (void**) pila[CIMA];
    int* ptLongitud= (int*) pila[CANTIDAD];
    
    //aqui usarias si pilaVacia si es necesario crear su funcion
    if(cima==nullptr){
        cout<<"Error: No se puede extraer una pila vacia"<<endl;
        exit(1);
    }
    
    void* registro;
    registro= cima[DATO];
    pila[CIMA]= cima[SIG];
    
    delete cima;
    
    (*ptLongitud)--;
    
    return registro;
            
 }
 
void imprimepila(void *pilafin,void (*imprime)(void*,ofstream&),
         const char* nombreArch){
    
    ofstream archReporte(nombreArch,ios::out);
    if (not archReporte.is_open()) {
        cout<<"Error: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    archReporte<<setprecision(2)<<fixed;
    void** pila=(void**)pilafin;
    void** nodo= (void**)pila[CIMA];
    
    //Impresion Como si fuera lista
    while (nodo) {
        
        imprime(nodo[DATO],archReporte);
        
        nodo= (void**)nodo[SIG];
    }
    
    //Por si te piden emprimir respetando la pila
//    void* reg;
//    while (pila[CIMA]!=nullptr) {
//        reg= pop(pilafin);
//        imprime(reg,archReporte);
//        
//        void** pila=(void**)pilafin;
//        
//    }
//    
    
//    int* ptLong=(int*)pila[CANTIDAD];
//    cout<<*ptLong;
 }