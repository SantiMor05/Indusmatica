/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 23 de mayo de 2025, 10:09
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
#include "Elemento.h"
#include "Nodo.h"
#include "Lista.h"
#include "funcionesLista.h"
Lista listaA, listaD, listaB, listaH;
/*
 * 
 */

void fusionar(Lista &L1,Lista L2){
    if (L1.cola->elemento.numero < L2.cabeza->elemento.numero){
        L1.cola->siguiente = L2.cabeza;
        L1.cola = L2.cola;
    }else{
        if (L1.cabeza->elemento.numero > L2.cola->elemento.numero){
            L2.cola->siguiente = L1.cabeza;
            L1.cabeza = L2.cabeza;
        }else{
            Nodo * ini = nullptr, * fin;
            while(!esListaVacia(L1) and !esListaVacia(L2)){
                if (L1.cabeza->elemento.numero < L2.cabeza->elemento.numero){
                    if (ini==nullptr){
                        ini = L1.cabeza;
                        fin = L1.cabeza;
                    }else{
                        fin->siguiente = L1.cabeza;
                        fin = L1.cabeza;
                    }
                    L1.cabeza = L1.cabeza->siguiente;
                }else{
                    if (ini==nullptr){
                        ini = L2.cabeza;
                        fin = L2.cabeza;
                    }else{
                        fin->siguiente = L2.cabeza;
                        fin = L2.cabeza;
                    }
                    L2.cabeza = L2.cabeza->siguiente;
                }
            }
            if (!esListaVacia(L1)){
                fin->siguiente = L1.cabeza;
                fin = L1.cola;
            }
            if (!esListaVacia(L2)){
                fin->siguiente = L2.cabeza;
                fin = L2.cola;
            }
            L1.cabeza = ini;
            L1.cola = fin;
            L1.longitud += L2.longitud;
        }
    }
}

void copiar(int *mejorCromo, int *cromo){
    for (int i = 0; i < 10; i++) mejorCromo[i] = 0;
    for (int i = 0; i < 10; i++) mejorCromo[i] = cromo[i];
}

int calcular_suma(Nodo *recorrido, int* cromo, int cant){
    int suma;
    for (int i = 0; i < cant; i++) {
        suma += recorrido->elemento.numero * cromo[i];
        recorrido = recorrido->siguiente;
    }
    return suma;
}

void cargabin(int *cromo, int num, int &cant1, int base, int cantElementos){
    cant1 = 0; int cifra;
    for (int i = 0; i < 10; i++) cromo[i] = 0;
    for (int i = 0; i < cantElementos; i++) {
        cifra = num % base;
        num /= base;
        cromo[i] = cifra;
    }
    for (int i = 0; i < cantElementos; i++) {
        if (cromo[i] == 1) cant1++;
    }
}

void formarListaMejorCromo(Lista &lista, Nodo *recorrido, int *mejorCromo, int cantElementos){
    Elemento elemento;
    for (int i = 0; i < cantElementos; i++) {
        elemento.numero = recorrido->elemento.numero;
        if (mejorCromo[i]==1) insertarAlFinal(lista,elemento);
        recorrido = recorrido->siguiente;
    }
}

void formarLista(Lista &lista, char opcion,int cant, int maximo){
    int cantElementos, mayorSum=0, sum;
    Nodo * recorrido;
    if (opcion=='A'){
        recorrido = listaA.cabeza;
        cantElementos = listaA.longitud;
    }
    else if (opcion=='D'){
        recorrido = listaD.cabeza;
        cantElementos = listaD.longitud;
    }
    else if (opcion=='B'){
        recorrido = listaB.cabeza;
        cantElementos = listaB.longitud;
    }
    else if (opcion=='H'){
        recorrido = listaH.cabeza;
        cantElementos = listaH.longitud;
    }
    Nodo *cabeza = recorrido;
    int opciones = pow(2,cantElementos), cromo[10]{}, cant1, mejorCromo[10]{};
    for (int i = 0; i < opciones; i++) {
        sum = 0;
        cargabin(cromo,i,cant1,2,cantElementos);
        if (cant1==cant){
            sum = calcular_suma(recorrido,cromo,cantElementos);
            if (sum <= maximo){
                if (sum > mayorSum){
                    mayorSum = sum;
                    copiar(mejorCromo,cromo);
                }
            }
        }
        recorrido = cabeza;
    }
    formarListaMejorCromo(lista,recorrido,mejorCromo,cantElementos);
    imprimir(lista);
}

int main(int argc, char** argv) {
    construir(listaA); construir(listaD); construir(listaB); construir(listaH);
    
    listaA.tipo = 'A';
    Elemento elemento;
    elemento.numero = 120;
    insertarAlFinal(listaA,elemento);
    elemento.numero = 145;
    insertarAlFinal(listaA,elemento);
    elemento.numero = 230;
    insertarAlFinal(listaA,elemento);
    elemento.numero = 247;
    insertarAlFinal(listaA,elemento);
    elemento.numero = 285;
    insertarAlFinal(listaA,elemento);
    
    listaD.tipo = 'D';
    elemento.numero = 182;
    insertarAlFinal(listaD,elemento);
    elemento.numero = 240;
    insertarAlFinal(listaD,elemento);
    elemento.numero = 300;
    insertarAlFinal(listaD,elemento);
    
    listaB.tipo = 'B';
    elemento.numero = 58;
    insertarAlFinal(listaB,elemento);
    elemento.numero = 120;
    insertarAlFinal(listaB,elemento);
    elemento.numero = 247;
    insertarAlFinal(listaB,elemento);
    elemento.numero = 278;
    insertarAlFinal(listaB,elemento);
    
    listaH.tipo = 'H';
    elemento.numero = 128;
    insertarAlFinal(listaH,elemento);
    elemento.numero = 236;
    insertarAlFinal(listaH,elemento);
    elemento.numero = 354;
    insertarAlFinal(listaH,elemento);
    elemento.numero = 540;
    insertarAlFinal(listaH,elemento);
    elemento.numero = 782;
    insertarAlFinal(listaH,elemento);
    
    int cant, maximo;
    char opcion;
    Lista lista, lista2; construir(lista); construir(lista2);
    cout<<"Inserte el tipo de producto a incluir: ";
    cin>>opcion;
    cout<<"Inserte el número de productos de este tipo: ";
    cin>>cant;
    cout<<"Inserte el máximo de calorías de este tipo: ";
    cin>>maximo;
    formarLista(lista,opcion,cant,maximo);
    cout<<"Inserte el nuevo tipo de producto a incluir : ";
    cin>>opcion;
    cout<<"Inserte el número de productos de este tipo: ";
    cin>>cant;
    cout<<"Inserte el máximo de calorías de este tipo: ";
    cin>>maximo;
    formarLista(lista2,opcion,cant,maximo);
    fusionar(lista,lista2);
    imprimir(lista);
    while(true){
        cout<<"Inserte el nuevo tipo de producto a incluir (inserte x si no desea incluir otro tipo más): ";
        cin>>opcion;
        if (opcion=='x' or opcion=='X') break;
        construir(lista2);
        cout<<"Inserte el número de productos de este tipo: ";
        cin>>cant;
        cout<<"Inserte el máximo de calorías de este tipo: ";
        cin>>maximo;
        formarLista(lista2,opcion,cant,maximo);
        fusionar(lista,lista2);
        imprimir(lista);
    }
    
    return 0;
}

