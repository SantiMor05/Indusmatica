/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 9 de julio de 2025, 06:15 PM
 */

#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "ArbolB.h"
using namespace std;

/*
 * 
 */

string determinarCategoria(const string palabra) {
    const char* articulos[] = {"el", "la", "los", "las", "un", nullptr};
    const char* sustantivos[] = {"gato", "perro", "casa", "mesa", "silla", nullptr};
    const char* verbos[] = {"come", "salta", "duerme", nullptr};
    for (int i = 0; articulos[i]; i++) {
        if (strcmp(palabra.c_str(), articulos[i]) == 0)return "_ARTICULO";
    }
    for (int i = 0; sustantivos[i]; i++) {
        if (strcmp(palabra.c_str(), sustantivos[i]) == 0)return "_SUSTANTIVO";
    }
    for (int i = 0; verbos[i]; i++) {
        if (strcmp(palabra.c_str(), verbos[i]) == 0)return "_VERBO";
    }
    return "_NO_CUMPLE";
}

void crearArbolGramatical(ArbolBinario &arbol) {
    Elemento elemento;
    strcpy(elemento.nombre, " ");
    strcpy(elemento.categoria, "ORACION");
    plantarArbolBinario(arbol, nullptr, elemento, nullptr);
    strcpy(elemento.categoria, "_SUJETO");
    plantarArbolBinario(arbol.raiz->izquierda, nullptr, elemento, nullptr);
    strcpy(elemento.categoria, "_PREDICADO");
    plantarArbolBinario(arbol.raiz->derecha, nullptr, elemento, nullptr);
    ifstream arch("datos.txt", ios::in);
    if (!arch) {
        cout << "Error al abrir el archivo datos.txt";
        exit(1);
    }
    string palabra, categoria;
    bool llenoA = false, llenoS = false, llenoV = false;
    while (true) {
        arch>>palabra;
        if (arch.eof())break;
        categoria = determinarCategoria(palabra);
        Elemento elemento;
        strcpy(elemento.nombre, palabra.c_str());
        strcpy(elemento.categoria, categoria.c_str());
        if (!llenoA) {
            plantarArbolBinario(arbol.raiz->izquierda->izquierda, nullptr, elemento, nullptr);
            llenoA = true;
        } else if (!llenoS) {
            plantarArbolBinario(arbol.raiz->izquierda->derecha, nullptr, elemento, nullptr);
            llenoS = true;
        } else if (!llenoV) {
            plantarArbolBinario(arbol.raiz->derecha->izquierda, nullptr, elemento, nullptr);
            llenoV = true;
        }
        if (llenoA and llenoS and llenoV) break;
    }
}

void validarArbolGramatical(ArbolBinario arbol) {
    bool invalido = false;
    if (arbol.raiz == nullptr) {
        cout << "Error: El aborl no existe" << endl;
        invalido = true;
    } else if (strcmp(arbol.raiz->izquierda->izquierda->elemento.categoria, "_ARTICULO") != 0) {
        invalido = true;
        cout << "Error: ";
        if (strcmp(arbol.raiz->izquierda->izquierda->elemento.categoria, "_SUSTANTIVO") == 0)
            cout << "Articulo debe estar antes del sustantivo" << endl;
        else if (strcmp(arbol.raiz->izquierda->izquierda->elemento.categoria, "_VERBO") == 0)
            cout << "Articulo debe estar antes del verbo" << endl;
    } else if (strcmp(arbol.raiz->izquierda->derecha->elemento.categoria,"_SUSTANTIVO" ) != 0) {
        invalido = true;
        cout << "Error: ";
        if (strcmp(arbol.raiz->izquierda->derecha->elemento.categoria,"_VERBO" ) == 0)
            cout << "Sustantivo debe estar antes del verbo" << endl;
    }

    if (!invalido) {
        cout << "Arbol valido!" << endl;
        recorrerPreOrdenRecursivo(arbol.raiz); // cree otro imprimiNodo2
    } else {
        cout << "Arbol Invalido!" << endl;
        cout << "Oracion:";
        recorrerEnOrdenRecursivo(arbol.raiz);
    }
}

int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    crearArbolGramatical(arbol);
    validarArbolGramatical(arbol);
    return 0;
}

