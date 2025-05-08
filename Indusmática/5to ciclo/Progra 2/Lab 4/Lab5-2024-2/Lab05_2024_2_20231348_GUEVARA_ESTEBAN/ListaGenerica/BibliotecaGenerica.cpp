/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.cpp
 * Author: esteban
 * 
 * Created on 7 de mayo de 2025, 20:48
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaGenerica.h"
enum dupla{SECCION,ARREGLO};
enum regnumero{INDICE,ELEMENTO};
enum lista{CABEZA,COLA,NUMERO};
enum nodo{DATO,SIG};

void crealista(void* &lista,void* (*leer)(ifstream &),
        const char* nombreArch){
    ifstream archLeer(nombreArch,ios::in);
    if (not archLeer.is_open()) {
        cout<<"ERROR no se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }

    void * reg;
    lista = nullptr;
    while (true) {
        reg= leer(archLeer);
        if(archLeer.eof()) break;
        insertarLista(reg,lista);
    }
    
}

void insertarLista(void* reg,void* &lst){
    
    int *numero;
    void **nuevoNodo,**ultimoNodo,**lista;
    lista=(void**) lst;
    
    void** dupla= new void*[2]{};
    dupla[0]= reg;
    dupla[1]= new void*[20]{};
    
    //Creacion del nodo
    nuevoNodo= new void*[2]{};
    nuevoNodo[DATO]= dupla;
    nuevoNodo[SIG]= nullptr;
    
    
    // Iinicializamos cabeza
    if(lista==nullptr){
        lista = new void*[3]{};
        int*ptNumDat= new int;
        *ptNumDat=1;
        lista[CABEZA]= nuevoNodo;
        lista[NUMERO]= ptNumDat;
        lista[COLA]= nuevoNodo;
        lst= lista;
    }else{
        
        ultimoNodo= (void**) lista[COLA];

        ultimoNodo[SIG]= nuevoNodo;
        
        lista[COLA]= nuevoNodo;
        
        numero =(int*)lista[NUMERO];
        (*numero)++;
    }
       
}


void cargalista(void* lista,int (*comprueba)(const void*,const void*),
        void * (*leereg)(ifstream &),const char* nombreArch){
    ifstream archLeer(nombreArch,ios::in);
    if (not archLeer.is_open()) {
        cout<<"ERROR no se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    
    
    void* reg;
    
    while (true) {
        reg = leereg(archLeer);
        if(archLeer.eof()) break;
        
        insertarArreglo(lista,comprueba,reg);
    }

    
}

void insertarArreglo(void *lst,
        int (*comprueba)(const void*,const void*),void* reg){
    
    void** nodo,**lista,**registro;
    registro= (void**)reg;
    lista= (void**)lst;
    nodo = (void**)lista[CABEZA];
    
    while (nodo) {
        if(comprueba(nodo[DATO],registro[INDICE])==0){
            
            insertarElemento(nodo[DATO],registro[ELEMENTO]);

            return;
        }
        
        nodo= (void**)nodo[SIG];        
    }

}

void insertarElemento(void* dupla,void *elemento){
    void** registro=(void**)dupla;
    void** arreglo= (void**)registro[ARREGLO];
    int numDat=0;
    while(arreglo[numDat]) numDat++;
    
    arreglo[numDat]= elemento;
    
}

void muestralista(void* lst,void (*imprime)(void*,ofstream &),const char* nombreArch){
    ofstream archReporte(nombreArch,ios::out);
    if (not archReporte.is_open()) {
        cout<<"ERROR no se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    void** nodo,**lista;
    lista= (void**)lst;
    nodo = (void**)lista[CABEZA];
    while (nodo) {
        
        imprime(nodo[DATO],archReporte);
        
        nodo= (void**)nodo[SIG];
    }

    
}