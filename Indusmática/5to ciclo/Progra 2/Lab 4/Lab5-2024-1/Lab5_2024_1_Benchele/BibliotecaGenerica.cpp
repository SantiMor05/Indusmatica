/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: Lenovo
 * 
 * Created on 7 de mayo de 2025, 11:11 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "BibliotecaGenerica.h"
#include "FuncionesComunes.h"
using namespace std;

enum LISTA{CAB, COL};
enum NODO{DAT, SIG};

bool esListaVacia(void **lista){
    void **cab = (void **)lista[CAB];
    if(cab == nullptr)return true;
    return false;
    //return lista[CAB] == nullptr;
}

void creaLista(void *&pedidos, void *(*leer)(ifstream &arch), const char*nombArch){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);
    
    void *reg;
    pedidos = nullptr;
    
    while (true) {
        reg = leer(arch);
        if(arch.eof())break;
        insertarAlFinal(reg, pedidos);
    }

}
void insertarAlFinal(void *reg, void *&pedidos){
    void **lista = (void **)pedidos;
    void **nodo = new void*[2]{};
    void **auxNodo;
    
    //LISTA{CAB, COL};
    //NODO{DAT, SIG};
    nodo[DAT] = reg;
    if(pedidos == nullptr){
        lista = new void*[2]{};
        lista[CAB] = nodo;
        lista[COL] = nodo;
        pedidos = lista;  
    }
    else{
        auxNodo = (void **)lista[COL];
        auxNodo[SIG] = nodo;
        lista[COL] = nodo;
    }
}

void combinaLista(void *ped1, void *ped2, void *&pedFinal, int (*comparar)(const void*, const void*)){ 
    //LISTA{CAB, COL};
    void **pedidos1 = (void **)ped1, **pedidos2 = (void **)ped2;
    void* dato1;
    void* dato2;

    if(esListaVacia(pedidos2))dato1 = nullptr;
    else dato1 = quitaLista(pedidos1);

    if(esListaVacia(pedidos2))dato2 = nullptr;
    else dato2 = quitaLista(pedidos2);

    while (dato1 and dato2) {
        if(comparar(dato1, dato2) <= 0) {
            insertarAlFinal(dato1, pedFinal);
            if(esListaVacia(pedidos1)) {
                dato1 = nullptr;
            } 
            else{
                dato1 = quitaLista(pedidos1);
            }
        } 
        else{
            insertarAlFinal(dato2, pedFinal);
            if(pedidos2[CAB] == nullptr) {
                dato2 = nullptr;
            } 
            else{
                dato2 = quitaLista(pedidos2);
            }
        }
    }
    insertarFaltantes(dato1, dato2, pedidos1, pedidos2, pedFinal);
}

void insertarFaltantes(void *dato1, void *dato2, void **pedidos1, void **pedidos2, 
                       void *pedFinal){
    while (dato1) {
        insertarAlFinal(dato1, pedFinal);
        if(esListaVacia(pedidos1)) {
            dato1 = nullptr;
        } 
        else{
            dato1 = quitaLista(pedidos1);
        }
    }
    while (dato2) {
        insertarAlFinal(dato2, pedFinal);
        if(esListaVacia(pedidos2)) {
            dato2 = nullptr;
        } 
        else{
            dato2 = quitaLista(pedidos2);
        }
    }
}
void *quitaLista(void *lst){
    void **lista = (void **)lst;
    
    if(lista[CAB] == nullptr)return nullptr;
    void **nodo = (void **)lista[CAB];
    void *dato = (nodo[DAT]);
    lista[CAB] = nodo[SIG];
    if(lista[CAB] == nullptr){
        //Ya no hay mas nodos
        lista[COL] = nullptr;
    }
    //delete nodo[DAT];
    //delete nodo[SIG];
    delete nodo;
    return dato;
}
void imprimeLista(void *ped, void (*imprimir)(ofstream &arch, void *dato), const char*nombArch){
    ofstream arch(nombArch, ios::out);
    verificar_Apertura_O(arch, nombArch);
    
    //LISTA{CAB, COL};
    void **pedidos = (void **)ped;
    void **rec = (void **)pedidos[CAB];
    
    //NODO{DAT, SIG};
    arch<<"Lista: "<<endl;
    while (rec) {
        imprimir(arch, rec[DAT]);
        rec = (void **)rec[SIG];
    }
}
