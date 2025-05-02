/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesLista.cpp
 * Author: Usuario
 * 
 * Created on 2 de mayo de 2025, 17:19
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "ELEMENTO.h"
#include "NODO.h"
#include "LISTA.h"
#include "FuncionesLista.h"

void construirLista(Lista &lista){
    lista.cabeza = nullptr;
    lista.cola = nullptr;
}

void insertarOrdenado(Lista &lista, int prioridad, int hora, int sucursal){
    Elemento elemento;
    elemento.prioridad = prioridad;
    elemento.hora = hora;
    elemento.sucursal = sucursal;
    
    Nodo *nuevoNodo;
    if(esListaVacia(lista)){
        nuevoNodo = crearNodo(elemento,nullptr);
        lista.cabeza = nuevoNodo;
        lista.cola = nuevoNodo;
    }else{
        Nodo* recorrido = lista.cabeza;
        Nodo* anterior = lista.cabeza;
        while(recorrido!=nullptr){
            if (hora<recorrido->elemento.hora or hora==recorrido->elemento.hora
                    and prioridad < recorrido->elemento.prioridad){
                nuevoNodo = crearNodo(elemento,recorrido);
                anterior->siguiente = nuevoNodo;
                return;
            }else{
                anterior = recorrido;
                recorrido = recorrido->siguiente;
            }
        }
        nuevoNodo = crearNodo(elemento,nullptr);
        anterior->siguiente = nuevoNodo;
        lista.cola = nuevoNodo;
    }
}

bool esListaVacia(Lista lista){
    if (lista.cabeza==nullptr) return true;
    else return false;
}

Nodo* crearNodo(struct Elemento elemento,struct Nodo *siguiente){
    struct Nodo *nodo = new struct Nodo;
    nodo->elemento = elemento;
    nodo->siguiente = siguiente;
    return nodo;
}

void imprimeLista(Lista lista){
    Nodo * recorrido = lista.cabeza;
    if (recorrido==nullptr){
        cout<<"No se puede imprimir la lista, pues está vacía"<<endl;
    }else{
        cout<<"[ ";
        while(recorrido!=nullptr){
            cout<<recorrido->elemento.hora<<"("<<recorrido->elemento.sucursal<<")";
            switch(recorrido->elemento.prioridad){
                case 1:
                    cout<<"(Lunes)  ";
                    break;
                case 2:
                    cout<<"(Martes)  ";
                    break;
                case 3:
                    cout<<"(Miércoles)  ";
                    break;
                case 4:
                    cout<<"(Jueves)  ";
                    break;
                default:
                    cout<<"(Viernes)  ";
                    break;
            }
            if (recorrido->siguiente!=nullptr) cout<<"->  ";
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}

void Fusion(Lista &L1, Lista L2){
    if (L1.cola->elemento.hora<=L2.cabeza->elemento.hora or (L1.cola->elemento.hora==L2.cabeza->elemento.hora
            and L1.cola->elemento.prioridad<L2.cabeza->elemento.prioridad)){
        L1.cola->siguiente = L2.cabeza;
        L1.cola = L2.cola;
    }else{
        if(L1.cabeza->elemento.hora>=L2.cola->elemento.hora or (L1.cabeza->elemento.hora==L2.cola->elemento.hora
                and L1.cabeza->elemento.prioridad>=L2.cola->elemento.prioridad)){
            L2.cola->siguiente = L1.cabeza;
            L1.cabeza = L2.cabeza;
        }else{
            Nodo * ini = nullptr;
            Nodo * fin = nullptr;
            while(!esListaVacia(L1) and !esListaVacia(L2)){
                if (L1.cabeza->elemento.hora<=L2.cabeza->elemento.hora or (L1.cabeza->elemento.hora==L2.cabeza->elemento.hora
                    and L1.cabeza->elemento.prioridad<L2.cabeza->elemento.prioridad)){
                    if (ini==nullptr){
                        ini = L1.cabeza;
                        fin = L1.cabeza;
                    }else{
                        fin->siguiente = L1.cabeza;
                        fin = fin->siguiente;
                    }
                    L1.cabeza = L1.cabeza->siguiente;
                }else{
                    if (ini==nullptr){
                        ini = L2.cabeza;
                        fin = L2.cabeza;
                    }else{
                        fin->siguiente = L2.cabeza;
                        fin = fin->siguiente;
                    }
                    L2.cabeza = L2.cabeza->siguiente;
                }
            }
            if (!esListaVacia(L1)){
                fin->siguiente = L1.cabeza;
                fin = L1.cola;
            }else{
                fin->siguiente = L2.cabeza;
                fin = L2.cola;
            }
            L1.cabeza = ini;
            L1.cola = fin;
        }
    }
}