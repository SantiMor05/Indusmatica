/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 22 de mayo de 2025, 15:49
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Elemento.h"
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

void llenarPilaMayores(int *cabezas, int n, Pila &pila){
    int mayor=0;
    Elemento elemento, basura;
    elemento.numero = -1;
    apilar(pila,elemento);
    for (int i = 0; i < n; i++) {
        elemento.numero = i;
        if (cabezas[i]>mayor){
            while(!esPilaVacia(pila)) basura = desapilar(pila);
            mayor = cabezas[i];
            basura.numero = -1;
            apilar(pila,basura);
        }
        if (cabezas[i]==mayor) apilar(pila,elemento);
    }
    elemento.numero = n;
    apilar(pila,elemento);
}

void robot_cabezon(int *cabezas,int &posMayor,int &cantM,int n){
    Pila pila; construir(pila);
    Elemento izq, medio, der;
    llenarPilaMayores(cabezas,n,pila);
//    imprimir(pila);
    der = desapilar(pila);
    medio = desapilar(pila);
    int cant; cantM=0;
    while(!esPilaVacia(pila)){
        izq = desapilar(pila);
        cant = 0;
        cant += der.numero - medio.numero - 1;
        cant += medio.numero - izq.numero - 1;
        if (cant>cantM){
            posMayor = medio.numero;
            cantM = cant;
        }
        der = medio;
        medio = izq;
    }
}

int main(int argc, char** argv) {
    int n=4, cabezas[n] = {1,3,6,4}, posMayor, cantM;
    robot_cabezon(cabezas,posMayor,cantM,n);
    cout<<"Posición="<<posMayor<<", "<<cantM<<" pilas pequeñas alrededor"<<endl<<endl;
    
    n=5; int cabezas2[n] = {2,5,7,7,1};
    robot_cabezon(cabezas2,posMayor,cantM,n);
    cout<<"Posición="<<posMayor<<", "<<cantM<<" pilas pequeñas alrededor"<<endl<<endl;
    
    n=14; int cabezas3[n] = {1,7,2,7,3,4,3,2,1,7,2,1,7,3};
    robot_cabezon(cabezas3,posMayor,cantM,n);
    cout<<"Posición="<<posMayor<<", "<<cantM<<" pilas pequeñas alrededor"<<endl<<endl;
    
    n=7; int cabezas4[n] = {6,2,5,4,5,1,6};
    robot_cabezon(cabezas4,posMayor,cantM,n);
    cout<<"Posición="<<posMayor<<", "<<cantM<<" pilas pequeñas alrededor"<<endl<<endl;
    return 0;
}

