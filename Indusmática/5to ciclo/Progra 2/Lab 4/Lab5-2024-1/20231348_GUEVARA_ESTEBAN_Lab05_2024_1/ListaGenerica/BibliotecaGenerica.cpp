/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: esteban
 * 
 * Created on 8 de mayo de 2025, 10:09
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaGenerica.h"

enum lista{CABEZA,COLA};
enum nodo{DATO,SIG};

void crealista(void* &lista,void* (*lee)(ifstream &),const char* nombreArch){
    ifstream archLee(nombreArch,ios::in);
    if (not archLee.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
  
    void* reg;
    lista= nullptr;
    
    inicializamosLista(lista);
    
    while (true) {
        reg= lee(archLee);
        if(archLee.eof()) break;
        
        insertalista(lista,reg);
        
    }

    
}

void inicializamosLista(void*& lst){
    void** lista;
    lista= new void*[2]{};
    lst= lista;
    
}

void insertalista(void* lst,void* reg){
    void** lista=(void**) lst;
    
    // creamos nodo y lo relacionamos con el registro
    void** nuevoNodo,**ultimoNodo;
    nuevoNodo= new void*[2]{};    
    nuevoNodo[DATO]= reg;
    nuevoNodo[SIG]= nullptr;
    
    
    if(listaVacia(lst)){
        
        //Insertamos primer dato
        lista[CABEZA]= nuevoNodo;
        lista[COLA]= nuevoNodo;

    }else{
        
        //cuando ya hay datos
        ultimoNodo= (void**)lista[COLA];
        //conecto a la lista
        ultimoNodo[SIG]= nuevoNodo;
        //hago del nuevo nodo cola
        lista[COLA]= nuevoNodo;
        
    }
    
}

bool  listaVacia(void* lst){
    void** lista= (void**) lst;
    if(lista[CABEZA]==nullptr) return true;
    else return false;
}

void imprimelista(void* lst,void (*imprime)(void*,ofstream&),
        const char* nombreArch){
    ofstream archReport(nombreArch,ios::out);
    if (not archReport.is_open()) {
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
  
    void** lista=(void**) lst,**nodo;
    
    nodo= (void**)lista[CABEZA];
    
    while (nodo) {
        
        imprime(nodo[DATO],archReport);
        
        nodo= (void**)nodo[SIG];
    }
    
}

void combinalista(void* lst1,void*lst2,void*& lstFinal,
        int (*cmp)(const void*,const void*)){
    int comparacion;
    void** lista1,**lista2,**listaFinal,**nodoLst1,**nodoLst2, *regFinal;
   

    inicializamosLista(lstFinal);
    listaFinal=(void**) lstFinal;
    
    //
    
    while (!listaVacia(lst1) and !listaVacia(lst2)) {
        
        lista1=(void**) lst1;
        lista2=(void**) lst2;
        nodoLst1= (void **) lista1[CABEZA];
        nodoLst2= (void**) lista2[CABEZA];
        
        comparacion= cmp(nodoLst1[DATO],nodoLst2[DATO]);
        if(comparacion==0){
            // perdemos intencionalmente el registro
            regFinal= quitarlista(lst1);
        }
        if(comparacion<0){
            // significa q saco el primer nodo de lista1
            regFinal= quitarlista(lst1);
            //inserto a mi Final
            insertalista(listaFinal,regFinal);
        }
        else{
            regFinal= quitarlista(lst2);
            
            insertalista(listaFinal,regFinal);
        }
        
    }
    
    // caso en q sobre;
    void** ultimoNodo= (void**) listaFinal[COLA];
    if(!listaVacia(lst2)){
        ultimoNodo[SIG]= lista2[CABEZA];
        listaFinal[COLA]= lista2[COLA];
    }
    if(!listaVacia(lst1)){
        ultimoNodo[SIG]= lista1[CABEZA];
        listaFinal[COLA]= lista1[COLA];
    }
    
    lstFinal= listaFinal;
}

void * quitarlista(void* &lst){
    
    void** lista = (void**) lst,**nodoInicial,*registro;
    nodoInicial=(void**)lista[CABEZA];
    
    registro= nodoInicial[DATO];
    
    
    //hacemos q la cabeza apunte al siguiente nodo
    lista[CABEZA]=nodoInicial[SIG];
    
    //deleteamos al nodo inicial;
    delete nodoInicial;
    
    return registro;
}