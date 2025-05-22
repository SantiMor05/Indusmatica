/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include "Elemento.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;

void insertarPrioridad(struct Cola &cola,struct Elemento elemento){
    struct Nodo *nuevoNodo = crearNodo(elemento,nullptr);
    
    if(cola.lista.cabeza==nullptr){
        cola.lista.cabeza= nuevoNodo;
        cola.lista.cola= nuevoNodo;
        if(elemento.tipo==1) cola.lista.vip= nuevoNodo;
    }else{
        if(elemento.tipo==1){
            if(cola.lista.vip==nullptr){
                nuevoNodo->siguiente= cola.lista.cabeza;
                cola.lista.cabeza= nuevoNodo;
            }else{
                nuevoNodo->siguiente= cola.lista.vip->siguiente;
                cola.lista.vip->siguiente= nuevoNodo;
                if(cola.lista.cola->elemento.tipo==1) cola.lista.cola= nuevoNodo;
            }
            cola.lista.vip= nuevoNodo;   
            
        }else{
            cola.lista.cola->siguiente= nuevoNodo;
            cola.lista.cola= nuevoNodo;
        }
        
        
    }
    
    
    
}

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-1
 */
int main(int argc, char** argv) {

    struct Cola cola;
    struct Elemento elemento;
    construir(cola);

    /*Encolamos elementos en la Cola*/
    int contVipAten=0;
    int contVipNOAten=0;
    
    struct Elemento cliente;
    int tiempoReal=15;
    elemento.numero = 0;
    int cantClientes=6;
    for (int i = 0; i < cantClientes; i++) {
        elemento.numero += 15;
        if(i%2!=0)elemento.tipo = 1;
        else elemento.tipo=2;  
        insertarPrioridad(cola,elemento);
        
        cliente = desencolar(cola);
        if(cliente.tipo==1){
            if(tiempoReal-cliente.numero<=30){
                contVipAten++;
            }else contVipNOAten++;
        }
        tiempoReal+=20;
        
    }
    
    // recoremos la cola evaluando cuantos cleintes vip o no vip fueron atentido
    cout<<contVipAten<<endl;
    cout<<contVipNOAten<<endl;
    

   

    
   
    return 0;
}

