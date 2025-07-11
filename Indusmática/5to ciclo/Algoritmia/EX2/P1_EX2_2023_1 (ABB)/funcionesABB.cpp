/* 
 * File:   funcionesABB.cpp
 * Author: ANA RONCAL
 * 
 * Created on 13 de noviembre de 2024, 13:50
 */

#include <iostream>
#include <iomanip>
#include "Elemento.h"
#include "ArbolBB.h"
using namespace std;

#include "funcionesAB.h"
#include "funcionesABB.h"

void construir(struct ArbolBinarioBusqueda & arbol){
    construir(arbol.arbolBinario);
}

void insertarRecursivo(struct NodoArbol *& raiz, const struct Elemento & elemento){
    if(esNodoVacio(raiz))
        plantarArbolBinario(raiz, nullptr, elemento, nullptr);
    else
        if(raiz->elemento.numero > elemento.numero)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            if(raiz->elemento.numero < elemento.numero)
                insertarRecursivo(raiz->derecha, elemento);
            else
                cout << "El elemento " << elemento.numero << "Ya se encuentra en el árbol" << endl;
}

void insertar(struct ArbolBinarioBusqueda & arbol, const struct Elemento & elemento){
    insertarRecursivo(arbol.arbolBinario.raiz, elemento);
}

void enOrden(const struct ArbolBinarioBusqueda & arbol){
    recorrerEnOrden(arbol.arbolBinario);
}

int comparaABB(int elementoA, int elementoB){
    if(elementoA == elementoB) return 0;
    else if(elementoA < elementoB) return -1;
    else if(elementoA > elementoB) return 1;
}

bool buscarRecursivo(struct NodoArbol * nodo, const struct Elemento & elemento){
    if(esNodoVacio(nodo))
        return false;
    if(comparaABB(nodo->elemento.numero, elemento.numero) == 0)
        return true;
    if(comparaABB(nodo->elemento.numero, elemento.numero) == 1)
        return buscarRecursivo(nodo->izquierda, elemento);
    else
        if(comparaABB(nodo->elemento.numero, elemento.numero) == -1)
            return buscarRecursivo(nodo->derecha, elemento);
}

bool buscar(const struct ArbolBinarioBusqueda & arbol, const struct Elemento & elemento){
    return buscarRecursivo(arbol.arbolBinario.raiz, elemento);
}

struct NodoArbol * minimoArbol(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    return minimoArbol(nodo->izquierda);
}

struct NodoArbol * eliminarRecursivo(struct NodoArbol * nodo, const struct Elemento & elemento){
    if(esNodoVacio(nodo))
        return nodo;
    //buscamos el nodo a eliminar
    if(nodo->elemento.numero > elemento.numero)
        nodo->izquierda = eliminarRecursivo(nodo->izquierda, elemento);
    else
        if(nodo->elemento.numero < elemento.numero)
            nodo->derecha = eliminarRecursivo(nodo->derecha, elemento);
        else
            /*encontró el elemento*/
            if(esNodoVacio(nodo->izquierda)){
                struct NodoArbol * hijo = nodo->derecha;
                delete nodo;
                return hijo;
            }
            else
                if(esNodoVacio(nodo->derecha)){
                    struct NodoArbol * hijo = nodo->izquierda;
                    delete nodo;
                    return hijo;
                }
                else{
                    /* dos hijos*/
                    struct NodoArbol * minNodo = minimoArbol(nodo->derecha);
                    nodo->elemento = minNodo->elemento;
                    nodo->derecha = eliminarRecursivo(nodo->derecha, minNodo->elemento);
                }
                    
    return nodo;           
    
}

void eliminar(struct ArbolBinarioBusqueda & arbol, const struct Elemento & elemento){
    arbol.arbolBinario.raiz = eliminarRecursivo(arbol.arbolBinario.raiz, elemento);
}

