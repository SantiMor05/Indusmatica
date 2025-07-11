/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 8 de julio de 2025, 23:23
 */

#include "funcionesABB.h"
#include "ArbolBB.h"
#include "funcionesAB.h"
#include <cstring>
#include <iostream>

using namespace std;

/*
 * 
 */


void verificarEnOrden(NodoArbol *nodo,char *contra, int &n, bool &valido){
    
    if(nodo == nullptr)return;
    
    verificarEnOrden(nodo->izquierda, contra, n, valido);
    
    if(nodo->elemento.letra != contra[n]){
        valido = false;
        return;
    }
    n++;
    verificarEnOrden(nodo->derecha, contra, n, valido);
   
}


int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda arbol;
    Elemento elemento;
    construir(arbol);
    elemento.pos = 4;
    elemento.letra = 'P';
    insertar(arbol,elemento);
    
    elemento.pos = 2;
    elemento.letra = 'U';
    insertar(arbol,elemento);
    
    elemento.pos = 1;
    elemento.letra = 'P';
    insertar(arbol,elemento);
    
    elemento.pos = 3;
    elemento.letra = 'C';
    insertar(arbol,elemento);
    
    elemento.pos = 6;
    elemento.letra = '0';
    insertar(arbol,elemento);
    
    elemento.pos = 5;
    elemento.letra = '2';
    insertar(arbol,elemento);
    
    elemento.pos = 7;
    elemento.letra = '2';
    insertar(arbol,elemento);
    
    elemento.pos = 8;
    elemento.letra = '4';
    insertar(arbol,elemento);
    
    enOrden(arbol);
    
    int maxIntentos, n;
    char contra[15]{};
    bool valido;
    cout << "Ingrese el numero maximo de intentos: ";
    cin >> maxIntentos;
    
    for(int i = 0; i < maxIntentos; i++){
        
        cout << "Intento " << i + 1 << "/" << maxIntentos<<". Ingrese la contraseña:";
        cin >> contra;
        if(strlen(contra) != arbol.longitud){
            cout << "Longitud incorrecta. Intento fallido." << endl;
            valido = false;
        }
        else{
            n = 0;
            valido = true;
            verificarEnOrden(arbol.arbolBinario.raiz, contra, n, valido);
            if(valido){
                cout << "Acceso concedido";
            }
            else
                cout <<"Contraseña incorrecta. Intento fallido" << endl;
        }
    }
    if(!valido)
        cout << "Se llego al numero de intentos fallidos permitidos" << endl;
    
    return 0;
}

