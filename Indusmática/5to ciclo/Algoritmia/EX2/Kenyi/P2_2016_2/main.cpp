/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 10 de julio de 2025, 09:08 PM
 */

#include <iostream>
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"

using namespace std;

/*
 * 
 */
void encontrarCaminos(NodoArbol* nodo, int sumaActual, int q, int camino[], int nivel) {
    if (nodo == nullptr) return;

    // Agregar el nodo actual al camino
    camino[nivel] = nodo->elemento.numero;
    sumaActual += nodo->elemento.numero;

    // Si es hoja y la suma es q, imprimir camino
    if (nodo->izquierda == nullptr && nodo->derecha == nullptr && sumaActual == q) {
        for (int i = 0; i <= nivel; i++) {
            cout << camino[i] << " ";
        }
        cout << endl;
    }

    // Recursión a los hijos
    encontrarCaminos(nodo->izquierda, sumaActual, q, camino, nivel + 1);
    encontrarCaminos(nodo->derecha, sumaActual, q, camino, nivel + 1);
}


int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,{10});
    insertar(arbol,{5});
    insertar(arbol,{12});
    insertar(arbol,{4});
    insertar(arbol,{7});
//    enOrden(arbol);
    int camino[20];
    encontrarCaminos(arbol.arbolBinario.raiz,0,22,camino,0);
    return 0;
}

