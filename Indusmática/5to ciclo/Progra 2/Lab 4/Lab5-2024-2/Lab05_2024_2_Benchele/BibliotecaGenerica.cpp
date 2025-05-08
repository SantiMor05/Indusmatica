/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: Lenovo
 * 
 * Created on 6 de mayo de 2025, 09:00 PM 11:48 pm
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "BibliotecaGenerica.h"
#include "FuncionesComunes.h"
using namespace std;

enum LISTA{CAB, COL, CANT};

enum DATO{DUP,SIG};

enum DUPLA{DAT, ARR};

void creaLista(void *&lst, void *(*leer)(ifstream &arch), const char*nombArch){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);

    
    void *reg;
    
    lst = nullptr; //constuir(lista)
    
    while (true) {
        reg = leer(arch);
        if(arch.eof())break;
        insertar(reg, lst);
    }
}

void insertar(void *reg, void *&lista){
    void **structLista = (void**)lista;
    void **nodo = new void*[2]{}, **anterior;
    void **dupla = new void*[2]{};
    void **auxNodo;
    void **arreglo = new void*[20]{};
    int *cant;
    
    //DATO{DUP,SIG};
    dupla[DAT] = reg;
    dupla[ARR] = arreglo;
    
    nodo[DUP] = dupla;
    
    //LISTA{CAB, COL, CANT};
    //enum DATO{DUP,SIG};
    if(lista == nullptr){ //esListaVacia(lista)
        structLista = new void*[3]{};
        structLista[CAB] = nodo;
        structLista[COL] = nodo;
        cant = new int;
        *cant = 1;
        structLista[CANT] = cant;
        lista = structLista;
    }
    else{
        auxNodo = (void **)structLista[COL];
        auxNodo[SIG] = nodo;
        structLista[COL] = nodo;
        cant = (int *)structLista[CANT];
        (*cant)++;
    }
    
}
void muestraLista(void *&lst, void (*imprimir)(ofstream &arch, void *dato), const char*nombArch){
    ofstream arch(nombArch, ios::out);
    verificar_Apertura_O(arch, nombArch);
    
    //LISTA{CAB, COL, CANT};
    //DATO{DUP,SIG};
    void **lista = (void **)lst;
    void **rec = (void **)lista[CAB];
    
    while(rec) {
        imprimir(arch, rec[DUP]);
        rec = (void **)rec[SIG];
    }
}

void cargaLista(void *lst, int (comprobar)(const void *, const void *), void *(*leer)(ifstream &arch),
                const char*nombArch){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);
    
    
    void **lista = (void**)lst;;
    void *reg;
    
    while (true) {
        reg = leer(arch);
        if(arch.eof())break;
        buscarCoincidencia(reg, lista, comprobar);
    }


}

void buscarCoincidencia(void *reg, void **lista, int (comprobar)(const void *, const void *)){
    //LISTA{CAB, COL, CANT};
    //DUPLA{DAT, ARR};
    void **buscado = (void **)reg;
    void **rec = (void **)lista[CAB];
    void **dupla;
    
    while (rec) {
        dupla = (void **)rec[DUP];
        if(comprobar(dupla[DAT], buscado[0]) == 0){
            insertaDatoEnArreglo(rec[DUP], buscado[1]);
            break;
        }
        rec = (void **)rec[SIG];
    }
}

void insertaDatoEnArreglo(void *dpl, void *buscado){
    //DUPLA{DAT, ARR};
    void **dupla = (void **)dpl;
    void **arreglo = (void **)dupla[ARR];
    int i = 0;
    while (arreglo[i])i++;
    cout<<i<<endl;
    arreglo[i] = buscado;
}


