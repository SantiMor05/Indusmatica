/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 9 de julio de 2025, 13:50
 */

#include <iostream>
#include <map>
#include <vector>
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "Elemento.h"
#include "funcionesAB.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"

using namespace std;

/*
 * Guia de emociones
 * 
 * 1:Alegria
 * 2: Tristeza
 * 3: Temor
 * 4: Furia
 * 5: Desagrado
 * 6: Ansiedad
 * 7: Envidia
 * 8: Venguenza
 * 9: Aburrimiento
 * 
 * 1:55:00
 * 
 */


NodoArbol *buscarNodo(ArbolBinarioBusqueda &arbol, Elemento elemento) {

    NodoArbol *nodo = arbol.arbolBinario.raiz;

    while (nodo) {
        if (elemento.numero < nodo->elemento)
            nodo = nodo->izquierda;
        else if (elemento.numero > nodo->elemento)
            nodo = nodo->derecha;
        else
            return nodo;
    }
    return nullptr;
}

bool seEncuentra(vector<int> &emociones, int emocion) {
    for (auto &emo : emociones) {
        if (emocion == emo)
            return true;
    }
    return false;
}

bool verificarEncuentra(int *combinaciones, map<int, vector<int>> &pesosEmociones, 
        NodoArbol *nodo, int n) {

    if (nodo == nullptr)return false;

    vector<int> emociones;
    for (auto &emocion : pesosEmociones) {
        for (auto &peso : emocion.second) {
            if (peso == nodo->elemento) {
                emociones.push_back(emocion.first);
                break;
            }
        }
    }
    bool izq, der;
    if(seEncuentra(emociones, combinaciones[n])){
        if(n == 2)return true;
        izq = verificarEncuentra(combinaciones, pesosEmociones, nodo->izquierda, n + 1);
        der = verificarEncuentra(combinaciones, pesosEmociones, nodo->derecha, n + 1);
    }
    else
        return false;

    
    return izq or der;
}

void reiniciarCombinaciones(int *combinacionesValidadas){
    
    for(int i = 0; i < 3; i++)
        combinacionesValidadas[i] = 0;
    
}

void buscarCombinaciones(map<int, vector<int>> &pesosEmociones, ArbolBinarioBusqueda &arbol,
        int combinaciones[][3]) {

    Cola cola;
    NodoArbol *nodo = arbol.arbolBinario.raiz;
    Elemento elemento;
    construir(cola);
    elemento.numero = nodo->elemento;
    encolar(cola, elemento);
    int n, nivel = 1, combinacionesValidas;
    int combinacionesValidadas[3], altura;
    bool mayor;
    while (!esColaVacia(cola)) {
        n = cola.lista.longitud;
        combinacionesValidas = 0;
        reiniciarCombinaciones(combinacionesValidadas);
        mayor = false;
        for (int i = 0; i < n; i++) {
            elemento = desencolar(cola);
            nodo = buscarNodo(arbol, elemento);
            //Buscamos a que emocion pertenece el nodo
            altura = alturaRecursivo(nodo) + 1;
            if (altura>= 3) {
                //Tenemos todas las emociones a la que corresponde el nodo
                //Verificamos las emociones con las combinaciones
                for (int j = 0; j < 3; j++) {
                    bool se_encuentra = verificarEncuentra(combinaciones[j], pesosEmociones, nodo, 0);
                    //Puede que una combinación se cumpla en varios nodos del mismo nivel
                    //para eso solo aumentamos la combinaciones cuando la combinación que está 
                    //siendo evaluada no se haya verificado ya
                    if(se_encuentra){
                        combinacionesValidas++;
                        combinacionesValidadas[j] = 1;
                    }
                }
                mayor = true;
            }

            if (nodo->izquierda) {
                elemento.numero = nodo->izquierda->elemento;
                encolar(cola, elemento);
            }
            if (nodo->derecha) {
                elemento.numero = nodo->derecha->elemento;
                encolar(cola, elemento);
            }
        }
        if(mayor){
            cout << "Nivel " << nivel << " - " << combinacionesValidas << " combinaciones" << endl;
        }
        nivel++;
    }
}

int main(int argc, char** argv) {

    map<int, vector<int>> pesosEmociones;
    ArbolBinarioBusqueda arbol;
    construir(arbol);



    pesosEmociones[1] = {180, 200};
    pesosEmociones[2] = {140, 230, 80};
    pesosEmociones[3] = {240, 100};
    pesosEmociones[4] = {280};
    pesosEmociones[5] = {250};
    pesosEmociones[6] = {260, 120};
    pesosEmociones[7] = {160, 240};
    pesosEmociones[8] = {120, 80};
    pesosEmociones[9] = {150, 230, 90};



    insertar(arbol, 180);
    insertar(arbol, 120);
    insertar(arbol, 100);
    insertar(arbol, 80);
    insertar(arbol, 90);
    insertar(arbol, 150);
    insertar(arbol, 140);
    insertar(arbol, 160);
    insertar(arbol, 250);
    insertar(arbol, 230);
    insertar(arbol, 200);
    insertar(arbol, 240);
    insertar(arbol, 280);
    insertar(arbol, 260);

    int combinaciones[3][3] = {
        {6, 9, 2},
        {5, 2, 3},
        {3, 8, 9}
    };

    buscarCombinaciones(pesosEmociones, arbol, combinaciones);

    return 0;
}

