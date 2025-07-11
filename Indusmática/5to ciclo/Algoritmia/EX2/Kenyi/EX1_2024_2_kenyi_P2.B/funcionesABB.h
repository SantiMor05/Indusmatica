
/* 
 * File:   funcionesAB.h
 * Author: anaro
 *
 * Created on 27 de octubre de 2024, 17:00
 */

#ifndef FUNCIONESABB_H
#define FUNCIONESABB_H

void construir(struct ArbolBinarioBusqueda & arbol);

void insertar(struct ArbolBinarioBusqueda & arbol, const struct Elemento & elemento);
void insertarRecursivo(struct NodoArbol *& raiz, const struct Elemento & elemento);
void enOrden(const struct ArbolBinarioBusqueda & arbol);
bool buscar(const struct ArbolBinarioBusqueda & arbol, const struct Elemento & elemento);

bool buscarRecursivo(struct NodoArbol * nodo, const struct Elemento & elemento);
int comparaABB(int elementoA, int elementoB);
void eliminar(struct ArbolBinarioBusqueda & arbol, const struct Elemento & elemento);
struct NodoArbol * eliminarRecursivo(struct NodoArbol * nodo, const struct Elemento & elemento);
struct NodoArbol * minimoArbol(struct NodoArbol * nodo);

#endif /* FUNCIONESABB_H */
