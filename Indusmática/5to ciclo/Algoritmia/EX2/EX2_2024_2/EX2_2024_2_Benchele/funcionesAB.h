
/* 
 * File:   funcionesAB.h
 * Author: anaro
 *
 * Created on 27 de octubre de 2024, 17:00
 */

#ifndef FUNCIONESAB_H
#define FUNCIONESAB_H

void construir(struct ArbolBinario & arbol);
bool esArbolVacio(const struct ArbolBinario & arbol);
bool esNodoVacio(struct NodoArbol * nodo);
struct NodoArbol* crearNuevoNodo(struct NodoArbol* izquierda, const struct Elemento& elemento, struct NodoArbol* derecha);
void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * izquierda,
        const struct Elemento & elemento, struct NodoArbol * derecha);
void plantarArbolBinario(struct ArbolBinario & arbol, 
        struct ArbolBinario & arbolIzquierda, const struct Elemento & elemento, 
        struct ArbolBinario & arbolDerecha);
void plantarArbolBinario(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, const struct Elemento & elemento, 
                    struct NodoArbol * derecha);
void recorrerPreOrden(const struct ArbolBinario & arbol); 
void recorrerPreOrdenRecursivo(struct NodoArbol * nodo);

void recorrerEnOrden(const struct ArbolBinario & arbol); 
void recorrerEnOrdenRecursivo(struct NodoArbol * nodo);

void recorrerPostOrden(const struct ArbolBinario & arbol); 
void recorrerPostOrdenRecursivo(struct NodoArbol * nodo);

int altura(const struct ArbolBinario & arbol);
int alturaRecursivo(struct NodoArbol * nodo);
int maximo(int a, int b);

int  numeroHojas(const struct ArbolBinario & arbol);
int numeroHojasRecursivo(struct NodoArbol * nodo);

int numeroNodos(const struct ArbolBinario & arbol);
int numeroNodosRecursivo(struct NodoArbol * nodo);

int esEquilibrado(const struct ArbolBinario & arbol);
int esEquilibradoRecursivo(struct NodoArbol * nodo);

void imprimir(const struct ArbolBinario & arbol);
void imprimirNodo(struct NodoArbol * raiz);

void destruirArbolBinario(struct ArbolBinario &);
void destruirRecursivo(struct NodoArbol *);


#endif /* FUNCIONESAB_H */
