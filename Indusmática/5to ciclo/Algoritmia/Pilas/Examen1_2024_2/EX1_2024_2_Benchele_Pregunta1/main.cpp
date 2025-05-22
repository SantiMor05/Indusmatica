/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 21 de mayo de 2025, 06:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "funcionesLista.h"
#include "Elemento.h"
#include "Pila.h"
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

/*
 * 
 */

void izquierda(int *altura, int *arregloConCant, int n){
    Pila auxPila;
    construir(auxPila);
    Elemento elePos;
    for (int i = 0; i < n; i++) {
        elePos.posicion = i;
        int cont = 0;
        while (!esPilaVacia(auxPila) and altura[cima(auxPila).posicion] < altura[i]) {
            cont +=arregloConCant[cima(auxPila).posicion] + 1;
            Elemento aux = desapilar(auxPila);
        }
        if(0 < cont){
            arregloConCant[i] = cont;
        }
        else{
            arregloConCant[i] = 0;
        }
        apilar(auxPila, elePos);
    }
}

void derecha(int *altura, int *arregloConCant, int n){
    //Es el mismo algoritmo que el de la izquierda, pero como es contando a la derecha, 
    //empiezas desde el ultimo hasta el primero
    Pila auxPila;
    construir(auxPila);
    Elemento elePos;
    for (int i = n - 1; i >= 0; i--) {
        elePos.posicion = i;
        int cont = 0;
        while (!esPilaVacia(auxPila) and altura[cima(auxPila).posicion] < altura[i]) {
            cont +=arregloConCant[cima(auxPila).posicion] + 1;
            Elemento aux = desapilar(auxPila);
        }
        if(0 < cont){
            arregloConCant[i] = cont;
        }
        else{
            arregloConCant[i] = 0;
        }
        apilar(auxPila, elePos);
    }
}

Elemento buscabajos(int *altura, int n){
    struct Elemento ganador;
    
    int mayor = 0;
    int cantPorPila_Der[n], cantPorPila_Izq[n];
    
    izquierda(altura, cantPorPila_Izq, n); //Cuenta las pilas menores a la izquierda de todas las pilas
    derecha(altura, cantPorPila_Der, n); //Cuenta las pilas menores a la derecha de todas las pilas 
    
    cout<<"COntador Izquierda: "<<endl;
    for (int i = 0; i < n; i++) cout<<cantPorPila_Izq[i]<<" ";
    cout<<endl<<"COntador derecha: "<<endl;
    for (int i = 0; i < n; i++) cout<<cantPorPila_Der[i]<<" ";
    cout<<endl;
    
    //Suma el numero de ambos arreglos y halla el mayor junto a su posicion
    cout<<"Suma arreglos: "<<endl;
    for (int i = 0; i < n; i++) {
        int cantIzq = cantPorPila_Izq[i];
        int cantDer = cantPorPila_Der[i];
        cout<<cantIzq+cantDer<<" ";
        if(mayor < cantIzq + cantDer){
            mayor = cantIzq + cantDer;
            ganador.cantidad = mayor;
            ganador.posicion = i;
            
        }
    }
    cout<<endl;
    return ganador;

}
int main(int argc, char** argv) {
    int n = 14;
    //int pilas[n] = {1, 3, 6, 4} ;
    //int pilas[n] = {2, 5, 7, 7, 1};
    int pilas[n] = {1, 7, 2, 7, 3, 4, 3, 2, 1, 7, 2, 1, 7, 3};
    //int pilas[n] = {6, 2, 5, 4, 5, 1, 6};
    
    struct Elemento pilaGanadora;
    pilaGanadora = buscabajos(pilas, n);
    
    cout<<"Posición: "<<pilaGanadora.posicion<<endl;
    cout<<"Pilas pequeñas alrededor: "<<pilaGanadora.cantidad<<endl;
    
    return 0;
}

