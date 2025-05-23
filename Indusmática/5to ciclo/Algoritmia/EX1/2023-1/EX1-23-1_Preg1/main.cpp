/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 22 de mayo de 2025, 14:45
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "funcionesPila.h"
#include "Elemento.h"
#include "Pila.h"

#define N 7

using namespace std;

/*
 * 
 */

void verificar(int servidores[][N]){
    
    Pila pila;
    Elemento elemento;
    bool verifica = true;
    int max = 0;
    elemento.numero = 0;
    apilar(pila,elemento);  
    
    for(int i = 1; i < N; i++){
        elemento = desapilar(pila);
        if(servidores[elemento.numero][i] == 0 or 
                servidores[i][elemento.numero] != 0){
            elemento.numero = i;
        }
        apilar(pila,elemento);
    }
    
    elemento = desapilar(pila);
    
    for(int i = 0; i < N; i++){
        if(i != elemento.numero and servidores[elemento.numero][i] == 0){
            verifica = false;
            break;
        }
        if(max < servidores[elemento.numero][i])
            max = servidores[elemento.numero][i];
    }
    for(int i = 0; i < N; i++){
        if(i != elemento.numero and servidores[i][elemento.numero] != 0){
            verifica = false;
            break;
        }
    }
    if(verifica){
        cout << "SkyNerd ha sido detectado en el servidor: " << elemento.numero + 1
                << endl;
        cout << "Maximo de paquetes enviados por SkyNerd: " << max << endl;
    }
    else
        cout << "SkyNerd no esta en la red" << endl;
}

int main(int argc, char** argv) {
    
    int servidores[N][N]{
        {0,10,10,10,20,10,10},
        {10,0,20,30,0,20,40},
        {0,0,0,0,0,100,0},
        {0,0,0,0,0,80,0},
        {50,10,5,10,0,100,4},
        {100,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
    };

    verificar(servidores);
    
    
    return 0;
}

