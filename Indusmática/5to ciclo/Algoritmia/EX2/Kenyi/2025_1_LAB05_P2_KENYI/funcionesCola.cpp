/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * 
 * Created on 5 de mayo de 2025, 10:55
 */

#include <iostream>
#include "Elemento.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "NodoArbol.h"

using namespace std;

/*constructor de Cola*/
void construir(struct Cola & cola){
    construir(cola.lista); //se inicializa el puntero cola
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

void encolar(struct Cola & cola, const struct Elemento  &elemento){
    cout <<"Encolando... " <<elemento.numero << endl;
    insertarAlFinal(cola.lista, elemento); // se utiliza el puntero cola
}

void encolar(struct Cola & cola, struct NodoArbol *&nodo){
    cout <<"Encolando... " <<nodo->elemento.numero<< endl;
    insertarAlFinal(cola.lista, nodo); // se utiliza el puntero cola
}

struct Elemento desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(11);
    }
    struct Elemento elemento = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return elemento;
}

NodoArbol * desencolar2(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(11);
    }
    struct NodoArbol *nodoA=cola.lista.cabeza->nodoA;
    eliminaCabeza(cola.lista);
    return nodoA;
}

void imprimir(const struct Cola & cola){
    imprime(cola.lista);
}