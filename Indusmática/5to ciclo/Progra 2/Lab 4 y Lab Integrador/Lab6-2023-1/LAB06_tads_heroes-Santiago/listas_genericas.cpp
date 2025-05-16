/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listas_genericas.cpp
 * Author: santi
 * 
 * Created on 15 de mayo de 2025, 11:01
 */

#include <iostream>
#include <iomanip>
#include "listas_genericas.h"

using namespace std;

enum Lista{DATO, SIG};

void inicializarLista(void *&lista){
    lista = nullptr;
}

void crear_lista_heroes(void *arreglo_heroes, void *&lista, 
        void *(*leer_heroe)(void *heroe)){
    
    inicializarLista(lista);
    
    void **arreglo = (void **)arreglo_heroes;
    void **cola = nullptr;
    void *registro;
    for(int i = 0; arreglo[i]; i++){
        registro = leer_heroe(arreglo[i]);  
        if(lista == nullptr){
            lista = registro;
        }
        else{
            cola[SIG] = registro;
        }
        cola = (void **)registro;
    }
    
}



void imprimir_lista_heroes(void *lista, void (*imprime)(const void *dato, 
        ofstream &arch)){
    
    static int cont = 0;
    ofstream arch;
    if(cont == 0){
        arch.open("ReportePrueba.txt", ios::out);
    }
    else
        arch.open("Reporte-Heroes.txt", ios::out);
    
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo Reporte" << endl;
        exit(1);
    }
    arch << setprecision(2) << fixed;
    void **nodo = (void **)lista;
    
    while(nodo != nullptr){
        imprime(nodo[DATO], arch);
        nodo = (void **)nodo[SIG];
    }
    
    cont++;
}


void eliminar_lista_heroes_repetidos(void *lista, bool (*elimina)(const void*anterior,
        void *actual)){
    
    void **nodo = (void **)lista, *aux;
    void **ant = nullptr;
    bool seElimina;
    while(nodo != nullptr){
        if(ant != nullptr){
            seElimina = elimina(ant[DATO], nodo[DATO]);
            if(seElimina){
                ant[SIG] = nodo[SIG];
                delete nodo;
                nodo = (void **)ant[SIG];
            }
            else{
                ant = nodo;
                nodo = (void **)nodo[SIG];
            }
        }
        else{
            ant = nodo;
            nodo = (void **)nodo[SIG];
        }          
        
    }
    
}