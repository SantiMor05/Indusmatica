/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 13 de mayo de 2025, 08:09 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
#include "Elemento.h"
using namespace std;

/*
 * 
 */

#define N 7
#define NO_ES_SKY -1

int red_1[N][N] = {{0,0,0,0,0,0,0},
                 {10,0,20,30,0,20,40},
                 {0,0,0,0,0,100,0},
                 {0,0,0,0,0,80,0},
                 {50,10,500,10,0,100,4},
                 {100,0,0,0,0,0},
                 {0,0}
};
int red_2[N][N] = {{0,10,10,10,20,10,10},
                 {10,0,20,30,0,20,40},
                 {0,0,0,0,0,100,0},
                 {0,0,0,0,0,80,0},
                 {50,10,5,10,0,100,4},
                 {100, 0,0,0,0,0},
                 {0,0}
};

void buscarServidor(int n, int &serverSky, int &max){
    struct Pila pila;
    struct Elemento serA, serB, temp, cand;
    //Server A = Fila, Server B = Columna
    
    construir(pila);
    
    for (int i = 0; i < n; i++) { //Generando el numero de los servidores 
        temp.numero = i;
        apilar(pila, temp);
    }
    
    while (longitud(pila) > 1) { //Mayor que 1 porque tiene que quedar un candidato al final de la iteracion
        serA = desapilar(pila);
        serB = desapilar(pila);
        if(red_1[serA.numero][serB.numero] == 0){
            apilar(pila, serB);
        }
        else{
            apilar(pila, serA);
        }
    }
    cand = desapilar(pila); 
    
    //Verificacion fila y columna
    
    //Opcion 1: A la misma vez
    max = 0;
    for (int i = 0; i < n; i++) {
        if(i!= cand.numero and (red_1[i][cand.numero] != 0 or not red_1[cand.numero][i])){
           //Si no es el mismo,    si recibe algo                  si no da algo
            serverSky = NO_ES_SKY;
            return;
        }
        if(max < red_1[cand.numero][i])max = red_1[cand.numero][i];
    }
    serverSky = cand.numero + 1;
    return;
    
    //Opcion 2: Por separado
    
    max = 0;
    int esSky = 1;
    for(int i = 0; i < n; i++){ //Revisa por columnas
        if(not red_1[cand.numero][i] and i!=cand.numero){
            //Si no da algo           Si no es el mismo
            esSky = 0;
            return;
        }
        if(max < red_1[cand.numero][i])max = red_1[cand.numero][i]; 
    } 
    
    if(esSky == 1){ //Revisa por filas
        for(int i = 0; i < n; i++){
            if(red_1[i][cand.numero]!=0) esSky = 0;
                //Si recibe algo
        }
    }   
    
    if(esSky == 1){
        serverSky = cand.numero+1;
        return;
    }
    
    serverSky = NO_ES_SKY;
    return;  
}

int main(int argc, char** argv) {
    int serverSky, maxPaq;
    buscarServidor(N, serverSky, maxPaq);
    
    if(serverSky != NO_ES_SKY){
        cout<<"SkyNerd ha sido detectado en el servidor: "<<serverSky<<endl;
        cout<<"Máximo de paquetes enviados por SkyNerd: "<<maxPaq<<endl;
    }
    else{
        cout<<"SkyNerd no está en la red "<<endl;
    }
    
    return 0;
}

