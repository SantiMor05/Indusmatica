/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de mayo de 2025, 18:34
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "funcionesPila.h"
#include "Elemento.h"
#include "Pila.h"
#include "funcionesLista.h"


using namespace std;

/*
 * 
 */


void encontrarMasGrande(Pila &pila, int &posMax, int &contMax, int n){
    
    Elemento elemento1,elemento2;
    int cont, aux;
    
    if(pila.lista.longitud == 1){
        elemento1 = desapilar(pila);
        posMax = elemento1.numero;
        contMax = n - 1;
    }
    else{
        elemento1 = desapilar(pila);
        cont = n - elemento1.numero - 1;
        while(!esPilaVacia(pila)){
            elemento2 = desapilar(pila);
            aux = elemento1.numero - elemento2.numero - 1;
            if(cont + aux > contMax){
                contMax =  cont + aux;
                posMax = elemento1.numero;
            }
            
            elemento1 = elemento2;
            cont = aux;            
        }
        aux = elemento1.numero;
        if(cont + aux > contMax){
            contMax =  cont + aux;
            posMax = elemento1.numero;
        }
        
    }
    
}


int main(int argc, char** argv) {

    Pila pila;
    Elemento elemento;
    int ant = 0, max = 0, pos, posMax;
    int cont = 0, contMax = 0;
    construir(pila);

    int pilas[]{1,3,6,4};
    int n = 4;

//    int pilas[]{2,5,7,7,1};
//    int n = 5;

//    int pilas[]{1,7,2,7,3,4,3,2,1,7,2,1,7,3};
//    int n = 14;
//
//    int pilas[]{6,2,5,4,5,1,6};
//    int n = 7;
//

    

    //No sabia que era O(n) xdddd
//    for (int i = 0; i < n; i++) {
//        if(pilas[i] >= max){
//            if(pilas[i] > max){
//                while(!esPilaVacia(pila))
//                    elemento = desapilar(pila);
//                
//            max = pilas[i];
//            }
//            elemento.numero = i;
//            apilar(pila,elemento);
//        }
//        
//    }
    
    for (int i = 0; i < n; i++)
        if(pilas[i] > max)
            max = pilas[i];
    
    
    for (int i = 0; i < n; i++) {
        if(pilas[i] == max){
            elemento.numero = i;
            apilar(pila,elemento);
        }
        
    }
    
    encontrarMasGrande(pila, posMax, contMax, n);
    

    cout << "Posicion = " << posMax << ", con " << contMax << " pilas"
            " pequeñas alrededor" << endl;

    return 0;
}

