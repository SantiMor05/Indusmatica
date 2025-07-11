/* 
 * File:   funcionesABB.h
 * Author: anaro
 *
 * Created on 13 de noviembre de 2024, 13:50
 */

#ifndef FUNCIONESABB_H
#define FUNCIONESABB_H

void construir(struct ArbolBinarioBusqueda & arbol);

void insertar(struct ArbolBinarioBusqueda & arbol, int elemento);
void insertarRecursivo(struct NodoArbol *& raiz, int elemento);

void enOrden(const struct ArbolBinarioBusqueda & arbol);

bool buscar(const struct ArbolBinarioBusqueda & arbol, int dato);
bool buscarRecursivo(struct NodoArbol * nodo, int dato);
int comparaABB(int elementoA, int elementoB);


void eliminar(struct ArbolBinarioBusqueda & arbol, int dato);
struct NodoArbol * eliminarRecursivo(struct NodoArbol * nodo, int elemento);
struct NodoArbol * minimoArbol(struct NodoArbol * nodo);

void eliminarPropio(struct ArbolBinarioBusqueda &arbol, int dato);
NodoArbol *hallarMaximoArbol(NodoArbol *nodo);
NodoArbol *eliminarPropioRecursivo(NodoArbol *nodo, int dato);

#endif /* FUNCIONESABB_H */
