/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: santi
 * 
 * Created on 6 de mayo de 2025, 22:39
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "BibliotecaGenerica.h"

using namespace std;

bool listavacia(void *lista){
    if(lista == nullptr)
        return true;
    void **regLista = (void **)lista;
    if(regLista[0] == nullptr)
        return true;

    return false;
}


void crealista(void *&pedidos, void *(*lee)(ifstream &), const char *nombArch){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo" << nombArch << endl;
        exit(1);
    }
    
    construyeLista(pedidos);
    void *dato;
    while(true){
        dato = lee(arch);
        if(dato == nullptr)break;
        insertalista(pedidos, dato);
    }
    
}

void imprimelista(void *pedidos, void(*imprime)(void *dato, ofstream &arch),
        const char *nombArch){
    
    ofstream arch(nombArch, ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    if(!listavacia(pedidos)){
        void **regLista = (void **)pedidos;
        void **nodo = (void **)regLista[0];
        while(nodo != nullptr){
            imprime(nodo[0], arch);
            nodo = (void **)nodo[1];
        }
    }
}

void insertalista(void *pedidos, void *dato){
    
    void **regLista = (void **)pedidos;
    void **cola = (void **)regLista[1];
    
    void **nodo = new void*[2]{};
    nodo[0] = dato;
    if(!listavacia(pedidos)){
        //Apuntamos la cola a nodo
        cola[1] = nodo;
        //El nuevo nodo se convierte en la nueva cola
        regLista[1] = nodo;
    }
    else
        regLista[1] = regLista[0] = nodo;
    
}

void construyeLista(void *&pedidos){
    
    void **regLista = new void*[2]{};
    pedidos = regLista;
    
    
}


void *quitalista(void *lista){
    if(!listavacia(lista)){
        
        void **regLista = (void **)lista;
        void **nodo = (void **)regLista[0];
        void *dato;
        regLista[0] = nodo[1]; //El inicio de la lista lo apuntamos al siguiente nodo
        dato = nodo[0];
        delete nodo;   
        return dato;
    }
    return nullptr;
}

void combinaLista(void *&pedidos1, void *&pedidos2, void *&pedidosfinal, 
        int cmpnum(const void*, const void*)){
    
    construyeLista(pedidosfinal);
    void *dato1 = nullptr, *dato2 = nullptr;
    while(true){
        //primeravez = false;
        if(dato1 == nullptr) dato1 = quitalista(pedidos1);
        if(dato2 == nullptr) dato2 = quitalista(pedidos2);
        
        if(dato1 != nullptr and dato2 != nullptr){
            if(cmpnum(dato1, dato2) > 0){
            insertalista(pedidosfinal, dato2);
            dato2 = nullptr;
            }
            else if(cmpnum(dato1, dato2) < 0){
                insertalista(pedidosfinal, dato1);
                dato1 = nullptr;
            }
            else{
                insertalista(pedidosfinal, dato1);
                dato1 = dato2 = nullptr;
            }
        }
        else if(dato1 == nullptr and dato2 != nullptr){
            insertalista(pedidosfinal, dato2);
            dato2 = nullptr;
        }
        else if (dato2 == nullptr and dato1 != nullptr){
            insertalista(pedidosfinal, dato1);
            dato1 = nullptr;
        }  
        else break;
    }
    //Ya no se podra usar las dos primeras listas;
    liberarMemoria(pedidos1);
    liberarMemoria(pedidos2);
}

void liberarMemoria(void *&lista){
    void **regLista = (void **)lista;
    delete regLista;
    lista = nullptr;
}