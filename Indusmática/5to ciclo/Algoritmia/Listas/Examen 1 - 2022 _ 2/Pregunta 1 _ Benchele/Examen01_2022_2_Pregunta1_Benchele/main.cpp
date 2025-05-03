/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 2 de mayo de 2025, 09:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <complex>
#include "FuncionesListas.h"
#include "Elemento.h"
#include "Lista.h"
using namespace std;

/*
 * 
 */
void insertarOrdenado(Lista &lista,int diaPrio, int hora, int sucursal){
    //Elemento, anterior, nuevo
    struct Elemento elemento;
    elemento.diaPriori = diaPrio;
    elemento.hora = hora;
    elemento.sucursal = sucursal;
    
    struct Nodo *nodoAnterior = obtenerNodoAnterior(lista, elemento);
    struct Nodo *nuevoNodo = crearNodo(elemento, nullptr);
    
    if(nodoAnterior == nullptr){
        nuevoNodo->siguiente = lista.cabeza; // ==nullptr
        lista.cabeza = nuevoNodo;
    }
    else{
        nuevoNodo->siguiente = nodoAnterior->siguiente;
        nodoAnterior->siguiente = nuevoNodo;
    }
    lista.longitud++;
    lista.cola = obtenerUltimoNodo(lista);
}

bool condicion(Lista l1, Lista l2, int tipo){
    switch(tipo){
        case 1: //Condicion cola L1 < cola L2
            if(l1.cola->elemento.hora < l2.cabeza->elemento.hora or (l1.cola->elemento.hora == l2.cabeza->elemento.hora 
              and l1.cola->elemento.diaPriori < l2.cabeza->elemento.diaPriori)){
                return true;
            }
            break;
        case 2: //Condicion cola L2 < cola L1
            if(l2.cola->elemento.hora < l1.cabeza->elemento.hora or (l2.cola->elemento.hora == l1.cabeza->elemento.hora 
              and l2.cola->elemento.diaPriori < l1.cabeza->elemento.diaPriori)){
                return true;
            }
            break;
        case 3: //Condicion cabeza L1 < cabeza L2
            if(l1.cabeza->elemento.hora < l2.cabeza->elemento.hora or (l1.cabeza->elemento.hora == l2.cabeza->elemento.hora 
              and l1.cabeza->elemento.diaPriori < l2.cabeza->elemento.diaPriori)){
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}
void fusion(struct Lista &l1, struct Lista l2){
    if(condicion(l1, l2, 1)){
        l1.cola->siguiente = l2.cabeza;
        l1.cola = l2.cola;
    }
    else{
        if(condicion(l1, l2, 2)){
            l2.cola->siguiente = l1.cabeza;
            l1.cabeza = l2.cabeza;
        }
        else{
            struct Nodo *ini = nullptr, *fin = nullptr;
            while (!esListaVacia(l1) and !esListaVacia(l2)) {
                if(condicion(l1, l2, 3)){
                    if(ini == nullptr){
                        ini = l1.cabeza;
                        fin = l1.cabeza;
                    }
                    else{
                        fin->siguiente = l1.cabeza;
                        fin = l1.cabeza;
                    }
                    l1.cabeza = l1.cabeza->siguiente;
                }
                else{
                    if(ini == nullptr){
                        ini = l2.cabeza;
                        fin = l2.cabeza;
                    }
                    else{
                        fin->siguiente = l2.cabeza;
                        fin = l2.cabeza;
                    }
                    l2.cabeza = l2.cabeza->siguiente;
                }
            }
            if(!esListaVacia(l1)){
                fin->siguiente = l1.cabeza;
                fin = l1.cola;
            }
            if(!esListaVacia(l2)){
                fin->siguiente = l2.cabeza;
                fin = l2.cola;
            }
            l1.cabeza = ini;
            l1.cola = fin;

        }
    }
}


int main(int argc, char** argv) {
    struct Lista lista_1, lista_2, lista_3, lista_4, lista_5;
    //Lista 1
    construir(lista_1);
    insertarOrdenado(lista_1, 1, 8, 6);
    insertarOrdenado(lista_1, 1, 10, 14);
    insertarOrdenado(lista_1, 1, 12, 1);
    imprime(lista_1);
    
    //Lista 2
    construir(lista_2);
    insertarOrdenado(lista_2, 2, 9, 3);
    insertarOrdenado(lista_2, 2, 11, 8);
    imprime(lista_2);
    
    //Lista 3
    construir(lista_3);
    insertarOrdenado(lista_3, 3, 8, 2);
    insertarOrdenado(lista_3, 3, 9, 5);
    insertarOrdenado(lista_3, 3, 10, 10);
    imprime(lista_3);
    
    //Lista 4
    construir(lista_4);
    insertarOrdenado(lista_4, 4, 14, 13);
    insertarOrdenado(lista_4, 4, 15, 9);
    insertarOrdenado(lista_4, 4, 16, 11);
    imprime(lista_4);
    
    //Lista 5
    construir(lista_5);
    insertarOrdenado(lista_5, 5, 17, 4);
    insertarOrdenado(lista_5, 5, 18, 12);
    insertarOrdenado(lista_5, 5, 19, 7);
    imprime(lista_5);
    
    //Fusiones
    fusion(lista_1, lista_2);
    fusion(lista_1, lista_3);
    fusion(lista_1, lista_4);
    fusion(lista_1, lista_5);
    
    //Reporte final
    cout<<endl<<endl;
    imprime(lista_1);
    return 0;
}

