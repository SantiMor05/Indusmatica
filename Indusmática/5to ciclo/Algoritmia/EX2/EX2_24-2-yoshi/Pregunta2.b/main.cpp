/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 8 de julio de 2025, 18:43
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
/*
 * 
 */

void llenadoEnOrden(char* contrasenha,NodoArbol *raiz,int &i){
    if (raiz){
        llenadoEnOrden(contrasenha,raiz->izquierda,i);
        contrasenha[i++] = raiz->elemento.letra;
        llenadoEnOrden(contrasenha,raiz->derecha,i);
    }
}

bool evaluarPalabra(char* palabra,ArbolBinarioBusqueda arbol){
    char contrasenha[20]{};
    int i = 0;
    llenadoEnOrden(contrasenha,arbol.arbolBinario.raiz,i);
    if (strlen(contrasenha)==strlen(palabra)){
        if (strcmp(contrasenha,palabra)==0){
            cout<<"Acceso concedido"<<endl;
            return true;
        }else{
            cout<<"Contraseña incorrecta. Intento fallido"<<endl;
            return false;
        }
    }else{
        cout << "Longitud incorrecta. Intento fallido"<<endl;
        return false;
    }
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    Elemento temp;
    temp.numero = 4;
    temp.letra = 'P';
    insertar(arbol,temp);
    temp.numero = 2;
    temp.letra = 'U';
    insertar(arbol,temp);
    temp.numero = 1;
    temp.letra = 'P';
    insertar(arbol,temp);
    temp.numero = 3;
    temp.letra = 'C';
    insertar(arbol,temp);
    temp.numero = 6;
    temp.letra = '0';
    insertar(arbol,temp);
    temp.numero = 5;
    temp.letra = '2';
    insertar(arbol,temp);
    temp.numero = 7;
    temp.letra = '2';
    insertar(arbol,temp);
    temp.numero = 8;
    temp.letra = '4';
    insertar(arbol,temp);
    
    int n;
    cout<<"Ingrese el número máximo de intentos: ";
    cin>>n;
    char palabra[15];
    for (int i = 1; i <= n; i++) {
        cout<<"Intento "<<i<<"/"<<n<<". Ingrrse la contraseña: ";
        cin>>palabra;
        if (evaluarPalabra(palabra,arbol)){
            return 0;
        }
    }
    cout<<"Se llegó al número de intentos fallidos permitidos";
    return 0;
}

