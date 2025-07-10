/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kalef Mandujano
 *
 * Descripción del código
 * 
 * Created on 8 de julio de 2025, 09:59 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>

#include "ArbolBB.h"
#include "Elemento.h"
#include "funcionesAB.h"
#include "funcionesABB.h"

using namespace std;

void contarNodos(NodoArbol *raiz,int &cont){
    if(raiz){
        contarNodos(raiz->izquierda,cont);
        contarNodos(raiz->derecha,cont);
        cont++;
    }
}

void colocarDatos(NodoArbol *&raiz,Elemento aux){
    if(raiz == nullptr){
        raiz = new NodoArbol;
        raiz->elemento = aux;
        raiz->derecha = nullptr;
        raiz->izquierda = nullptr;
        return;
    }
    if(aux.numero < raiz->elemento.numero){
        colocarDatos(raiz->izquierda,aux);
    }else{
        colocarDatos(raiz->derecha,aux);
    }
}


void insertarR(ArbolBinario &arbol,Elemento aux){
    colocarDatos(arbol.raiz,aux);
}

NodoArbol *buscarNodo(NodoArbol *raiz,char car,int pos){
    if(raiz){
        if(raiz->elemento.numero == pos){
            if(raiz->elemento.letra == car){
                return raiz;
            }else{
                return nullptr;
            }
        }
        if(pos < raiz->elemento.numero){
            //Vamos izquierda
            return buscarNodo(raiz->izquierda,car,pos);
        }else{
            //Vamos derecha
            return buscarNodo(raiz->derecha,car,pos);
        }
    }
    return nullptr;
}

void verificarContrasena(ArbolBinario arbolBinario,char *cadena,int &tam){
    NodoArbol *aux;
    for (int i = 0; cadena[i]; i++) {
        aux = buscarNodo(arbolBinario.raiz,cadena[i],i+1);
        if(aux){
            tam--;
        }
    }

}



int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda arbol;
    
    construir(arbol);
    
    Elemento aux;
    
    aux.numero = 4;
    aux.letra = 'P';
    
    insertarR(arbol.arbolBinario,aux);
    
    aux.numero = 2;
    aux.letra = 'U';
    
    insertarR(arbol.arbolBinario,aux);
    
    aux.numero = 6;
    aux.letra = '0';
    
    insertarR(arbol.arbolBinario,aux);
    
    aux.numero = 1;
    aux.letra = 'P';
    
    insertarR(arbol.arbolBinario,aux);
    
    aux.numero = 3;
    aux.letra = 'C';
    
    insertarR(arbol.arbolBinario,aux);
    
    aux.numero = 5;
    aux.letra = '2';
    
    insertarR(arbol.arbolBinario,aux);
    
    aux.numero = 7;
    aux.letra = '2';
    
    insertarR(arbol.arbolBinario,aux);
    
    aux.numero = 8;
    aux.letra = '4';
    
    insertarR(arbol.arbolBinario,aux);
    
    
//    recorrerEnOrden(arbol.arbolBinario);
    
    int n, cont = 0;
    cout<<"Ingrese el número máximo de intentos: ";
    cin>>n;
    char cadena[10];
    contarNodos(arbol.arbolBinario.raiz,cont);
    int tam;
    bool band = true;
    for (int i = 0; i < n; i++) {
        cout<<"Intento "<<i+1<<"/3. Ingrese la contraseña: ";
        cin>>cadena;
        tam = strlen(cadena);
        if(tam == cont){
            //Procedemos a ver si la contraseña se encuentra
            verificarContrasena(arbol.arbolBinario,cadena,tam);
            if(tam == 0){
                //Si el tamaño es igual a '0' quiere decir que la cadena era la contraseña
                cout<<"Acceso concedido"<<endl;
                band = false;
                break;
            }else{
                cout<<"Contraseña incorrecta. Intento fallido"<<endl;
            }
        }else{
            cout<<"Longitud incorrecta. Intento fallido."<<endl;
        }
    }
    if(band){
        cout<<"Se llego al numero de intentos fallidos permitidos"<<endl;
    }

    
    
    
    
    return 0;
}

