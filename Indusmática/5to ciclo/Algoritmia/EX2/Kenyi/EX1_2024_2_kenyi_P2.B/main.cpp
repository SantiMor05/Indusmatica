/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 9 de julio de 2025, 11:23 PM
 */

#include <iostream>
#include <string.h>
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
using namespace std;

/*
 * 
 */

void completarContrasena(const NodoArbol *raiz, char * contrasena, int &i) {
    if (raiz) {
        completarContrasena(raiz->izquierda, contrasena, i);
        contrasena[i++] = raiz->elemento.c;
        completarContrasena(raiz->derecha, contrasena, i);
    }
}

bool validarContrasena(const ArbolBinarioBusqueda arbol, const char *palabra) {
    char constrasena[20]{};
    int i = 0;
    completarContrasena(arbol.arbolBinario.raiz, constrasena, i);
    if (strlen(constrasena) == strlen(palabra)) {
        if (strcmp(constrasena, palabra) == 0) {
            cout << "Acceso concedido" << endl;
            return true;
        } else {
            cout << "Contraseña incorrecta. Inteto fallido" << endl;
            return false;
        }
    } else cout << "Longitud incorrecta. Intento fallido" << endl;
    return false;
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    Elemento elemento;
    elemento.numero = 4;
    elemento.c = 'P';
    insertar(arbol, elemento);
    elemento.numero = 2;
    elemento.c = 'U';
    insertar(arbol, elemento);
    elemento.numero = 6;
    elemento.c = '0';
    insertar(arbol, elemento);
    elemento.numero = 1;
    elemento.c = 'P';
    insertar(arbol, elemento);
    elemento.numero = 3;
    elemento.c = 'C';
    insertar(arbol, elemento);
    elemento.numero = 5;
    elemento.c = '2';
    insertar(arbol, elemento);
    elemento.numero = 7;
    elemento.c = '2';
    insertar(arbol, elemento);
    elemento.numero = 8;
    elemento.c = '4';
    insertar(arbol, elemento);
    cout << "Ingrese el numero maximo de intentos: ";
    int intentos;
    char contrasena[10];
    bool encontro = false;
    ;
    cin>>intentos;

    for (int i = 0; i < intentos; i++) {
        cout << "Intento " << i + 1 << "/3 . Ingrese la contraseña: ";
        cin>>contrasena;
        if (validarContrasena(arbol, contrasena)) {
            encontro = true;
            break;
        }
    }
    if (!encontro) cout << "Se llego al numero de intentos fallidos permitidos" << endl;

//    recorrerEnOrden(arbol.arbolBinario);

    return 0;
}

