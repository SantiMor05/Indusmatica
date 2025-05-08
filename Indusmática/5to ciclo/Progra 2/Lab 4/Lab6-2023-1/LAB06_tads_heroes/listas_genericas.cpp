
/* 
 * File:   listas_genericas.cpp
 * Author: Usuario
 * 
 * Created on 8 de mayo de 2025, 04:32 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "listas_genericas.h"

void crear_lista_heroes(void *arr, void*&lista, void*(*leer)(void*)) {

    construirLista(lista);
    void **arreglo = (void**) arr, *reg,**aux,**aux2, **quinteta;
    void **lis=(void**)lista;
    int i;
    for (i = 0; arreglo[i]; i++) {
        reg = leer(arreglo[i]);
        aux=(void**)reg;
        char *nom=(char *)aux[1];
        insertaFinal(lista, reg);
        aux2=(void**)lis[0];
        quinteta = (void**)aux2[0];
        char *num2=(char*)quinteta[1];
        
    }
    
}

void insertaFinal(void *lst, void *reg){
    void **lista=(void**)lst;
    void **nodo = new void*[2]{}, **cola;
    nodo[0] = reg;
    
    if(lista[0]==nullptr){
        lista[0]= nodo;
        lista[1]=nodo;
    }else{
        cola = (void**)lista[1];
        cola[1] = nodo;
        lista[1]=nodo;
    }
}

void construirLista(void *&lista) {
    void **dupla = new void*[2]   { };
    lista = dupla;
}

void imprimir_lista_heroes(void *lst, void (*imprime)(void *, ofstream&)){
    ofstream arch("Heroes.txt", ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Heroes.txt" << endl;
        exit(1);
    }
    arch << fixed << setprecision(2);
    void **lista = (void**)lst;
    void**rec = (void**)lista[0];
    arch << left << setw(10) << "Codigo" << setw(30) << "Nombre" << setw(10) << "Rol"
            << setw(10) << "Categoria" << "Puntaje" << endl;
    arch << "--------------------------------------------------------------------" << endl;
    while(rec){
        imprime(rec[0], arch);
        rec = (void**)rec[1];
    }
    
}

void eliminar_lista_heroes_repetidos(void *lst, int eliminar(const void*, const void*)){
     void **lista = (void**)lst;
    void**rec = (void**)lista[0];
    void **sig;
    
    while(rec[1]!=nullptr){
        sig = (void**)rec[1];
        if(eliminar(rec[0],sig[0])==0){
            rec[1] = sig[1];
            delete sig;
        }
        rec = (void**)rec[1];
    }
}
