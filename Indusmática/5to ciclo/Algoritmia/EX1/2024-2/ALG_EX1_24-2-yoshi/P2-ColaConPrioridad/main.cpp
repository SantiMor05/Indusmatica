/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 22 de mayo de 2025, 21:54
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Elemento.h"
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
/*
 * 
 */

void desencolarNoVip(Cola &cola){
    Nodo* aux = cola.lista.VIP->siguiente;
    cola.lista.VIP->siguiente = cola.lista.VIP->siguiente->siguiente;
    delete aux;
}

int main(int argc, char** argv) {
    Cola cola;
    construir(cola);
    Elemento elemento;
    elemento.numero =  15;
    elemento.tipo = 0;
    encolar(cola,elemento);
    
    elemento.numero =  30;
    elemento.tipo = 1;
    encolar(cola,elemento);
    
    elemento.numero =  45;
    elemento.tipo = 0;
    encolar(cola,elemento);
    
    elemento.numero =  60;
    elemento.tipo = 1;
    encolar(cola,elemento);
    
    elemento.numero =  75;
    elemento.tipo = 0;
    encolar(cola,elemento);
    
    elemento.numero =  90;
    elemento.tipo = 1;
    encolar(cola,elemento);
    
//    imprimir(cola);
    
    int tiempo = 15, cantAtend = 0, cantNoAtend=0;
    while(!esColaVacia(cola)){
        if (cola.lista.VIP == nullptr){
            elemento = desencolar(cola);
        }else{
        if (cola.lista.cabeza->elemento.numero <= tiempo and cola.lista.VIP->siguiente->elemento.numero <= tiempo){
            elemento = desencolar(cola);
            if (tiempo - elemento.numero >= 20) cantNoAtend++;
            else{
                cantAtend++;
                tiempo += 20;
            }
        }else{
            if (cola.lista.cabeza->elemento.numero <= tiempo){
                elemento = desencolar(cola);
                if (tiempo - elemento.numero >= 20) cantNoAtend++;
                else{
                    cantAtend++;
                    tiempo += 20;
                }
            }else{
                desencolarNoVip(cola);
                tiempo += 20;
            }
        }
        }
    }
    cout<<"RESULTADOS DE LA SIMULACIÓN DEL DESPACHO DE ENTRADAS:"<<endl;
    cout<<"Clientes VIP atendidos     : "<<cantAtend<<endl;
    cout<<"Clientes VIP NO atendidos  : "<<cantNoAtend<<endl;
    
    return 0;
}

