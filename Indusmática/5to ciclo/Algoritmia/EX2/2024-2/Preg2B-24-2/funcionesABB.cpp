/* 
 * File:   funcionesABB.cpp
 * Author: ANA RONCAL
 * 
 * Created on 13 de noviembre de 2024, 13:50
 */

#include <iostream>
#include <iomanip>
#include "ArbolBB.h"
using namespace std;
#include "funcionesAB.h"
#include "funcionesABB.h"
#include "Elemento.h"

void construir(struct ArbolBinarioBusqueda & arbol){
    construir(arbol.arbolBinario);
    arbol.longitud = 0;
}

void insertar(struct ArbolBinarioBusqueda & arbol, Elemento elemento){
    bool valido = insertarRecursivo(arbol.arbolBinario.raiz, elemento);
    if(valido)
        arbol.longitud++;
}

bool insertarRecursivo(struct NodoArbol *& raiz, Elemento elemento){
    if(esNodoVacio(raiz))
        plantarArbolBinario(raiz, nullptr, elemento, nullptr);
    else
        if(raiz->elemento.pos > elemento.pos)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            if(raiz->elemento.pos < elemento.pos)
                insertarRecursivo(raiz->derecha, elemento);
            else{
                cout << "El elemento " << elemento.pos << "Ya se encuentra en el árbol" << endl;
                return false;
            }
    return true;
}

void enOrden(const struct ArbolBinarioBusqueda & arbol){
    recorrerEnOrden(arbol.arbolBinario);
}

//bool buscar(const struct ArbolBinarioBusqueda & arbol, int dato){
//    return buscarRecursivo(arbol.arbolBinario.raiz, dato);
//}
//
//bool buscarRecursivo(struct NodoArbol * nodo, int dato){
//    if(esNodoVacio(nodo))
//        return false;
////    if(comparaABB(nodo->elemento, dato) == 0)
////        return true;
////    if(comparaABB(nodo->elemento, dato) == 1)
////        return buscarRecursivo(nodo->izquierda, dato);
////    else
////        if(comparaABB(nodo->elemento, dato) == -1)
////            return buscarRecursivo(nodo->derecha, dato);
////}
////
////int comparaABB(int elementoA, int elementoB){
////    if(elementoA == elementoB) return 0;
////    else if(elementoA < elementoB) return -1;
////    else if(elementoA > elementoB) return 1;
////}
//
//void eliminar(struct ArbolBinarioBusqueda & arbol, int dato){
//    arbol.arbolBinario.raiz = eliminarRecursivo(arbol.arbolBinario.raiz, dato);
//}
//
//struct NodoArbol * eliminarRecursivo(struct NodoArbol * nodo, int elemento){
//    if(esNodoVacio(nodo))
//        return nodo;
//    //buscamos el nodo a eliminar
//    if(nodo->elemento > elemento)
//        nodo->izquierda = eliminarRecursivo(nodo->izquierda, elemento);
//    else
//        if(nodo->elemento < elemento)
//            nodo->derecha = eliminarRecursivo(nodo->derecha, elemento);
//        else
//            /*encontró el elemento*/
//            if(esNodoVacio(nodo->izquierda)){
//                struct NodoArbol * hijo = nodo->derecha;
//                delete nodo;
//                return hijo;
//            }
//            else
//                if(esNodoVacio(nodo->derecha)){
//                    struct NodoArbol * hijo = nodo->izquierda;
//                    delete nodo;
//                    return hijo;
//                }
//                else{
//                    /* dos hijos*/
//                    struct NodoArbol * minNodo = minimoArbol(nodo->derecha);
//                    nodo->elemento = minNodo->elemento;
//                    nodo->derecha = eliminarRecursivo(nodo->derecha, minNodo->elemento);
//                }
//                    
//    return nodo;           
//    
//}
//
//struct NodoArbol * minimoArbol(struct NodoArbol * nodo){
//    if(esNodoVacio(nodo))
//        return nodo;
//    if(esNodoVacio(nodo->izquierda))
//        return nodo;
//    return minimoArbol(nodo->izquierda);
//}
//
//
//void eliminarPropio(struct ArbolBinarioBusqueda &arbol, int dato){
//    
//    arbol.arbolBinario.raiz = eliminarPropioRecursivo(arbol.arbolBinario.raiz, dato);
//    
//}
//
//NodoArbol *eliminarPropioRecursivo(NodoArbol *nodo, int dato){
//    
//    if(esNodoVacio(nodo)) return nodo;
//    
//    if(dato > nodo->derecha->elemento)
//        nodo->derecha = eliminarPropioRecursivo(nodo->derecha, dato);
//    else if(dato < nodo->izquierda->elemento)
//        nodo->izquierda = eliminarPropioRecursivo(nodo->izquierda, dato);
//    else if(dato == nodo->elemento){ //Lo encontramos
//        
//        if(esNodoVacio(nodo->izquierda)){ //Solo tenemos hijo derecho
//            //o ningún hijo
//            NodoArbol *hijo = nodo->derecha;
//            delete nodo;
//            return hijo;
//        }
//        else if(esNodoVacio(nodo->derecha)){ //Solo tenemos hijo izquierdo o
//            //ningún hijo
//            NodoArbol *hijo = nodo->izquierda;
//            delete nodo;
//            return hijo;            
//        }
//        
//        else{ //Tiene dos hijos
//            NodoArbol *maximoArbol = hallarMaximoArbol(nodo->izquierda);
//            nodo->elemento = maximoArbol->elemento;
//            nodo->izquierda = eliminarPropioRecursivo(nodo->izquierda, maximoArbol->elemento);
//        }
//        
//    }
//    
//    
//    return nodo;
//    
//}
//
//
//NodoArbol *hallarMaximoArbol(NodoArbol *nodo){
//    
//    if(esNodoVacio(nodo))return nodo;
//    
//    if(esNodoVacio(nodo->derecha))
//        return nodo;
//    
//    return hallarMaximoArbol(nodo->derecha);
//    
//}