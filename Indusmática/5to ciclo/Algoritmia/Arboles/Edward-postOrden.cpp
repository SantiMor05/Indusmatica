#include <iostream>
#include "NodoArbol.h"
#include "PilaNodoArbol.h"
using namespace std;

void recorrerPostOrdenUnaPila(NodoArbol* raiz) {
    if (!raiz) return;

    PilaNodoArbol pila;
    construir(pila);

    NodoArbol* actual = raiz;
    NodoArbol* ultimoVisitado = nullptr;

    while (!esVacia(pila) || actual != nullptr) {
        if (actual != nullptr) {
            apilar(pila, actual);
            actual = actual->izquierda;
        } else {
            NodoArbol* nodoEnCima = cima(pila);

            if (nodoEnCima->derecha != nullptr && ultimoVisitado != nodoEnCima->derecha) {
                actual = nodoEnCima->derecha;
            } else {
                cout << nodoEnCima->elemento.numero << " ";
                ultimoVisitado = desapilar(pila);
            }
        }
    }

    destruir(pila);
    cout << endl;
}
