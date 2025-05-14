/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 13 de mayo de 2025, 09:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

/*
 * 
 */

void submarino(char *ordenes, int cantOrd){
    Pila pila;
    construir(pila);
    Elemento nivel;

    for (int i = 0; i <= cantOrd; i++) { //3 ordenes -> 4 niveles
        nivel.numero = i + 1;
        apilar(pila, nivel); //Va apilando
        
        if(i == cantOrd or ordenes[i] == 'S'){ //Si encuentra 'S' lo desapila todo //O si es la ultima iteración coloca el ultimo nivel hallado(i + 1 = cantOrd + 1)
            while (!esPilaVacia(pila)){ 
                nivel = desapilar(pila);
                cout<<nivel.numero<<" ";
            }
        }
    }
}
int main(int argc, char** argv) {
    //char ordenes[5]{'S', 'S', 'S', 'B', 'S'};
    char ordenes[3]{'B', 'B', 'S'}; //Caso mas fácil para entender lo que se pide
    //char ordenes[7]{'S', 'B', 'S', 'B', 'B', 'S', 'S'};
    int cantOrd = 3;
    
    cout<<"La unidad recibe la siguiente orden: ";
    for(int i = 0; i < cantOrd; i++)cout<<ordenes[i]<<" ";
    cout<<endl<<"La respuesta es: ";
    submarino(ordenes, cantOrd);
    
    return 0;
}

