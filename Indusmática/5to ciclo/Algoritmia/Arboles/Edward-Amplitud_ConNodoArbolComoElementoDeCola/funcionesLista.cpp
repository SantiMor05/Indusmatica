/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Elemento.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "NodoArbol.h"
#include "Lista.h"
using namespace std;


void insertarAlFinal(struct Lista & tad, NodoArbol* elemento) {

    //struct Nodo * ultimoNodo = obtenerUltimoNodo(lista);
    struct Nodo * ultimoNodo = tad.cola; /*obtiene el último nodo*/
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr) {/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
    } else {//La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
        tad.cola = nuevoNodo;
    }
    tad.longitud++;
}

struct Nodo * crearNodo(NodoArbol*elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}


void eliminaCabeza(struct Lista & tad) {
    struct Nodo * nodoAEliminar = tad.cabeza;
    if (nodoAEliminar != nullptr) {
        tad.cabeza = tad.cabeza->siguiente;
        if (tad.cabeza == nullptr) /*falta añadir para que coloque*/
            tad.cola = nullptr; /*cola en null*/
        delete nodoAEliminar;
        tad.longitud--;
    }
}