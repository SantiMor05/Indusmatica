/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: kenyi
 * 
 * Created on 7 de mayo de 2025, 08:26 PM
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistros.h"

void construir(void *&lista) {
    lista = nullptr;
}

void crearlista(void *&pedido, void* (*lee)(ifstream&), const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    construir(pedido);
    void *dato;
    while (true) {
        dato = lee(arch);
        if (dato == nullptr)break;
        insertarlista(pedido, dato);
    }
}

bool listavacia(void *lista) {
    if (lista == nullptr)return true;
    void **reg=(void**)lista;
    if(reg[0]==nullptr)return true;
    return false;
}

void insertarlista(void *&lista, void *dato) {
    void **reg = (void **) lista;
    void **nodo = new void*[2] {
    };
    void **aux;

    nodo[0] = dato;

    if (listavacia(lista)) {
        reg = new void*[2] {
        };
        reg[0] = nodo;
        reg[1] = nodo;
        lista = reg;
    } else {
        aux = (void **) reg[1];
        aux[1] = nodo;
        reg[1] = nodo;
    }

}

void combinalista(void *lista1, void *lista2, void *&listafinal,
        int (*cmp)(const void *, const void*)) {
    bool fusion=false;
    void **aux;
    void **reg1 = (void**) lista1;
    void **reg2 = (void**) lista2;
    if (cmp(reg1[1], reg2[0]) < 0) {
        aux = (void**) reg1[1];
        aux[1] = reg2[0];
        reg1[1] = reg2[1];
    } else {
        if (cmp(reg2[1], reg1[0]) < 0) {
            aux = (void**) reg2[1];
            aux[1] = reg1[0];
            reg1[0] = reg2[0];
        } else {
            fusion=true;
            construir(listafinal);
            void *dato,**aux,**cola;
            while (!listavacia(lista1)and !listavacia(lista2)) {
                if(cmp(reg1[0],reg2[0])<0){
                    dato=quitalista(lista1);
                }
                else{
                    dato=quitalista(lista2);
                }
                insertarlista(listafinal,dato);
            }
            if(!listavacia(lista1)){
               aux= (void**)listafinal;
               cola=(void**)aux[1];
               cola[1]=reg1[0];
               aux[1]=reg1[1];
            }
            else{
                aux= (void**)listafinal;
               cola=(void**)aux[1];
               cola[1]=reg2[0];
               aux[1]=reg2[1];
            }
        }
    }
    if(!fusion)listafinal = lista1;
}

void *quitalista(void *lista) {
    if (!listavacia(lista)) {

        void **regLista = (void **) lista;
        void **nodo = (void **) regLista[0];
        void *dato;
        regLista[0] = nodo[1]; //El inicio de la lista lo apuntamos al siguiente nodo
        dato = nodo[0];
        delete nodo;
        return dato;
    }
    return nullptr;
}

void imprimelista(void *pedido, void (*imprime)(const void *, ofstream &),
        const char *nombArch) {

    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }

    void **reg = (void **) pedido;


    if (!listavacia(pedido)) {
        void **aux = (void **) reg[0];
        for (int i = 0; aux; i++) {
            imprime(aux[0], arch);
            aux = (void **) aux[1];
        }
    }
}