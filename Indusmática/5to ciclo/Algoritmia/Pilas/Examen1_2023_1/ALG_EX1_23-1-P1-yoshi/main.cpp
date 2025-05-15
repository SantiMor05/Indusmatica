/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 14 de mayo de 2025, 23:03
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
#define N 7
/*
 * 
 */

void llenar_pila(Pila &pila){
    Elemento elemento;
    for (int i = 0; i < N; i++){
        elemento.numero = i;
        apilar(pila,elemento);
    }
}

bool skyNerd(int mapa[][N], int &maximo, int &posSN){
    Pila pila;
    construir(pila);
    Elemento elemento, posibleSkyNerd;
    llenar_pila(pila);
    posibleSkyNerd = desapilar(pila);
    while(!esPilaVacia(pila)){
        elemento = desapilar(pila);
        if (mapa[posibleSkyNerd.numero][elemento.numero]==0 and mapa[elemento.numero][posibleSkyNerd.numero]>0)
            posibleSkyNerd.numero = elemento.numero;
    }
    for (int i = 0; i < N; i++) {
        if (i!=posibleSkyNerd.numero){
            if (mapa[posibleSkyNerd.numero][i]==0 or mapa[i][posibleSkyNerd.numero]>0)
                return false;
        }
        if (mapa[posibleSkyNerd.numero][i]>maximo)
            maximo = mapa[posibleSkyNerd.numero][i];
    }
    posSN = posibleSkyNerd.numero;
    return true;
}

int main(int argc, char** argv) {
    int mapa[][N] = {               {0,10,10,10,0,10,10},
                                    {10,0,20,30,0,20,40},
                                    {0,0,0,0,0,100,0},
                                    {0,0,0,0,0,80,0},
                                    {50,10,5,10,0,100,4},
                                    {100,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0}};
    int maximo=0, posSN;
    if (skyNerd(mapa,maximo,posSN)){
        cout<<"SkyNerd se ha enocntrado en el servidor "<<posSN+1<<endl;
        cout<<"Máximo de paquetes enviados por SkyNerd: "<<maximo<<endl;
    }else cout<<"SkyNerd no está en la red";
    return 0;
}

