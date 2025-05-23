/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 23 de mayo de 2025, 11:36
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
/*
 * 
 */

void operacion_Nautilus(char *Indicaciones, int n){
    Pila pila;
    construir(pila);
    Elemento elemento;
    int i=0;
    for (i=1; i <= n; i++) {
        elemento.numero = i;
        if (Indicaciones[i-1]=='S'){
            apilar(pila,elemento);
            while(!esPilaVacia(pila)){
                elemento = desapilar(pila);
                cout<<elemento.numero<<"  ";
            } 
        }
        else{
            apilar(pila,elemento);
        }
    }
    cout<<i<<"  ";
}

int main(int argc, char** argv) {
    int n=3;
    char Indicaciones[n] = {'B','B','S'};
    operacion_Nautilus(Indicaciones,n);
    cout<<endl;
    n=5;
    char Indicaciones2[n] = {'S','S','S','B','S'};
    operacion_Nautilus(Indicaciones2,n);
    cout<<endl;
    n=7;
    char Indicaciones3[n] = {'S','B','S','B','B','S','S'};
    operacion_Nautilus(Indicaciones3,n);
    return 0;
}

