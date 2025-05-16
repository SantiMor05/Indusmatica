/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listas_genericas.cpp
 * Author: esteban
 * 
 * Created on 15 de mayo de 2025, 11:34
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "listas_genericas.h"

enum registro{COD,NOMBRE,ROL,CATEG,PUNTAJE};

enum nodo{DATO,SIG};
enum lista{CAB,COLA};

void crear_lista_heroes(void* heroes,void* &lista,void* (*lee_heroe)
    (void*,int)){
    void** arrHeroes= (void**) heroes;
    void* registro;
    int numDat=0;
    
    while(arrHeroes[numDat]) numDat++;
    
    construirLista(lista);
        
 
    while (true) {
        
        registro= lee_heroe(heroes,numDat);
        if(registro==nullptr) break;
        insertarLista(lista,registro);
        
    }

    
    
}

void construirLista(void* &lst){
    
    void** lista = (void**) lst;
    
    lista = new void*[2]{};
    
    lst= lista;
            
}

void* lee_heroe(void *heroes,int numDat){
    
    void** arrHeroes= (void**) heroes,*registro=nullptr;
    
    

    for (int i = 0; i<numDat ; i++) {
        if(arrHeroes[i]!=nullptr){
            // quito el dato
            registro= arrHeroes[i];
            
            // vuelvo ese espacio null
            
            arrHeroes[i]= nullptr;
            //rompo el for
            break;
            
        }

    }
    
    if(registro==nullptr) delete arrHeroes;
    
    return registro;

}


void insertarLista(void* lst,void* registro){
    
    void** lista=(void**) lst,** ultimoNodo;
    
    //creamos nuevo
    void** nuevoNodo= new void*[2]{};
    nuevoNodo[DATO]= registro;
    
    if(lista[CAB]==nullptr){
        
       lista[CAB]= nuevoNodo;
       lista[COLA]= nuevoNodo;
        
    }else{
       
        ultimoNodo= (void**) lista[COLA];
        
        ultimoNodo[SIG]= nuevoNodo;
        
        lista[COLA]= nuevoNodo;
    }
    
    
}

void imprimir_lista_heroes(void* lst, 
        void (*imprimir_registro)(void*,ofstream &)){
    
    ofstream archReporte("Reporte-Heroes.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se ha podido abrir el archivo Reporte-Heroes.txt"<<endl;
        exit(1);
    }
    
    
    void** lista=(void**)lst;
    void** nodo=(void**) lista[CAB];
    int contador=0;
    
    archReporte<<setprecision(2)<<fixed;
    
    archReporte<<left<<setw(20)<<"NOMBRE"<<setw(20)<<"ROL"<<setw(20)<<"CATEGORIA"
            <<setw(20)<<"PUNTAJE"<<setw(20)<<right<<"CODIGO"<<endl;
    while (nodo) {
        imprimir_registro(nodo[DATO],archReporte);
        
        contador++;
        nodo= (void**) nodo[SIG];
    }
    archReporte<<"Cantidad de Heroes: "<<contador;  
}

void imprimir_registro_heroe(void* reg,ofstream & archReporte){
    
    void** registro=(void**)reg;
    int* ptCodigo= (int*)registro[COD];
    char* ptNombre = (char*)registro[NOMBRE];
    char* ptRol= (char*)registro[ROL];
    char *ptCategoria= (char*)registro[CATEG];
    double *ptPuntaje= (double *)registro[PUNTAJE];
    
    archReporte<<left<<setw(20)<<ptNombre<<setw(20)<<ptRol<<setw(20)<<ptCategoria
            <<setw(20)<<*ptPuntaje<<right<<setw(20)<<*ptCodigo<<endl;
    
}

void eliminar_lista_heroes_repetidos(void* lst,bool (*eliminar_registro)(void*,void*&)){
    
    void** lista= (void**)lst,**nodoAct,**nodoAnt,**nodoSig;
    int i=0;
    bool fueEliminado=false;
    nodoAct= (void**)lista[CAB];
    while (nodoAct) {
        
        if(i!=0){ 
            nodoSig= (void**) nodoAct[SIG];
            
            fueEliminado= eliminar_registro(nodoAnt[DATO],nodoAct[DATO]);
            
            if(fueEliminado){
                // quido el nodo de la lista
                nodoAnt[SIG]= nodoSig;
                delete nodoAct;
                nodoAct= nodoSig;
            
            }else{
                // paso a la sig
                nodoAnt= nodoAct;

                nodoAct= (void**) nodoAct[SIG];
                 
            }
        }else{
            nodoAnt= nodoAct;
            nodoAct= (void**) nodoAct[SIG];
        }
           
        i++;
    }

    
}

bool eliminar_registro(void* regAnt,void*& regAct){
    
    void** regAnterior=(void**)regAnt, ** regActual= (void**)regAct;
    char* ptNombreAnt = (char*)regAnterior[NOMBRE];
    char* ptNombreAct = (char*)regActual[NOMBRE];
    int cmp= strcmp(ptNombreAct,ptNombreAnt);
    
    if(cmp==0){
        //eliminamos el registro del actual
        int* ptCodigo= (int*)regActual[COD];
        char* ptRol= (char*)regActual[ROL];
        char *ptCategoria= (char*)regActual[CATEG];
        double *ptPuntaje= (double *)regActual[PUNTAJE];
        
        delete ptCodigo;
        delete ptRol;
        delete ptCategoria;
        delete ptPuntaje;
        delete ptNombreAct;
        
        delete regActual;
        
        return true;
    }else return false;
    
    
    
}