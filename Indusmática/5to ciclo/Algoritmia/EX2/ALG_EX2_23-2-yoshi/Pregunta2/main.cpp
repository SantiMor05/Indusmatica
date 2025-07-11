/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 9 de julio de 2025, 16:58
 */

#include <iostream>
#include <string>
#include <cstring>
#include "ArbolB.h"
#include "funcionesAB.h"
using namespace std;

/*
 * 
 */

//función que recorre la palabra validando si ha sido completamente encontrada
bool estoyFreddyFazbear(char *cad, int n){
    for (int i = 0; i < n; i++) {
        if (cad[i] != 0)
            return false;
    }
    return true;
}

//si encuentra una letra de la palabra, la marca con 0 par no repetir letra
bool FNAF(char letra,char *cad, int n){
    for (int i = 0; i < n; i++) {
        if (cad[i] == letra){
            cad[i] = 0;
            return true;
        }
    }
    return false;
}

bool EstaPalabra(NodoArbol* raiz,char* cad, int num){
    if (raiz){
        if (FNAF(raiz->elemento.letra,cad,num)){
            if (estoyFreddyFazbear(cad,num))
                return true;
            else{
                if (EstaPalabra(raiz->izquierda,cad,num))
                    return true;
                else if (EstaPalabra(raiz->derecha,cad,num))
                    return true;
                    else return false;
            }
        }
    }
    return false;
}

bool validarPalabra(const ArbolBinario &arbol,char* palabra){
    if (EstaPalabra(arbol.raiz,palabra,strlen(palabra)))
        return true;
    return false;
}


int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    //nivel 0
    arbol.raiz = new NodoArbol;
    arbol.raiz->elemento.letra = 'L';
    
    //nivel 1
    arbol.raiz->izquierda = new NodoArbol;
    arbol.raiz->izquierda->elemento.letra = 'D';
    arbol.raiz->derecha = new NodoArbol;
    arbol.raiz->derecha->elemento.letra = 'I';
    
    //nivel 2
    arbol.raiz->izquierda->izquierda = new NodoArbol;
    arbol.raiz->izquierda->izquierda->elemento.letra = 'E';
    arbol.raiz->izquierda->derecha = new NodoArbol;
    arbol.raiz->izquierda->derecha->elemento.letra = 'E';
    arbol.raiz->derecha->izquierda = new NodoArbol;
    arbol.raiz->derecha->izquierda->elemento.letra = 'C';
    arbol.raiz->derecha->derecha = new NodoArbol;
    arbol.raiz->derecha->derecha->elemento.letra = 'N';
    
    //nivel 3
    arbol.raiz->izquierda->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->izquierda->izquierda = nullptr;
    arbol.raiz->izquierda->derecha->izquierda = new NodoArbol;
    arbol.raiz->izquierda->derecha->izquierda->elemento.letra = 'R';
    arbol.raiz->izquierda->derecha->derecha = new NodoArbol;
    arbol.raiz->izquierda->derecha->derecha->elemento.letra = 'G';
    arbol.raiz->derecha->izquierda->izquierda = new NodoArbol;
    arbol.raiz->derecha->izquierda->izquierda->elemento.letra = 'C';
    arbol.raiz->derecha->izquierda->derecha = nullptr;
    arbol.raiz->derecha->derecha->izquierda = new NodoArbol;
    arbol.raiz->derecha->derecha->izquierda->elemento.letra = 'A';
    arbol.raiz->derecha->derecha->derecha = nullptr;
    
    //nivel 4
    arbol.raiz->izquierda->derecha->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->derecha->izquierda->izquierda = nullptr;
    arbol.raiz->izquierda->derecha->derecha->derecha = nullptr;
    arbol.raiz->derecha->izquierda->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->derecha->derecha->izquierda = new NodoArbol;
    arbol.raiz->izquierda->derecha->derecha->izquierda->elemento.letra = 'T';
    arbol.raiz->izquierda->derecha->derecha->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->derecha->derecha->izquierda->izquierda = nullptr;
    arbol.raiz->derecha->izquierda->izquierda->izquierda = new NodoArbol;
    arbol.raiz->derecha->izquierda->izquierda->izquierda->izquierda = nullptr;
    arbol.raiz->derecha->izquierda->izquierda->izquierda->derecha = nullptr;
    arbol.raiz->derecha->izquierda->izquierda->izquierda->elemento.letra = 'O';
    arbol.raiz->derecha->derecha->izquierda->izquierda = new NodoArbol;
    arbol.raiz->derecha->derecha->izquierda->izquierda->elemento.letra = 'F';
    arbol.raiz->derecha->derecha->izquierda->izquierda->derecha = nullptr;
    arbol.raiz->derecha->derecha->izquierda->izquierda->izquierda = nullptr;
    arbol.raiz->derecha->derecha->izquierda->derecha = new NodoArbol;
    arbol.raiz->derecha->derecha->izquierda->derecha->elemento.letra = 'T';
    arbol.raiz->derecha->derecha->izquierda->derecha->derecha = nullptr;
    arbol.raiz->derecha->derecha->izquierda->derecha->izquierda = nullptr;
        
    char** mensajeDonatello = new char*[7];
    mensajeDonatello[0] = new char[strlen("HIJO")+1]{};
    strcpy(mensajeDonatello[0],"HIJO");
    mensajeDonatello[1] = new char[strlen("FINAL")+1]{};
    strcpy(mensajeDonatello[1],"FINAL");
    mensajeDonatello[2] = new char[strlen("MUNDO")+1]{};
    strcpy(mensajeDonatello[2],"MUNDO");
    mensajeDonatello[3] = new char[strlen("DEL")+1]{};
    strcpy(mensajeDonatello[3],"DEL");
    mensajeDonatello[4] = new char[strlen("DIA")+1]{};
    strcpy(mensajeDonatello[4],"DIA");
    mensajeDonatello[5] = new char[strlen("CICLO")+1]{};
    strcpy(mensajeDonatello[5],"CICLO");
    mensajeDonatello[6] = new char[strlen("FIN")+1]{};
    strcpy(mensajeDonatello[6],"FIN");
    char cad[100];
    cout<<"Mensaje de Dontalleo al maestro Splinter: ";
    for (int i = 0; i < 7; i++) {
        strcpy(cad,mensajeDonatello[i]);
        if (validarPalabra(arbol,mensajeDonatello[i])){
            cout << cad << " ";
        }
    }

    
    return 0;
}

