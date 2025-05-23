/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de mayo de 2025, 23:05
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
int main(int argc, char** argv) {
    
    Pila pila;
    Elemento elemento;
    construir(pila);
    
//    char mov[] = {'S','S', 'S','B','S'};
//    int n = 5;
    
//    char mov[] = {'B','B', 'S'};
//    int n = 3;
    
    char mov[] = {'S','B', 'S','B','B','S','S', 'B'};
    int n = 8;
//    
// 
    
    for(int i = 0; i < n + 1; i++){
            elemento.numero = i + 1;
            apilar(pila, elemento);
            if(i == n or mov[i] == 'S'){
                while(!esPilaVacia(pila)){
                    elemento = desapilar(pila);
                    cout << elemento.numero << " ";
                }    
            }
    }

    return 0;
}

